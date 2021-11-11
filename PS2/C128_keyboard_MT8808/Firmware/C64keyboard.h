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


#ifndef C64keyboard_h
#define C64keyboard_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#define C64_KEYMAP_SIZE 	   132 // Size of each array in the key maps



#define debug   true  //Set true for serial monitor of C64 keycodes and PS/2 keycodes



#define MT8808  true    // Set true if using MT8808 and false if using MT8812 ot MT8816



//PS2 communication pins
#define DATA_PIN				15 // Data pin for PS2 keyboard
#define IRQ_PIN					2  // Interrupt pin for PS2 keyboard

//MT88xx control pins
#define ANALOG_SW_DATA      9 // Sets selected cross switch on/off (Old 13)
#define ANALOG_SW_STROBE    8 // Strobe timing pulse
#define ANALOG_SW_RESET     10 // Reset all MT88XX cross switches to off (Old 2)
#define ANALOG_SW_AX0     7
#define ANALOG_SW_AX1     6
#define ANALOG_SW_AX2     5
#define ANALOG_SW_AY0     4
#define ANALOG_SW_AY1     3
#define ANALOG_SW_AY2     14
#define ANALOG_SW_AX3     A3 // Pin that controls AX3 (MT8812 & MT8816 only)

//C64 NMI setup
#define NMI_PIN           16
#define RESTORE_KEY       PS2_KEY_TAB // Tab acts as Restore key
//C128 40/80
#define C128_40_80_PIN    A0
#define C128_40_80_KEY    PS2_KEY_F12 // F12 is 40/80 toggle
//C128 CAPS
#define C128_CAPS_PIN     A1
#define C128_CAPS_KEY     PS2_KEY_F11 // F11 is CAPS (C128) toggle

//Scan code value to enable a key map. Default is key map 1.
#define KEY_MAP_1				PS2_KEY_F9  // (DEC 105) F9
#define KEY_MAP_2				PS2_KEY_F10 // (DEC 106) F10

//Key map value to ignore key press
#define IGNORE_KEYCODE			0xAA //(DEC 170) (Must be > 128)

// Key map value to reset the MT88xx chip
#define MT_RESET        PS2_KEY_PRTSCR  // PrintScreen/SystemRequest activates MT88XX reset

// Key map value for capslock
#define CAPSLOCK_KEY      PS2_KEY_CAPS // (DEC 3) CapsLock key

// C64 keyboard mapping
#include "keymapping.h"

class C64keyboard {
  public:

    C64keyboard();


    static void begin(const C64Keymap_t &map = C64Keymap_main);

};
#endif
