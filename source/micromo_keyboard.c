// micromo: gesiton du clavier via API bitbox
#include "dcmo5.h"
#include "micromo_dialog.h"

// pc -> mo5 keycode. reversed with designated init !
static uint8_t pckeycode[]= {
    [0x11] = 0x00, // 0x00 N
    [0x4C] = 0x01, // 0x01 EFF (del)
    [0x0d] = 0x02, // 0x02 J
    [0x0b] = 0x03, // 0x03 H
    [0x18] = 0x04, // 0x04 U
    [0x1c] = 0x05, // 0x05 Y
    [0x24] = 0x06, // 0x06 7 '
    [0x23] = 0x07, // 0x07 6 &
    [0x36] = 0x08, // 0x08 , <
    [0x49] = 0x09, // 0x09 INS
    [0x0e] = 0x0a, // 0x0a K
    [0x0a] = 0x0b, // 0x0b G
    [0x0c] = 0x0c, // 0x0c I
    [0x17] = 0x0d, // 0x0d T
    [0x25] = 0x0e, // 0x0e 8 (
    [0x22] = 0x0f, // 0x0f 5 %
    [0x37] = 0x10, // 0x10 . >
    [0x4a] = 0x11, // 0x11 DEBUT (home)
    [0x0f] = 0x12, // 0x12 L
    [0x09] = 0x13, // 0x13 F
    [0x12] = 0x14, // 0x14 O
    [0x15] = 0x15, // 0x15 R
    [0x26] = 0x16, // 0x16 9 )
    [0x21] = 0x17, // 0x17 4 $
    [0x38] = 0x18, // 0x18 @ ^
    [0x4f] = 0x19, // 0x19 DROITE
    [0x10] = 0x1a, // 0x1a M
    [0x07] = 0x1b, // 0x1b D
    [0x13] = 0x1c, // 0x1c P
    [0x08] = 0x1d, // 0x1d E
    [0x27] = 0x1e, // 0x1e 0 `
    [0x20] = 0x1f, // 0x1f 3 #
    [0x2c] = 0x20, // 0x20 ESPACE
    [0x51] = 0x21, // 0x21 BAS
    [0x05] = 0x22, // 0x22 B
    [0x16] = 0x23, // 0x23 S
    [0x2f] = 0x24, // 0x24 / ?
    [0x1a] = 0x25, // 0x25 Z
    [0x2d] = 0x26, // 0x26 - =
    [0x1f] = 0x27, // 0x27 2 "
    [0x1b] = 0x28, // 0x28 X
    [0x50] = 0x29, // 0x29 GAUCHE
    [0x19] = 0x2a, // 0x2a V
    [0x04] = 0x2b, // 0x2b Q
    [0x30] = 0x2c, // 0x2c * :
    [0x14] = 0x2d, // 0x2d A
    [0x2e] = 0x2e, // 0x2e + ;
    [0x1e] = 0x2f, // 0x2f 1 !
    [0x1d] = 0x30, // 0x30 W
    [0x52] = 0x31, // 0x31 HAUT
    [0x06] = 0x32, // 0x32 C
    [0x4b] = 0x33, // 0x33 RAZ (pgup)
    [0x28] = 0x34, // 0x34 ENTREE
    [0x4e] = 0x35, // 0x35 CNT (pgdn)
    [0xe4] = 0x36, // 0x36 ACC (ctrl droite)
    [0x48] = 0x37, // 0x37 STOP (pause)
    [0xe1] = 0x38, // 0x38 MAJUSCULE (lshift)
    [0xe5] = 0x39  // 0x39 BASIC (rshift)
};


void cb_k7(int choice) {
    message("selected k7 :%d\n",choice);
}

void do_nothing(int x) {
    message("selected %d\n",x);
    switch(x) {
        case 0:
            dialog_menu("Keyboard Help", "EFF : Del\nDEBUT : Home\nRAZ : PgUp\nCNT : PgDn\nACC : Ctrl droite\nSTOP : pause\nMAJ : maj gauche\nBASIC : Maj Droite",0);
            break;
        case 1: // reboot
            Initprog();
            pause6809 = 0;
            break;
        case 2:  // select k7
            dialog_menu("Cassette select","Arkanoid\nDemo\netc\netc\nceci\nest\nun\ntres\nlong\nmenu\nmais\nca\ndevrait\naller",cb_k7);
            break;
        case 3:
            pause6809 = 1-pause6809;
            break;
        case 4 :
            dialog_menu("MicroMo","Micromo est un port\nde l'emulateur DCMO5 v11\nsur la micro Bitbox.\n\nDCMO5 (07) Daniel Coulom\nMicroMO (16) Makapuf :)",0);
            break;
    }
}

void micromo_keyboard (void)
{
	struct event e;
	while (1) {
		e=event_get();
		if (e.type==no_event)
			break;
		else if (e.type==evt_keyboard_press) {
            if (dialog_active()) {
                dialog_keypress(e); // menu ? if in menu dont send keys to emulator
            } else {
                // prise en charge directe par l'emulateur
                if(e.kbd.key == 0x29) {
                    /* KEY_PAUSE : pause, */
                    dialog_menu("MicroMO","Help\nReset\nSelect k7 (F2)\nPause\nA propos...",do_nothing);
                    return;
                } else {
                    if (e.kbd.key)
                        touche[pckeycode[e.kbd.key]] = 0x00;
                }
            }

			// message ("pressed key %x mod %x sym %c mo5 %d\n",e.kbd.key, e.kbd.mod, e.kbd.sym, pckeycode[e.kbd.key]);
		} else if (e.type==evt_keyboard_release) {

	    	if (e.kbd.key)
	    		touche[pckeycode[e.kbd.key]] = 0x80;
			// message ("released key %x mod %x sym %c mo5 %d\n",e.kbd.key, e.kbd.mod, e.kbd.sym, pckeycode[e.kbd.key]);

		}
	}
}

