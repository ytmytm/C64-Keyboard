
typedef struct {
  uint8_t noshift_1[C64_KEYMAP_SIZE];
  uint8_t shift_1[C64_KEYMAP_SIZE];
  uint8_t noshift_2[C64_KEYMAP_SIZE];
  uint8_t shift_2[C64_KEYMAP_SIZE];
} C64Keymap_t;

/* Maps are positional in relation to keyboard ASCII codes.
Place C64 key byte (Chart is found in KEYBIN spreadsheet)
into the equivalent keyboard ASCII code code position.
For C64 keyboards normally ASCII code set 2.

Each map has a normal (without shift) and shifted (with shift) array.

In situations where there is a shift difference, add 64 to the C64 key byte. 
This is when a key is shifted on keyboard, but not shifted on the C64 or vise-versa.

Unused ASCII codes need to have the IGNORE_KEYCODE value in place.(Default 170)

*/

#define C64_KEY_DEL	0x00	// 0 DEL
#define C64_KEY_F1	0x01	// 1 F1
#define C64_KEY_HORZ_CSR	0x02	// 2 HORZ CSR
#define C64_KEY_F5	0x03	// 3 F5
#define C64_KEY_RETURN	0x04	// 4 RETURN
#define C64_KEY_F3	0x05	// 5 F3
#define C64_KEY_F7	0x06	// 6 F7
#define C64_KEY_VERT_CSR	0x07	// 7 VERT CSR
#define C64_KEY_9	0x08	// 8 9
#define C64_KEY_M	0x09	// 9 M
#define C64_KEY_J	0x0A	// 10 J
#define C64_KEY_O	0x0B	// 11 O
#define C64_KEY_I	0x0C	// 12 I
#define C64_KEY_K	0x0D	// 13 K
#define C64_KEY_ZERO	0x0E	// 14 0
#define C64_KEY_N	0x0F	// 15 N
#define C64_KEY_5	0x10	// 16 5
#define C64_KEY_C	0x11	// 17 C
#define C64_KEY_D	0x12	// 18 D
#define C64_KEY_T	0x13	// 19 T
#define C64_KEY_R	0x14	// 20 R
#define C64_KEY_F	0x15	// 21 F
#define C64_KEY_6	0x16	// 22 6
#define C64_KEY_X	0x17	// 23 X
#define C64_KEY_POUND	0x18	// 24 POUND
#define C64_KEY_RSHIFT	0x19	// 25 RSHIFT
#define C64_KEY_SEMICOLON	0x1A	// 26 ;
#define C64_KEY_ARR_UP	0x1B	// 27 ^
#define C64_KEY_STAR	0x1C	// 28 *
#define C64_KEY_EQUALS	0x1D	// 29 =
#define C64_KEY_HOME	0x1E	// 30 HOME
#define C64_KEY_SLASH	0x1F	// 31 /
#define C64_KEY_3	0x20	// 32 3
#define C64_KEY_Z	0x21	// 33 Z
#define C64_KEY_A	0x22	// 34 A
#define C64_KEY_E	0x23	// 35 E
#define C64_KEY_W	0x24	// 36 W
#define C64_KEY_S	0x25	// 37 S
#define C64_KEY_4	0x26	// 38 4
#define C64_KEY_LSHIFT	0x27	// 39 LSHIFT
#define C64_KEY_PLUS	0x28	// 40 +
#define C64_KEY_DOT	0x29	// 41 .
#define C64_KEY_L	0x2A	// 42 L
#define C64_KEY_AT	0x2B	// 43 @
#define C64_KEY_P	0x2C	// 44 P
#define C64_KEY_COLON	0x2D	// 45 :
#define C64_KEY_MINUS	0x2E	// 46 -
#define C64_KEY_COMMA	0x2F	// 47 ,
#define C64_KEY_7	0x30	// 48 7
#define C64_KEY_B	0x31	// 49 B
#define C64_KEY_G	0x32	// 50 G
#define C64_KEY_U	0x33	// 51 U
#define C64_KEY_Y	0x34	// 52 Y
#define C64_KEY_H	0x35	// 53 H
#define C64_KEY_8	0x36	// 54 8
#define C64_KEY_V	0x37	// 55 V
#define C64_KEY_1	0x38	// 56 1
#define C64_KEY_SPACE	0x39	// 57 SPACE
#define C64_KEY_CTRL	0x3A	// 58 CTRL
#define C64_KEY_Q	0x3B	// 59 Q
#define C64_KEY_ARR_LEFT	0x3C	// 60 <-
#define C64_KEY_CBM	0x3D	// 61 CBM
#define C64_KEY_2	0x3E	// 62 2
#define C64_KEY_RUN_STOP	0x3F	// 63 RUN/STOP

#define C64_MOD_SHIFT	0x40	// shift modifier (shift on without shift map, unshift on shifted map)

const PROGMEM C64Keymap_t C64Keymap_main = {
	// symbolic map 1 without shift
	{	 IGNORE_KEYCODE // 0x00 - dummy
		,IGNORE_KEYCODE	// PS2_KEY_NUM         0x01
		,IGNORE_KEYCODE	// PS2_KEY_SCROLL      0x02
		,IGNORE_KEYCODE	// PS2_KEY_CAPS        0x03
		,IGNORE_KEYCODE	// PS2_KEY_PRTSCR      0x04
		,IGNORE_KEYCODE	// PS2_KEY_PAUSE       0x05
		,C64_KEY_LSHIFT	// PS2_KEY_L_SHIFT     0x06
		,C64_KEY_RSHIFT	// PS2_KEY_R_SHIFT     0x07

		,C64_KEY_CTRL	// PS2_KEY_L_CTRL      0X08
		,C64_KEY_CTRL	// PS2_KEY_R_CTRL      0X09
		,C64_KEY_RUN_STOP	// PS2_KEY_L_ALT       0x0A
		,IGNORE_KEYCODE	// PS2_KEY_R_ALT       0x0B
		,C64_KEY_CBM	// PS2_KEY_L_GUI       0x0C // L-Windows
		,C64_KEY_CBM	// PS2_KEY_R_GUI       0x0D // R-Windows
		,IGNORE_KEYCODE	// PS2_KEY_MENU        0x0E
		,IGNORE_KEYCODE	// PS2_KEY_BREAK       0x0F // CTRL+PAUSE generated inside keyboard

		,IGNORE_KEYCODE	// PS2_KEY_SYSRQ       0x10	// ALT+PrtScr
		,C64_KEY_HOME	// PS2_KEY_HOME        0x11
		,C64_KEY_RUN_STOP	// PS2_KEY_END         0x12
		,IGNORE_KEYCODE	// PS2_KEY_PGUP        0x13
		,IGNORE_KEYCODE	// PS2_KEY_PGDN        0x14
		,C64_KEY_HORZ_CSR | C64_MOD_SHIFT		// PS2_KEY_L_ARROW     0x15
		,C64_KEY_HORZ_CSR	// PS2_KEY_R_ARROW     0x16
		,C64_KEY_VERT_CSR | C64_MOD_SHIFT		// PS2_KEY_UP_ARROW    0x17

		,C64_KEY_VERT_CSR	// PS2_KEY_DN_ARROW    0x18
		,C64_KEY_DEL | C64_MOD_SHIFT			// PS2_KEY_INSERT      0x19
		,C64_KEY_DEL	// PS2_KEY_DELETE      0x1A
		,C64_KEY_RUN_STOP	// PS2_KEY_ESC         0x1B	// run/stop
		,C64_KEY_DEL	// PS2_KEY_BS          0x1C
		,IGNORE_KEYCODE	// PS2_KEY_TAB         0x1D	// XXX control?
		,C64_KEY_RETURN	// PS2_KEY_ENTER       0x1E
		,C64_KEY_SPACE	// PS2_KEY_SPACE       0x1F

		,C64_KEY_ZERO	// PS2_KEY_KP0         0x20
		,C64_KEY_1		// PS2_KEY_KP1         0x21
		,C64_KEY_2		// PS2_KEY_KP2         0x22
		,C64_KEY_3		// PS2_KEY_KP3         0x23
		,C64_KEY_4		// PS2_KEY_KP4         0x24
		,C64_KEY_5		// PS2_KEY_KP5         0x25
		,C64_KEY_6		// PS2_KEY_KP6         0x26
		,C64_KEY_7		// PS2_KEY_KP7         0x27

		,C64_KEY_8		// PS2_KEY_KP8         0x28
		,C64_KEY_9		// PS2_KEY_KP9         0x29
		,C64_KEY_DOT	// PS2_KEY_KP_DOT      0x2A
		,C64_KEY_RETURN	// PS2_KEY_KP_ENTER    0x2B
		,C64_KEY_PLUS	// PS2_KEY_KP_PLUS     0x2C
		,C64_KEY_MINUS	// PS2_KEY_KP_MINUS    0x2D
		,C64_KEY_STAR	// PS2_KEY_KP_TIMES    0x2E
		,C64_KEY_SLASH	// PS2_KEY_KP_DIV      0x2F

		,C64_KEY_ZERO	// PS2_KEY_0           0X30
		,C64_KEY_1		// PS2_KEY_1           0X31
		,C64_KEY_2		// PS2_KEY_2           0X32
		,C64_KEY_3		// PS2_KEY_3           0X33
		,C64_KEY_4		// PS2_KEY_4           0X34
		,C64_KEY_5		// PS2_KEY_5           0X35
		,C64_KEY_6		// PS2_KEY_6           0X36
		,C64_KEY_7		// PS2_KEY_7           0X37

		,C64_KEY_8		// PS2_KEY_8           0X38
		,C64_KEY_9		// PS2_KEY_9           0X39
		,C64_KEY_7 | C64_MOD_SHIFT	// PS2_KEY_APOS        0X3A
		,C64_KEY_COMMA	// PS2_KEY_COMMA       0X3B
		,C64_KEY_MINUS	// PS2_KEY_MINUS       0X3C
		,C64_KEY_DOT	// PS2_KEY_DOT         0X3D
		,C64_KEY_SLASH	// PS2_KEY_DIV         0X3E
		,C64_KEY_EQUALS	// PS2_KEY_KP_EQUAL    0x3F /* Some Numeric keyboards have an '=' on right keypad */

		,C64_KEY_ARR_LEFT 	// PS2_KEY_SINGLE      0X40 /* Single quote or back quote */
		,C64_KEY_A		// PS2_KEY_A           0X41
		,C64_KEY_B		// PS2_KEY_B           0X42
		,C64_KEY_C		// PS2_KEY_C           0X43
		,C64_KEY_D		// PS2_KEY_D           0X44
		,C64_KEY_E		// PS2_KEY_E           0X45
		,C64_KEY_F		// PS2_KEY_F           0X46
		,C64_KEY_G		// PS2_KEY_G           0X47

		,C64_KEY_H		// PS2_KEY_H           0X48
		,C64_KEY_I		// PS2_KEY_I           0X49
		,C64_KEY_J		// PS2_KEY_J           0X4A
		,C64_KEY_K		// PS2_KEY_K           0X4B
		,C64_KEY_L		// PS2_KEY_L           0X4C
		,C64_KEY_M		// PS2_KEY_M           0X4D
		,C64_KEY_N		// PS2_KEY_N           0X4E
		,C64_KEY_O		// PS2_KEY_O           0X4F

		,C64_KEY_P		// PS2_KEY_P           0X50
		,C64_KEY_Q		// PS2_KEY_Q           0X51
		,C64_KEY_R		// PS2_KEY_R           0X52
		,C64_KEY_S		// PS2_KEY_S           0X53
		,C64_KEY_T		// PS2_KEY_T           0X54
		,C64_KEY_U		// PS2_KEY_U           0X55
		,C64_KEY_V		// PS2_KEY_V           0X56
		,C64_KEY_W		// PS2_KEY_W           0X57

		,C64_KEY_X		// PS2_KEY_X           0X58
		,C64_KEY_Y		// PS2_KEY_Y           0X59
		,C64_KEY_Z		// PS2_KEY_Z           0X5A
		,C64_KEY_SEMICOLON					// PS2_KEY_SEMI        0X5B
		,C64_KEY_POUND						// PS2_KEY_BACK        0X5C // backslash
		,C64_KEY_COLON | C64_MOD_SHIFT		// PS2_KEY_OPEN_SQ     0X5D	// [
		,C64_KEY_SEMICOLON | C64_MOD_SHIFT	// PS2_KEY_CLOSE_SQ    0X5E // ]
		,C64_KEY_EQUALS						// PS2_KEY_EQUAL       0X5F

		,C64_KEY_COMMA						// PS2_KEY_KP_COMMA    0x60	/* Some Numeric keypads have a comma key */
		,C64_KEY_F1							// PS2_KEY_F1          0X61
		,C64_KEY_F1 | C64_MOD_SHIFT			// PS2_KEY_F2          0X62
		,C64_KEY_F3							// PS2_KEY_F3          0X63
		,C64_KEY_F3 | C64_MOD_SHIFT			// PS2_KEY_F4          0X64
		,C64_KEY_F5							// PS2_KEY_F5          0X65
		,C64_KEY_F5 | C64_MOD_SHIFT			// PS2_KEY_F6          0X66
		,C64_KEY_F7							// PS2_KEY_F7          0X67

		,C64_KEY_F7 | C64_MOD_SHIFT			// PS2_KEY_F8          0X68
		,IGNORE_KEYCODE		// PS2_KEY_F9          0X69
		,IGNORE_KEYCODE		// PS2_KEY_F10         0X6A
		,IGNORE_KEYCODE		// PS2_KEY_F11         0X6B
		,IGNORE_KEYCODE		// PS2_KEY_F12         0X6C
		,IGNORE_KEYCODE		// PS2_KEY_F13         0X6D
		,IGNORE_KEYCODE		// PS2_KEY_F14         0X6E
		,IGNORE_KEYCODE		// PS2_KEY_F15         0X6F

		,IGNORE_KEYCODE		// PS2_KEY_F16         0X70
		,IGNORE_KEYCODE		// PS2_KEY_F17         0X71
		,IGNORE_KEYCODE		// PS2_KEY_F18         0X72
		,IGNORE_KEYCODE		// PS2_KEY_F19         0X73
		,IGNORE_KEYCODE		// PS2_KEY_F20         0X74
		,IGNORE_KEYCODE		// PS2_KEY_F21         0X75
		,IGNORE_KEYCODE		// PS2_KEY_F22         0X76
		,IGNORE_KEYCODE		// PS2_KEY_F23         0X77

		,IGNORE_KEYCODE		// PS2_KEY_F24         0X78
		,IGNORE_KEYCODE		// PS2_KEY_NEXT_TR     0X79
		,IGNORE_KEYCODE		// PS2_KEY_PREV_TR     0X7A
		,IGNORE_KEYCODE		// PS2_KEY_STOP        0X7B
		,IGNORE_KEYCODE		// PS2_KEY_PLAY        0X7C
		,IGNORE_KEYCODE		// PS2_KEY_MUTE        0X7D
		,IGNORE_KEYCODE		// PS2_KEY_VOL_UP      0X7E
		,C64_KEY_DEL		// PS2_KEY_VOL_DN      0X7F	// ??? why?

		,IGNORE_KEYCODE		// PS2_KEY_MEDIA       0X80
		,IGNORE_KEYCODE		// PS2_KEY_EMAIL       0X81
		,IGNORE_KEYCODE		// PS2_KEY_CALC        0X82
		,IGNORE_KEYCODE		// PS2_KEY_COMPUTER    0X83
	},
	// symbolic map 1 with shift
	{
		 IGNORE_KEYCODE // 0x00 - dummy
		,IGNORE_KEYCODE	// PS2_KEY_NUM         0x01
		,IGNORE_KEYCODE	// PS2_KEY_SCROLL      0x02
		,IGNORE_KEYCODE	// PS2_KEY_CAPS        0x03
		,IGNORE_KEYCODE	// PS2_KEY_PRTSCR      0x04
		,IGNORE_KEYCODE	// PS2_KEY_PAUSE       0x05
		,C64_KEY_LSHIFT	// PS2_KEY_L_SHIFT     0x06
		,C64_KEY_RSHIFT	// PS2_KEY_R_SHIFT     0x07

		,C64_KEY_CTRL	// PS2_KEY_L_CTRL      0X08
		,C64_KEY_CTRL	// PS2_KEY_R_CTRL      0X09
		,C64_KEY_RUN_STOP	// PS2_KEY_L_ALT       0x0A
		,IGNORE_KEYCODE	// PS2_KEY_R_ALT       0x0B
		,C64_KEY_CBM	// PS2_KEY_L_GUI       0x0C // L-Windows
		,C64_KEY_CBM	// PS2_KEY_R_GUI       0x0D // R-Windows
		,IGNORE_KEYCODE	// PS2_KEY_MENU        0x0E
		,IGNORE_KEYCODE	// PS2_KEY_BREAK       0x0F // CTRL+PAUSE generated inside keyboard

		,IGNORE_KEYCODE	// PS2_KEY_SYSRQ       0x10	// ALT+PrtScr
		,C64_KEY_HOME	// PS2_KEY_HOME        0x11
		,C64_KEY_RUN_STOP	// PS2_KEY_END         0x12	// XXX run/stop?
		,IGNORE_KEYCODE	// PS2_KEY_PGUP        0x13
		,IGNORE_KEYCODE	// PS2_KEY_PGDN        0x14
		,C64_KEY_HORZ_CSR | C64_MOD_SHIFT	// PS2_KEY_L_ARROW     0x15	// XXX shift+left; move larrow to tilde
		,C64_KEY_HORZ_CSR	// PS2_KEY_R_ARROW     0x16
		,C64_KEY_VERT_CSR | C64_MOD_SHIFT		// PS2_KEY_UP_ARROW    0x17	// XXX shift+down; move uparrow to ???

		,C64_KEY_VERT_CSR	// PS2_KEY_DN_ARROW    0x18
		,C64_KEY_DEL | C64_MOD_SHIFT		// PS2_KEY_INSERT      0x19	// XXX shift+del
		,C64_KEY_DEL	// PS2_KEY_DELETE      0x1A
		,C64_KEY_RUN_STOP	// PS2_KEY_ESC         0x1B
		,C64_KEY_DEL	// PS2_KEY_BS          0x1C
		,IGNORE_KEYCODE	// PS2_KEY_TAB         0x1D	// XXX control?
		,C64_KEY_RETURN	// PS2_KEY_ENTER       0x1E
		,C64_KEY_SPACE	// PS2_KEY_SPACE       0x1F

		,C64_KEY_ZERO	// PS2_KEY_KP0         0x20
		,C64_KEY_1		// PS2_KEY_KP1         0x21
		,C64_KEY_2		// PS2_KEY_KP2         0x22
		,C64_KEY_3		// PS2_KEY_KP3         0x23
		,C64_KEY_4		// PS2_KEY_KP4         0x24
		,C64_KEY_5		// PS2_KEY_KP5         0x25
		,C64_KEY_6		// PS2_KEY_KP6         0x26
		,C64_KEY_7		// PS2_KEY_KP7         0x27

		,C64_KEY_8		// PS2_KEY_KP8         0x28
		,C64_KEY_9		// PS2_KEY_KP9         0x29
		,C64_KEY_DOT	// PS2_KEY_KP_DOT      0x2A
		,C64_KEY_RETURN	// PS2_KEY_KP_ENTER    0x2B
		,C64_KEY_PLUS	// PS2_KEY_KP_PLUS     0x2C
		,C64_KEY_MINUS	// PS2_KEY_KP_MINUS    0x2D
		,C64_KEY_STAR	// PS2_KEY_KP_TIMES    0x2E
		,C64_KEY_SLASH	// PS2_KEY_KP_DIV      0x2F

		,C64_KEY_9		// PS2_KEY_0           0X30	// shift+0 == ) -> shift+9 == )
		,C64_KEY_1		// PS2_KEY_1           0X31
		,C64_KEY_AT | C64_MOD_SHIFT		// PS2_KEY_2           0X32	// shift+2 -> @-shift
		,C64_KEY_3		// PS2_KEY_3           0X33
		,C64_KEY_4		// PS2_KEY_4           0X34
		,C64_KEY_5		// PS2_KEY_5           0X35
		,C64_KEY_ARR_UP | C64_MOD_SHIFT		// PS2_KEY_6           0X36	// shift+6 -> ^-shift
		,C64_KEY_6		// PS2_KEY_7           0X37	// shift+7 == & -> shift+6 == &

		,C64_KEY_STAR | C64_MOD_SHIFT		// PS2_KEY_8           0X38	// shift+8 -> *-shift
		,C64_KEY_8		// PS2_KEY_9           0X39	// shift+9 == ( -> shift+8 == (
		,C64_KEY_2		// PS2_KEY_APOS        0X3A // sfhit+' == " -> shift+2 == "
		,C64_KEY_COMMA	// PS2_KEY_COMMA       0X3B
		,C64_KEY_MINUS	// PS2_KEY_MINUS       0X3C
		,C64_KEY_DOT	// PS2_KEY_DOT         0X3D
		,C64_KEY_SLASH	// PS2_KEY_DIV         0X3E
		,C64_KEY_EQUALS	// PS2_KEY_KP_EQUAL    0x3F /* Some Numeric keyboards have an '=' on right keypad */

		,C64_KEY_AT 	// PS2_KEY_SINGLE      0X40 /* Single quote or back quote */ XXX tilde? move LARROW here?
		,C64_KEY_A		// PS2_KEY_A           0X41
		,C64_KEY_B		// PS2_KEY_B           0X42
		,C64_KEY_C		// PS2_KEY_C           0X43
		,C64_KEY_D		// PS2_KEY_D           0X44
		,C64_KEY_E		// PS2_KEY_E           0X45
		,C64_KEY_F		// PS2_KEY_F           0X46
		,C64_KEY_G		// PS2_KEY_G           0X47

		,C64_KEY_H		// PS2_KEY_H           0X48
		,C64_KEY_I		// PS2_KEY_I           0X49
		,C64_KEY_J		// PS2_KEY_J           0X4A
		,C64_KEY_K		// PS2_KEY_K           0X4B
		,C64_KEY_L		// PS2_KEY_L           0X4C
		,C64_KEY_M		// PS2_KEY_M           0X4D
		,C64_KEY_N		// PS2_KEY_N           0X4E
		,C64_KEY_O		// PS2_KEY_O           0X4F

		,C64_KEY_P		// PS2_KEY_P           0X50
		,C64_KEY_Q		// PS2_KEY_Q           0X51
		,C64_KEY_R		// PS2_KEY_R           0X52
		,C64_KEY_S		// PS2_KEY_S           0X53
		,C64_KEY_T		// PS2_KEY_T           0X54
		,C64_KEY_U		// PS2_KEY_U           0X55
		,C64_KEY_V		// PS2_KEY_V           0X56
		,C64_KEY_W		// PS2_KEY_W           0X57

		,C64_KEY_X		// PS2_KEY_X           0X58
		,C64_KEY_Y		// PS2_KEY_Y           0X59
		,C64_KEY_Z		// PS2_KEY_Z           0X5A
		,C64_KEY_COLON | C64_MOD_SHIFT		// PS2_KEY_SEMI        0X5B // shift+; -> : == ;-shift
		,C64_KEY_POUND						// PS2_KEY_BACK        0X5C
		,C64_KEY_COLON | C64_MOD_SHIFT		// PS2_KEY_OPEN_SQ     0X5D	// XXX ???
		,C64_KEY_SEMICOLON | C64_MOD_SHIFT	// PS2_KEY_CLOSE_SQ    0X5E // XXX ???
		,C64_KEY_PLUS | C64_MOD_SHIFT		// PS2_KEY_EQUAL       0X5F	// shift+= -> +-shift

		,C64_KEY_COMMA						// PS2_KEY_KP_COMMA    0x60	/* Some Numeric keypads have a comma key */
		,C64_KEY_F1							// PS2_KEY_F1          0X61
		,IGNORE_KEYCODE						// PS2_KEY_F2          0X62
		,C64_KEY_F3							// PS2_KEY_F3          0X63
		,IGNORE_KEYCODE						// PS2_KEY_F4          0X64
		,C64_KEY_F5							// PS2_KEY_F5          0X65
		,IGNORE_KEYCODE						// PS2_KEY_F6          0X66
		,C64_KEY_F7							// PS2_KEY_F7          0X67

		,IGNORE_KEYCODE						// PS2_KEY_F8          0X68
		,IGNORE_KEYCODE		// PS2_KEY_F9          0X69
		,IGNORE_KEYCODE		// PS2_KEY_F10         0X6A
		,IGNORE_KEYCODE		// PS2_KEY_F11         0X6B
		,IGNORE_KEYCODE		// PS2_KEY_F12         0X6C
		,IGNORE_KEYCODE		// PS2_KEY_F13         0X6D
		,IGNORE_KEYCODE		// PS2_KEY_F14         0X6E
		,IGNORE_KEYCODE		// PS2_KEY_F15         0X6F

		,IGNORE_KEYCODE		// PS2_KEY_F16         0X70
		,IGNORE_KEYCODE		// PS2_KEY_F17         0X71
		,IGNORE_KEYCODE		// PS2_KEY_F18         0X72
		,IGNORE_KEYCODE		// PS2_KEY_F19         0X73
		,IGNORE_KEYCODE		// PS2_KEY_F20         0X74
		,IGNORE_KEYCODE		// PS2_KEY_F21         0X75
		,IGNORE_KEYCODE		// PS2_KEY_F22         0X76
		,IGNORE_KEYCODE		// PS2_KEY_F23         0X77

		,IGNORE_KEYCODE		// PS2_KEY_F24         0X78
		,IGNORE_KEYCODE		// PS2_KEY_NEXT_TR     0X79
		,IGNORE_KEYCODE		// PS2_KEY_PREV_TR     0X7A
		,IGNORE_KEYCODE		// PS2_KEY_STOP        0X7B
		,IGNORE_KEYCODE		// PS2_KEY_PLAY        0X7C
		,IGNORE_KEYCODE		// PS2_KEY_MUTE        0X7D
		,IGNORE_KEYCODE		// PS2_KEY_VOL_UP      0X7E
		,C64_KEY_DEL		// PS2_KEY_VOL_DN      0X7F	// ??? why?

		,IGNORE_KEYCODE		// PS2_KEY_MEDIA       0X80
		,IGNORE_KEYCODE		// PS2_KEY_EMAIL       0X81
		,IGNORE_KEYCODE		// PS2_KEY_CALC        0X82
		,IGNORE_KEYCODE		// PS2_KEY_COMPUTER    0X83
	},
  
 // map 2 without shift
     {170,170,170,170,170,170, 39, 25,// ASCII Codes 0x00 - 0x07
     58,170, 63,170, 61,170,170,170,// ASCII Codes 0x08 - 0x0F
    170, 30,170,170,170,170,  2, 27,// ASCII Codes 0x10 - 0x17
      7,170, 00,170, 60,170,  4, 57,// ASCII Codes 0x18 - 0x1F
    170,170,170,170,170,170,170,170,// ASCII Codes 0x20 - 0x27
    170,170,170,170, 40, 46, 28,170,// ASCII Codes 0x28 - 0x2F
     14, 56, 62, 32, 38, 16, 22, 48,// ASCII Codes 0x30 - 0x37
     54,  8, 45, 47, 46, 41, 31,170,// ASCII Codes 0x38 - 0x3F
     43, 34, 49, 17, 18, 35, 21, 50,// ASCII Codes 0x40 - 0x47
     53, 12, 10, 13, 42,  9, 15, 11,// ASCII Codes 0x48 - 0x4F
     44, 59, 20, 37, 19, 51, 55, 36,// ASCII Codes 0x50 - 0x57
     23, 52, 33, 26, 24,109, 90, 29,// ASCII Codes 0x58 - 0x5F
    170, 1,  65,  5, 69,  3, 67,  6,// ASCII Codes 0x60 - 0x67
     70,170,170,170,170,170,170,170,// ASCII Codes 0x68 - 0x6F
    170,170,170,170,170,170,170,170,// ASCII Codes 0x70 - 0x77
    170,170,170,170,170,170,170,  0,// ASCII Codes 0x78 - 0x7F
    170,170,170,170},// ASCII Codes 0x80 - 0x83
  // map 2 with shift
  {170,170,170,170,170,170, 39, 25,// ASCII Codes 0x00 - 0x07
     58,170, 63,170, 61,170,170,170,// ASCII Codes 0x08 - 0x0F
    170, 30,170,170,170,170,  2, 27,// ASCII Codes 0x10 - 0x17
      7,170,  0,170, 60,170,  4, 57,// ASCII Codes 0x18 - 0x1F
    170,170,170,170,170,170,170,170,// ASCII Codes 0x20 - 0x27
    170,170,170,170, 40, 46, 28,170,// ASCII Codes 0x28 - 0x2F
     14, 56, 62, 32, 38, 16, 22, 48,// ASCII Codes 0x30 - 0x37
     54,  8, 45, 47, 46, 41, 31,170,// ASCII Codes 0x38 - 0x3F
     43, 34, 49, 17, 18, 35, 21, 50,// ASCII Codes 0x40 - 0x47
     53, 12, 10, 13, 42,  9, 15, 11,// ASCII Codes 0x48 - 0x4F
     44, 59, 20, 37, 19, 51, 55, 36,// ASCII Codes 0x50 - 0x57
     23, 52, 33, 26, 24,170,170, 29,// ASCII Codes 0x58 - 0x5F
    170,  1,170,  5,170,  3,170,  6,// ASCII Codes 0x60 - 0x67
    170,170,170,170,170,170,170,170,// ASCII Codes 0x68 - 0x6F
    170,170,170,170,170,170,170,170,// ASCII Codes 0x70 - 0x77
    170,170,170,170,170,170,170,  0,// ASCII Codes 0x78 - 0x7F
    170,170,170,170},// ASCII Codes 0x80 - 0x83

    
  
};
