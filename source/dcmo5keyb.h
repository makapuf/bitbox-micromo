//////////////////////////////////////////////////////////////////////////////
// DCMO5KEYB.H - mo5 keyboard definition
// Author   : Daniel Coulom - danielcoulom@gmail.com
// Web site : http://dcmo5.free.fr
// Created  : November 2007
//
// This file is part of DCMO5 v11.
// 
// DCMO5 v11 is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// DCMO5 v11 is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with DCMO5 v11.  If not, see <http://www.gnu.org/licenses/>.
//
//////////////////////////////////////////////////////////////////////////////
 
button mo5key[MO5KEY_MAX] = {
{"N",        222, 114,  24, 24,  0}, //0x00 
{"EFF",      418, 114,  24, 24,  1}, //0x01 
{"J",        234,  86,  24, 24,  2}, //0x02 
{"H",        206,  86,  24, 24,  3}, //0x03 
{"U",        222,  58,  24, 24,  4}, //0x04 
{"Y",        194,  58,  24, 24,  5}, //0x05 
{"7 '",      206,  30,  24, 24,  6}, //0x06 
{"6 &",      178,  30,  24, 24,  7}, //0x07 
{" , <",     250, 114,  24, 24,  8}, //0x08 
{"INS",      390, 114,  24, 24,  9}, //0x09 
{"K",        262,  86,  24, 24, 10}, //0x0a 
{"G",        178,  86,  24, 24, 11}, //0x0b 
{"I",        250,  58,  24, 24, 12}, //0x0c 
{"T",        166,  58,  24, 24, 13}, //0x0d 
{"8 (",      234,  30,  24, 24, 14}, //0x0e 
{"5 %",      150,  30,  24, 24, 15}, //0x0f 
{" . >",     278, 114,  24, 24, 16}, //0x10 
{"[retour]",  38,  86,  24, 24, 17}, //0x11 
{"L",        290,  86,  24, 24, 18}, //0x12  
{"F",        150,  86,  24, 24, 19}, //0x13 
{"O",        278,  58,  24, 24, 20}, //0x14 
{"R",        138,  58,  24, 24, 21}, //0x15 
{"9 )",      262,  30,  24, 24, 22}, //0x16 
{"4 $",      122,  30,  24, 24, 23}, //0x17 
{"@ ^",      306, 114,  24, 24, 24}, //0x18 
{"[droite]", 418,  58,  24, 24, 25}, //0x19 
{"M",        318,  86,  24, 24, 26}, //0x1a 
{"D",        122,  86,  24, 24, 27}, //0x1b 
{"P",        306,  58,  24, 24, 28}, //0x1c 
{"E",        110,  58,  24, 24, 29}, //0x1d 
{"0 `",      290,  30,  24, 24, 30}, //0x1e 
{"3 #",       94,  30,  24, 24, 31}, //0x1f 
{"ESPACE",   150, 142, 108, 24, 32}, //0x20 
{"[bas]",    402,  86,  24, 24, 33}, //0x21 
{"B",        194, 114,  24, 24, 34}, //0x22 
{"S",         94,  86,  24, 24, 35}, //0x23 
{" / ?",     334,  58,  24, 24, 36}, //0x24 
{"Z",         82,  58,  24, 24, 37}, //0x25 
{" - =",     318,  30,  24, 24, 38}, //0x26 
{"2 \"",      66,  30,  24, 24, 38}, //0x27 
{"X",        110, 114,  24, 24, 40}, //0x28 
{"[gauche]", 390,  58,  24, 24, 41}, //0x29 
{"V",        166, 114,  24, 24, 42}, //0x2a 
{"Q",         66,  86,  24, 24, 43}, //0x2b 
{" * :",     362,  58,  24, 24, 44}, //0x2c 
{"A",         54,  58,  24, 24, 45}, //0x2d  
{" + ;",     346,  30,  24, 24, 46}, //0x2e 
{"1 !",       38,  30,  24, 24, 47}, //0x2f 
{"W",         82, 114,  24, 24, 48}, //0x30 
{"[haut]",   402,  30,  24, 24, 49}, //0x31 
{"C",        138, 114,  24, 24, 50}, //0x32 
{"RAZ",       10,  86,  24, 24, 51}, //0x33 
{"ENT",      346,  86,  40, 24, 52}, //0x34 
{"CNT",       10,  58,  24, 24, 53}, //0x35 
{"ACC",      374,  30,  24, 24, 54}, //0x36 
{"STP",       10,  30,  24, 24, 55}, //0x37 
{"SHIFT",     10, 114,  52, 24, 56}, //0x38 
{"BASIC",    334, 114,  52, 24, 57}  //0x39 
};
 
button joykey[JOYKEY_MAX] = {
{"[0] haut",   135,  30, 0, 0, 58}, //0x00 
{"[0] bas",    135,  80, 0, 0, 61}, //0x01 
{"[0] gauche", 110,  55, 0, 0, 59}, //0x02 
{"[0] droite", 160,  55, 0, 0, 60}, //0x03 
{"[1] haut",   293,  30, 0, 0, 58}, //0x04 
{"[1] bas",    293,  80, 0, 0, 61}, //0x05 
{"[1] gauche", 268,  55, 0, 0, 59}, //0x06 
{"[1] droite", 318,  55, 0, 0, 60}, //0x07 
{"[0] action", 123, 112, 0, 0, 62}, //0x08 
{"[1] action", 281, 112, 0, 0, 62}  //0x09 
};
 
button keyboardbutton[KEYBOARDBUTTON_MAX] = {
{"[defaut]",  10, 209, 0, 0, 68}, //0x00 
{"[sauver]", 228, 209, 0, 0, 68}  //0x01 
};
 
button joystickbutton[JOYSTICKBUTTON_MAX] = {
{"[defaut]",  10, 209, 0, 0, 68}, //0x00 
{"[sauver]", 228, 209, 0, 0, 68}  //0x01 
};

#ifdef WIN32
//scancode hardware du PC Windows pour chaque touche MO5
//(+ 0x40 pour les touches du pave numerique pour les distinguer des autres)
int pckeycode[MO5KEY_MAX]=
{
 0x31, //0x00 N
 0x53, //0x01 EFF
 0x24, //0x02 J
 0x23, //0x03 H
 0x16, //0x04 U
 0x15, //0x05 Y
 0x08, //0x06 7 '
 0x07, //0x07 6 &
 0x32, //0x08 , <
 0x52, //0x09 INS
 0x25, //0x0a K
 0x22, //0x0b G
 0x17, //0x0c I
 0x14, //0x0d T
 0x09, //0x0e 8 (
 0x06, //0x0f 5 %
 0x33, //0x10 . >
 0x47, //0x11 DEBUT
 0x26, //0x12 L 
 0x21, //0x13 F
 0x18, //0x14 O
 0x13, //0x15 R
 0x0a, //0x16 9 )
 0x05, //0x17 4 $
 0x34, //0x18 @ ^
 0x4d, //0x19 DROITE
 0x27, //0x1a M
 0x20, //0x1b D
 0x19, //0x1c P
 0x12, //0x1d E
 0x0b, //0x1e 0 `
 0x04, //0x1f 3 #
 0x39, //0x20 ESPACE
 0x50, //0x21 BAS
 0x30, //0x22 B
 0x1f, //0x23 S
 0x28, //0x24 / ?
 0x11, //0x25 Z
 0x0c, //0x26 - =
 0x03, //0x27 2 "
 0x2d, //0x28 X
 0x4b, //0x29 GAUCHE
 0x2f, //0x2a V
 0x1e, //0x2b Q
 0x2b, //0x2c * :
 0x10, //0x2d A 
 0x0d, //0x2e + ;
 0x02, //0x2f 1 !
 0x2c, //0x30 W
 0x48, //0x31 HAUT
 0x2e, //0x32 C
 0x4f, //0x33 RAZ
 0x1c, //0x34 ENTREE
 0x1d, //0x35 CNT
 0x1b, //0x36 ACC
 0x29, //0x37 STOP
 0x2a, //0x38 MAJUSCULE
 0x36  //0x39 BASIC
};

//scancode hardware du PC Windows pour chaque fonction des manettes MO5
//(+ 0x40 pour les touches du pave numerique pour les distinguer des autres)
int pcjoycode[JOYKEY_MAX]=
{
 0x8c, //0 manette 0 HAUT 
 0x90, //1 manette 0 BAS
 0x8f, //2 manette 0 GAUCHE
 0x91, //3 manette 0 DROITE 
 0x75, //4 manette 1 HAUT 
 0x88, //5 manette 1 BAS
 0x87, //6 manette 1 GAUCHE
 0x89, //7 manette 1 DROITE
 0x5c, //8 manette 0 ACTION
 0x8e  //9 manette 1 ACTION
};

#else

//scancode hardware du PC Linux pour chaque touche MO5
//(+ 0x40 pour les touches du pave numerique pour les distinguer des autres)
int pckeycode[MO5KEY_MAX]=
{
 0x39, //0x00 N
 0x6b, //0x01 EFF
 0x2c, //0x02 J
 0x2b, //0x03 H
 0x1e, //0x04 U
 0x1d, //0x05 Y
 0x10, //0x06 7 '
 0x0f, //0x07 6 &
 0x3a, //0x08 , <
 0x6a, //0x09 INS
 0x2d, //0x0a K
 0x2a, //0x0b G
 0x1f, //0x0c I
 0x1c, //0x0d T
 0x11, //0x0e 8 (
 0x0e, //0x0f 5 %
 0x3b, //0x10 . >
 0x61, //0x11 DEBUT
 0x2e, //0x12 L 
 0x29, //0x13 F
 0x20, //0x14 O
 0x1b, //0x15 R
 0x12, //0x16 9 )
 0x0d, //0x17 4 $
 0x3c, //0x18 @ ^
 0x66, //0x19 DROITE
 0x2f, //0x1a M
 0x28, //0x1b D
 0x21, //0x1c P
 0x1a, //0x1d E
 0x13, //0x1e 0 `
 0x0c, //0x1f 3 #
 0x41, //0x20 ESPACE
 0x68, //0x21 BAS
 0x38, //0x22 B
 0x27, //0x23 S
 0x30, //0x24 / ?
 0x19, //0x25 Z
 0x14, //0x26 - =
 0x0b, //0x27 2 "
 0x35, //0x28 X
 0x64, //0x29 GAUCHE
 0x37, //0x2a V
 0x26, //0x2b Q
 0x33, //0x2c * :
 0x18, //0x2d A 
 0x15, //0x2e + ;
 0x0a, //0x2f 1 !
 0x34, //0x30 W
 0x62, //0x31 HAUT
 0x36, //0x32 C
 0x67, //0x33 RAZ
 0x24, //0x34 ENTREE
 0x25, //0x35 CNT
 0x23, //0x36 ACC
 0x31, //0x37 STOP
 0x32, //0x38 MAJUSCULE
 0x3e  //0x39 BASIC
};

//scancode hardware du PC Linux pour chaque fonction des manettes MO5
//(+ 0x40 pour les touches du pave numerique pour les distinguer des autres)
int pcjoycode[JOYKEY_MAX]=
{
 0x94, //0 manette 0 HAUT 
 0x98, //1 manette 0 BAS
 0x97, //2 manette 0 GAUCHE
 0x99, //3 manette 0 DROITE 
 0xb0, //4 manette 1 HAUT 
 0x90, //5 manette 1 BAS
 0x8f, //6 manette 1 GAUCHE
 0x91, //7 manette 1 DROITE
 0xac, //8 manette 0 ACTION
 0x96  //9 manette 1 ACTION
};

#endif

/*
//essai avec les noms symbolique
//le clavier francais n'est pas reconnu dans Windows 
int pckeysym[MO5KEY_MAX]=
{
 SDLK_n,          //0x00 N
 SDLK_DELETE,     //0x01 EFF
 SDLK_j,          //0x02 J
 SDLK_h,          //0x03 H
 SDLK_u,          //0x04 U
 SDLK_y,          //0x05 Y
 SDLK_7,          //0x06 7 '
 SDLK_6,          //0x07 6 &
 SDLK_COMMA,      //0x08 , <
 SDLK_INSERT,     //0x09 INS
 SDLK_k,          //0x0a K
 SDLK_g,          //0x0b G
 SDLK_i,          //0x0c I
 SDLK_t,          //0x0d T
 SDLK_8,          //0x0e 8 (
 SDLK_5,          //0x0f 5 %
 SDLK_PERIOD,     //0x10 . >
 SDLK_HOME,       //0x11 DEBUT
 SDLK_l,          //0x12 L 
 SDLK_f,          //0x13 F
 SDLK_o,          //0x14 O
 SDLK_r,          //0x15 R
 SDLK_9,          //0x16 9 )
 SDLK_4,          //0x17 4 $
 SDLK_SLASH,      //0x18 @ ^
 SDLK_RIGHT,      //0x19 DROITE
 SDLK_m,          //0x1a M
 SDLK_d,          //0x1b D
 SDLK_p,          //0x1c P
 SDLK_e,          //0x1d E
 SDLK_0,          //0x1e 0 `
 SDLK_3,          //0x1f 3 #
 SDLK_SPACE,      //0x20 ESPACE
 SDLK_DOWN,       //0x21 BAS
 SDLK_b,          //0x22 B
 SDLK_s,          //0x23 S
 SDLK_SEMICOLON,  //0x24 / ?
 SDLK_z,          //0x25 Z
 SDLK_RIGHTPAREN, //0x26 - =
 SDLK_2,          //0x27 2 "
 SDLK_x,          //0x28 X
 SDLK_LEFT,       //0x29 GAUCHE
 SDLK_v,          //0x2a V
 SDLK_q,          //0x2b Q
 SDLK_ASTERISK,   //0x2c * :
 SDLK_a,          //0x2d A 
 SDLK_PLUS,       //0x2e + ;
 SDLK_1,          //0x2f 1 !
 SDLK_w,          //0x30 W
 SDLK_UP,         //0x31 HAUT
 SDLK_c,          //0x32 C
 SDLK_END,        //0x33 RAZ
 SDLK_RETURN,     //0x34 ENTREE
 SDLK_LCTRL,      //0x35 CNT
 SDLK_DOLLAR,     //0x36 ACC
 SDLK_HASH,       //0x37 STOP
 SDLK_LSHIFT,     //0x38 MAJUSCULE
 SDLK_RSHIFT      //0x39 BASIC
};

int pcjoysym[JOYKEY_MAX]=
{
 SDLK_KP5,        //0 manette 0 HAUT 
 SDLK_KP2,        //1 manette 0 BAS
 SDLK_KP1,        //2 manette 0 GAUCHE
 SDLK_KP3,        //3 manette 0 DROITE 
 SDLK_KP_DIVIDE,  //4 manette 1 HAUT 
 SDLK_KP8,        //5 manette 1 BAS
 SDLK_KP7,        //6 manette 1 GAUCHE
 SDLK_KP9,        //7 manette 1 DROITE
 SDLK_KP_ENTER,   //8 manette 0 ACTION
 SDLK_KP_PLUS     //9 manette 1 ACTION
};

#ifdef WIN32
//scancode PC Windows en fonction du scancode MO5
//version avec STOP par �, BASIC par shift-droit, ACC par backspace
//pose le probl�me des touches shift droite et gauche simultan�es 
int pckeycode[MO5KEY_MAX]=
{
 0x06e, //0x00 N
 0x07f, //0x01 EFF
 0x06a, //0x02 J
 0x068, //0x03 H
 0x075, //0x04 U
 0x079, //0x05 Y
 0x037, //0x06 7 '
 0x036, //0x07 6 &
 0x06d, //0x08 , <
 0x115, //0x09 INS
 0x06b, //0x0a K
 0x067, //0x0b G
 0x069, //0x0c I
 0x074, //0x0d T
 0x038, //0x0e 8 (
 0x035, //0x0f 5 %
 0x02c, //0x10 . >
 0x116, //0x11 DEBUT
 0x06c, //0x12 L 
 0x066, //0x13 F
 0x06f, //0x14 O
 0x072, //0x15 R
 0x039, //0x16 9 )
 0x034, //0x17 4 $
 0x02e, //0x18 @ ^
 0x113, //0x19 DROITE
 0x03b, //0x1a M
 0x064, //0x1b D
 0x070, //0x1c P
 0x065, //0x1d E
 0x030, //0x1e 0 `
 0x033, //0x1f 3 #
 0x020, //0x20 ESPACE
 0x112, //0x21 BAS
 0x062, //0x22 B
 0x073, //0x23 S
 0x027, //0x24 / ?
 0x077, //0x25 Z
 0x02d, //0x26 - =
 0x032, //0x27 2 "
 0x078, //0x28 X
 0x114, //0x29 GAUCHE
 0x076, //0x2a V
 0x061, //0x2b Q
 0x05c, //0x2c * :
 0x071, //0x2d A 
 0x03d, //0x2e + ;
 0x031, //0x2f 1 !
 0x07a, //0x30 W
 0x111, //0x31 HAUT
 0x063, //0x32 C
 0x117, //0x33 RAZ
 0x00d, //0x34 ENTREE
 0x132, //0x35 CNT
 0x05d, //0x36 ACC
 0x060, //0x37 STOP
 0x130, //0x38 MAJUSCULE
 0x12f  //0x39 BASIC
};

int pcjoycode[JOYKEY_MAX]=
{
 0x105, //0 manette 0 HAUT 
 0x102, //1 manette 0 BAS
 0x101, //2 manette 0 GAUCHE
 0x103, //3 manette 0 DROITE 
 0x10b, //4 manette 1 HAUT 
 0x108, //5 manette 1 BAS
 0x107, //6 manette 1 GAUCHE
 0x109, //7 manette 1 DROITE
 0x10f, //8 manette 0 ACTION
 0x10e  //9 manette 1 ACTION
};

#else

//scancode PC Linux en fonction du scancode MO5
int pckeycode[MO5KEY_MAX]={
 0x06e, //0x00 N
 0x07f, //0x01 EFF
 0x06a, //0x02 J
 0x068, //0x03 H
 0x075, //0x04 U
 0x079, //0x05 Y
 0x0e8, //0x06 7 '
 0x02d, //0x07 6 &
 0x02c, //0x08 , <
 0x115, //0x09 INS
 0x06b, //0x0a K
 0x067, //0x0b G
 0x069, //0x0c I
 0x074, //0x0d T
 0x05f, //0x0e 8 (
 0x028, //0x0f 5 % 
 0x03b, //0x10 . >
 0x116, //0x11 DEBUT
 0x06c, //0x12 L 
 0x066, //0x13 F
 0x06f, //0x14 O
 0x072, //0x15 R
 0x0e7, //0x16 9 )
 0x027, //0x17 4 $ 
 0x021, //0x18 @ ^
 0x113, //0x19 DROITE
 0x06d, //0x1a M
 0x064, //0x1b D
 0x070, //0x1c P
 0x065, //0x1d E
 0x0e0, //0x1e 0 `
 0x022, //0x1f 3 # 
 0x020, //0x20 ESPACE
 0x112, //0x21 BAS
 0x062, //0x22 B
 0x073, //0x23 S
 0x03a, //0x24 / ?
 0x07a, //0x25 Z
 0x029, //0x26 - =
 0x0e9, //0x27 2 " 
 0x078, //0x28 X
 0x114, //0x29 GAUCHE
 0x076, //0x2a V
 0x071, //0x2b Q
 0x02a, //0x2c * :
 0x061, //0x2d A 
 0x03d, //0x2e + ;
 0x026, //0x2f 1 ! 
 0x077, //0x30 W
 0x111, //0x31 HAUT
 0x063, //0x32 C
 0x117, //0x33 RAZ
 0x00d, //0x34 ENTREE
 0x132, //0x35 CNT
 0x131, //0x36 ACC
 0x060, //0x37 STOP 
 0x130, //0x38 MAJUSCULE
 0x12f  //0x39 BASIC
};

int pcjoycode[JOYKEY_MAX]={   //a verifier ?????????????????
 0x105, //0 manette 0 HAUT 
 0x102, //1 manette 0 BAS
 0x101, //2 manette 0 GAUCHE
 0x103, //3 manette 0 DROITE 
 0x10b, //4 manette 1 HAUT 
 0x108, //5 manette 1 BAS
 0x107, //6 manette 1 GAUCHE
 0x109, //7 manette 1 DROITE
 0x10f, //8 manette 0 ACTION
 0x10e  //9 manette 1 ACTION
};
#endif
*/
