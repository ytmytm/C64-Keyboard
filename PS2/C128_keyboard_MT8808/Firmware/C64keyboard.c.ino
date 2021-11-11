// IDE settings: board Arduino Micro

/*
  C64keyboard.h - Commodore Keyboard library

  Copyright (c) 2019 Hartland PC LLC
  Written by Robert VanHazinga


  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/
#include "C64keyboard.h"


const uint8_t ANALOG_SW_ARRAY[] = { ANALOG_SW_AY2, ANALOG_SW_AY1, ANALOG_SW_AY0, ANALOG_SW_AX2, ANALOG_SW_AX1, ANALOG_SW_AX0 };


void resetMT88(void) {
  digitalWrite(ANALOG_SW_DATA , LOW);
  digitalWrite(ANALOG_SW_RESET, HIGH);
  digitalWrite(ANALOG_SW_STROBE, HIGH);
  digitalWrite(ANALOG_SW_RESET, LOW);
  digitalWrite(ANALOG_SW_STROBE, LOW);
  digitalWrite(ANALOG_SW_DATA , HIGH);
  keyboard.setLock (0);
  capslock = false;
  lshift = false;
  rshift = false;
  c128_40_80 = false;
  c128_capslock = false;
  currkeymap = 1;
}


void setswitch(uint8_t c) {
  bool state;

  if (c == IGNORE_KEYCODE)
	return;

  // Fix logic table hole in MT8812/16
  // Convert x12 & x13 to x6 & x7. AX3 line control
  if ( !MT8808 &&( (c > 55 && c < 64) || (c > 23 && c < 32 ))) {
    c -= 24;
    digitalWrite(ANALOG_SW_AX3, HIGH);
  }

  if (c < 64) {
    for (uint8_t i = 0; i<(sizeof(ANALOG_SW_ARRAY)/sizeof(ANALOG_SW_ARRAY[0])); i++) {
      state =  bitRead(c, i);
      digitalWrite(ANALOG_SW_ARRAY[i], state);
    }
    digitalWrite( ANALOG_SW_STROBE, HIGH);
    digitalWrite( ANALOG_SW_STROBE, LOW);
  }
  if (!MT8808){
    digitalWrite(ANALOG_SW_AX3, LOW);
  }
}


void debugkey (uint8_t c, uint8_t flags, uint8_t kc) {
    Serial.print ("C64 Keycode: ");
    Serial.print (c);
    Serial.print ("  (ASCII Code: ");
    Serial.print (kc);
    Serial.print (" Hex: ");
    Serial.print (kc, HEX);
    Serial.print (")  Flags: ");
    for (int8_t i = 7; i >= 0; i--) {
        bool b = bitRead(flags, i);
        Serial.print(b);
    }
    Serial.println();
}


void c64key(uint16_t k) {
   flags = k >> 8;
   uint8_t kc= k & 0xFF;
   uint8_t c = 0;

  if (currkeymap == 2) {
    if (bitRead(flags, 6)) {
      c = pgm_read_byte(keymap->shift_2 + kc);
    }
    else {
      c = pgm_read_byte(keymap->noshift_2 + kc);
    }
  }

  if (currkeymap == 1) {
    if (bitRead(flags, 6)) {
      c = pgm_read_byte(keymap->shift_1 + kc);
    }
    else {
      c = pgm_read_byte(keymap->noshift_1 + kc);
    }
  }
//  debug output
  if (debug){
    debugkey(c,flags,kc);
  }

// Ignore extended codes 
  if (kc == PS2_KEY_ACK){
    c=IGNORE_KEYCODE;
  }

// MT reset function    
  if (kc == MT_RESET) {
    resetMT88();  
    c=IGNORE_KEYCODE;
  }

// Restore key function   
  if (kc == RESTORE_KEY) {
    if (bitRead (flags,7)) {
       pinMode (NMI_PIN,INPUT);
    } else {
       pinMode (NMI_PIN,OUTPUT);
       digitalWrite (NMI_PIN,LOW);
    }
    c = IGNORE_KEYCODE;
  }

// C128 40/80 key
  if (kc == C128_40_80_KEY && !bitRead(flags,7)) { // only on keypress
    c128_40_80 = !c128_40_80;
    if (!c128_40_80) {
       pinMode (C128_40_80_PIN,INPUT);
    } else {
       pinMode (C128_40_80_PIN,OUTPUT);
       digitalWrite (C128_40_80_PIN,LOW);
    }
    c = IGNORE_KEYCODE;
  }

// C128 CAPS key
  if (kc == C128_CAPS_KEY && !bitRead(flags,7)) { // only on keypress
    c128_capslock = !c128_capslock;
    if (!c128_capslock) {
       pinMode (C128_CAPS_PIN,INPUT);
    } else {
       pinMode (C128_CAPS_PIN,OUTPUT);
       digitalWrite (C128_CAPS_PIN,LOW);
    }
    c = IGNORE_KEYCODE;
  }

// Capslock function 
  if (kc == CAPSLOCK_KEY) {
    capslock = !capslock;
    digitalWrite (ANALOG_SW_DATA, capslock);
    setswitch(C64_KEY_LSHIFT);
    c = IGNORE_KEYCODE;
  }

// Keymap Handling
  if (kc == KEY_MAP_1 && !bitRead(flags,7)) {
    currkeymap = 1;
    keyboard.setLock (keyboard.getLock() & (!PS2_LOCK_SCROLL));
    c = IGNORE_KEYCODE;
  }

  if (kc == KEY_MAP_2 && !bitRead(flags,7)) {
    currkeymap = 2;
    keyboard.setLock (keyboard.getLock() | PS2_LOCK_SCROLL);
    c = IGNORE_KEYCODE;
  }

// Jump to end if key code is an ignored key
  if (c != IGNORE_KEYCODE) {
    // Differential shift conversion during key press
   if (c >= C64_MOD_SHIFT) {
      c -= C64_MOD_SHIFT;
      if (rshift || lshift) {
        digitalWrite (ANALOG_SW_DATA, LOW);
        setswitch(C64_KEY_RSHIFT);
        digitalWrite (ANALOG_SW_DATA, LOW);
        setswitch(C64_KEY_LSHIFT);
      } else {
        digitalWrite (ANALOG_SW_DATA, HIGH);
        setswitch(C64_KEY_LSHIFT);
      }
      // Set cross switch key
      digitalWrite(ANALOG_SW_DATA, HIGH);
      setswitch(c);
      if bitRead (flags,7) {
        // Restore shift state to match keystate
        digitalWrite (ANALOG_SW_DATA, lshift);
        setswitch(C64_KEY_LSHIFT);
        digitalWrite (ANALOG_SW_DATA, rshift);
        setswitch(C64_KEY_RSHIFT);
        digitalWrite(ANALOG_SW_DATA, HIGH);
     }
   }
// Shift key handling
    if bitRead (flags,6) {
      if (c==C64_KEY_RSHIFT) {rshift = true;}
      if (c==C64_KEY_LSHIFT) {lshift = true;}
    }

    if bitRead (flags,7) {
      digitalWrite(ANALOG_SW_DATA , LOW);
      if (c==C64_KEY_RSHIFT) {rshift = false;}
      if (c==C64_KEY_LSHIFT) {lshift = false;}
    }

// Process normal keypress
    setswitch(c);
 }

// Reset switch state pin to default high state (Key press).
  digitalWrite(ANALOG_SW_DATA , HIGH);
}


void C64keyboard::begin(const C64Keymap_t &map) {

  keymap = &map;

  // initialize the pins
  for (uint8_t i = 0; i<(sizeof(ANALOG_SW_ARRAY)/sizeof(ANALOG_SW_ARRAY[0])); i++) {
    pinMode(ANALOG_SW_ARRAY[i], OUTPUT);
  }

  if (!MT8808){pinMode( ANALOG_SW_AX3, OUTPUT);}  // ANALOG_SW_AX3 (AX3) is separate as it is used only for conversion of X12/X13 into X6/X7
  pinMode(ANALOG_SW_STROBE, OUTPUT);  // MT88XX strobe
  pinMode(ANALOG_SW_DATA, OUTPUT);   // MT88XX data
  pinMode(ANALOG_SW_RESET, OUTPUT); // MT88XX reset
  pinMode(ANALOG_SW_DATA, OUTPUT);  //MT88XX data
  pinMode(NMI_PIN, INPUT); // C64 NMI
  pinMode(C128_40_80_PIN, INPUT); // C128 40/80
  pinMode(C128_CAPS_PIN, INPUT); // C128 CAPS LOCK

  resetMT88();
}


C64keyboard::C64keyboard() {
  // nothing to do here, begin() does it all
}
