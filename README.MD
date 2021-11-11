
# C128 version

I have forked this version from https://github.com/Hartland/C64-Keyboard for two reasons:

- design PCB to connect PS/2 keyboard with MT8808 and Arduino Micro Pro solution to C128D
- provide symbolic, rather than positional, mapping for the keys

Have fun!

-- Maciej 'YTM/Elysium' Witkowiak

## Project cloning

This project has external submodule with Arduino Micro Pro symbol and footprint.

Clone it with all submodules using:

```sh
git clone --recurse-submodules https://github.com/ytmytm/C64-Keyboard.git
```

## PCB and schematic

Use KiCad to open the project in PS2/C128_keyboard_MT8808/PCB folder.

Ready for use Gerber files for circuit board v1.0 are in PS2/C128_keyboard_MT8808/PCB/gerber folder.

## Firmware

Use Arduino IDE to compile and flash the code from PS2/C128_keyboard_MT8808/Firmware folder.

## C128 version circuit assembly

Parts:

* 26-wire flat ribbon cable
* 26-pin ribbon cable connectors (male for PCB, female for crimping on the cable)
* DE25 male crimp connector for ribbon cable
* MT8808
* Arduino Micro Pro
* (optional) PS/2 socket
* (optional) 28-pin and 24-pin sockets

Assembly:

* align red (first) wire with triangular mark on the female connector and crimp it
* separate 26th wire and remove it from the cable, cut it off as close as possible to the already crimped connector
* now the cable can be aligned and crimped in the DE25 connector; aligh red (first) wire with the mark on connector, confirm that it goes to pin 1
* solder parts on the PCB, start with lowest profile components first (sockets, MT8808, male 26-pin connector)

You can skip over transistor and resistor and connect pin 3 from the cable directly to Arduino pin 16 using a jumper 

Add two wire connections that I forgot to put on PCB in version 1:

* pin 24 to A0 (40/80 key)
* pin 25 to A1 (CAPS key)

## Keyboard mapping

| C64/128 key | PS/2 key |
|-------------|----------|
| C=		  | Windows  |
| RUN/STOP    | ESC, END, left ALT |
| RESTORE     | TAB |
| ARROW LEFT  | ` (tilde) |
| ARROW UP    | ^ (SHIFT+6) |
| @           | @ (SHIFT+2) |
| DEL         | DEL, BACKSPACE |
| CLR/HOME    | HOME |
| *           | * (SHIFT+8) |
| POUND       | \ |

## Function keys

| PS/2 key | action |
|----------|--------|
| F9       | symbolic keymap (default) |
| F10      | positional keymap |
| F11      | C128 CAPS toggle |
| F12      | C128 40/80 toggle |
| CAPS LOCK | SHIFT LOCK toggle |
| SysRq    | reset MT8808 |

## TODOs

To do in version 2:

* connect C128 40/80 line (pin 24) to A0
* connect C128 CAPS line (pin 25) to A1
* connect RESTORE line (pin 3) directly to pin 16, no need for transistor and resistor there
* correct parts alignment so that mounting holes are not obscured
* use PS/2 socket footprint
* +5V jumper between Arduino VCC and +5V net (serial port, PS/2 port and DE25 pin 4)

To do for MT8812/MT8816 version:

* handle extra C128 keys using DE25 pins 21/22/23 (K0/K1/K2)

To do for SEEDUINO version:

* there is not enough pins, I/O expander or latch is needed

# Original documentation follows

## C64 PS2/USB Keyboard




This project is designed to allow a PS2/USB keyboard to be used with a Commodore 64 in place of the original Commodore keyboard.


Dependencies
------------
* PS2KeyAdvanced Arduino library for use with PS2 keyboard. Install through the IDE library manager

* A slightly modified USBHOST Arduino library is included for use with USB keyboard. This will need to be placed in the Arduino library directory.

* The SEEED will need its board driver installed into the Arduino IDE. See manufacturers instructions.


Hardware
--------
* Arduino Uno, Nano, or SEEED XIAO. SEEED required for USB keyboard

* MT8808, MT8812 or MT8816 Analog Switch Array

* 20 pin female header or male header with cable (PATA cable will work)

* Arduino shield PCB. 
	- Any universal PCB that will line up correctly

* PS2 keyboard 
	- matching socket or cut/strip and directly wire
	
* USB keyboard 
	- Requires SEEED and in most cases, USB Type C to USB A or Micro Type B cable/adapter
	- Keyboards that connect through internal USB hubs are not supported.This is a limitation of the USBHost library
	- Restore (NMI) key requires a NPN transistor (2n3904 suggested) and resistor (10K)

DUE - DEPRECIATED
---------

*  **DUE is included for archive only and will not be updated. The SEEED XIAO is recommended for USB **


 
Documents
---------
* MT88XX.xml
	- Basic wiring charts. Separate tabs for MT8808 and MT8812/MT8816. Wiring charts are also on the schematics

* MT8808.pdf and MT8812-16.pdf MT8808 is separate due to a different IC pinout to MT8812-16
	- PDF versions for the wiring charts
	
* KEYBIN.xml
	- MT88XX AY/AX. These are the hard wired Commodore keyboard header position values used in keyboard mapping.
	- The position values are placed on the keymap where the PS2/USB keyboard value matches the Commodore key desired.
	- The AX2-1-0 AY2-1-0 and logic hole hole columns are for reference and not needed to make keymaps. 
	
* DEFAULTKEY
	- Included key map document
	
* Schematic_MT8812-16.pdf and Schematic_MT8808.PDF.These are located in the PS2/doc and USB/doc folders.
	-Schematic diagrams. MT8808 is separate due to a different IC pinout to MT8812-16



Usage
-----

* PS2 keyboards use the PS2KeyAdvanced library.
	-Use Manage Library to search for and install PS2KeyAdvanced.

* USB Keyboards use the included modified USBHOST.

* Using the Arduino IDE upload the sketch: *C64_keyboard.ino* into your Arduino.

* **SYSTEM OPTIONS ARE LOCATED IN THE *C64KEYBOARD.H* HEADER FILE. THE MT8808 DEFINITION IS VERY IMPORTANT. SET TO TRUE IF USING A MT8808 OR FLASE IF USING MT8812-16.**


!!!POWER REQUIREMENTS!!!!
-------------------------

* The Arduino UNO, Nano, and SEEED can be powered from the C64 keyboard header Pin 4

* **The Arduino DUE CANNOT BE POWERED FROM PIN 4!! Use the + side of C10 (+10V) connected to the DUE barrel power connector instead.**


TODO
----
* Create schematic diagrams for SEEED build. Wiring diagrams are included with 0.920

* Create spreadsheet/program to automatically create key maps

* Publish pre-compiled binary files
 


Version 0.920
-------------
* Add SEEED XIAO board for USB keyboards

* Document DUE is for archive only

Version 0.911
-------------
* USB IDE library requirement removed

Version 0.91
------------
* USB module published
 


Version 0.9
------------
* Code rewrite using PS2KeyAdvanced library

* Several bugs have been fixed

* Speed and reliability have been greatly improved

* Up to 2 key maps can be stored and hot swapped with assigned keys (Default F9-F10)


	

