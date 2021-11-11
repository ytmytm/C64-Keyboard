/*
  C64keyboard - Commodore Keyboard library

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

#include <PS2KeyAdvanced.h>
#include "C64keyboard.h"


PS2KeyAdvanced keyboard;
C64keyboard ckey;
static volatile uint8_t  currkeymap = 1, flags ;
static const C64Keymap_t *keymap = NULL;
static volatile bool lshift=false, rshift=false, capslock=false, c128_40_80=false, c128_capslock=false ;


void setup() {
  // Configure the keyboard library
  keyboard.begin( DATA_PIN, IRQ_PIN );
  // setup I/O pins
  ckey.begin();
  // setup delay for USB
  delay(5000);
  if (debug) {
    Serial.begin(115200);
    keyboard.echo( );              // ping keyboard to see if it's there
    delay( 6 );
    uint16_t c;
    c = keyboard.read( );
    if( (c & 0xFF) == PS2_KEY_ECHO || (c & 0xFF) == PS2_KEY_BAT ) {
      Serial.println( "Keyboard OK.." );    // Response was Echo or power up
    } else {
      if( ( c & 0xFF ) == 0 ) {
        Serial.println( "Keyboard Not Found" );
      } else {
        Serial.print( "Invalid Code received of " );
        Serial.println( c, HEX );
      }
    }
    Serial.println("C64 keyboard started");
  }
  keyboard.setNoRepeat (1);
  keyboard.setNoBreak (0);
  keyboard.setLock (PS2_LOCK_NUM);
}


void loop() {
  if (keyboard.available()) {
    c64key(keyboard.read());
  }
}
