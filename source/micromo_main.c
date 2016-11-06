// micromo_main.c

#include <string.h>
#include <bitbox.h>
#include "dcmo5.h"
#include "micromo_dialog.h"
#include "../build/k7.h"


const uint8_t palette[16] = {
	0,   // noir
	224, // rouge
	57,  // vert
	249, // jaune
	39,  // bleu
	231, // magenta
	63,  // cyan
	255, // blanc

	181, // gris
	203, // rose
	124, // vert clair
	220, // sable
	109, // bleu ciel
	207, // parme
	191, // cyan clair
	209, // orange

};

int report;           // nombre de milliemes de cycle a reporter

int frequency = 1000;        // frequence 6809 en kHz

/* Debug show ram replaces drawing the real device screen  with
   a graphical view of the memory for quick debugging. */
#define DEBUG_SHOWRAM 0




void graph_line(void) {

	if (vga_odd) {
		dialog_drawline8();
		return;
	}


	if (DEBUG_SHOWRAM) {
		memset(draw_buffer,1,400);
		if (vga_line<0xc0)
			memcpy(draw_buffer,ram+(vga_line*256),256);

		return;
	}


	if ((vga_line<TOUR_V || vga_line>=TOUR_V+200)) {
		memset(draw_buffer, palette[bordercolor], VGA_H_PIXELS);
	} else {
		uint8_t *dst = (uint8_t *)draw_buffer; // use 8bit interface
		// les bords
		for (int i=0;i<TOUR_H;i++){
			*dst = palette[bordercolor];
			*(dst+320+TOUR_H) = palette[bordercolor];
			dst++;
		}

		char *src = &ram[ 40*(vga_line-TOUR_V) ];
		for (int byte=0;byte<40;byte++) // 320 pixels / 8 = 40 octets par ligne
		{
			uint8_t c  = *(src); // color attribute
			uint8_t fond   = palette [ c >> 4 ];
			uint8_t teinte = palette [ c &0xf ];

			// now blit - xx use SEL on device ?
			uint8_t f = *(src++ + 0x2000);
			for (int i=0;i<8;i++,f<<=1) {
				*dst++ = f&0x80?fond:teinte;
			}
		}
	}
}


void game_init() {
    // initialisations
    Init6809registerpointers();
    Hardreset();                      // MO5 initialization
}

void game_frame() {
	// sync FRAME now -> should be in sound callback for better sync !
	if (!pause6809)
		Run(1000000UL / 60 );

	micromo_keyboard();
	dialog_frame();
}

// STUBS for Bitbox

void Erreur(int n) {
	message("Erreur %d\n",n);
	dialog_menu("Error","Error undefined",0);
}


void Displayline(int videolinenumber) {}


/*

// Play sound ////////////////////////////////////////////////////////////////
void Playsound(void *udata, Uint8 *stream, int bufferlength)
{
    int i;
    int mcycles; // nombre de milliemes de cycles entre deux echantillons
    int icycles; // nombre entier de cycles entre deux echantillons
    extern int sound, frequency;
    extern int Run(int n);
    extern void Testshiftkey();
    // 45 cycles 6809 a 992250 Hz = un echantillon a 22050 Hz
    for(i = 0; i < bufferlength; i++)
    {
        if(pause6809) {stream[i] = 128; continue; }
        // calcul et execution du nombre de cycles entre deux echantillons
        // nbre de cycles theoriques pour la periode en cours =
        // nbre theorique + relicat arrondi precedent - cycles en trop precedent
        mcycles = frequency * 100000 / 2205; // milliemes de cycles theoriques
        mcycles += report;                   // milliemes de cycles corriges
        icycles = mcycles / 1000;            // nbre entier de cycles a effectuer
        report = mcycles - 1000 * icycles;   // relicat de l'arrondi a reporter
        report -= 1000 * Run(icycles);       // retrancher les milliemes en trop
        stream[i] = sound + 128;
    }
    Testshiftkey();                          // contournement bug SDL sur l'appui simultane SHIFT, ALT, CTRL
}*/


void cb_k7(int choice) {
    message("selected k7 :%d\n",choice);
    k7_data = k7list[choice].data;
    k7_len = k7list[choice].size;
    k7_pos = 0;
    k7bit=0;
}


void main_cb(int x) {
    message("selected %d\n",x);


    switch(x) {
        case 0:
            dialog_menu("Keyboard Help",
            	"EFF : Del\nDEBUT : Home\nRAZ : PgUp\nCNT : PgDn\nACC : Ctrl droite\n"
            	"STOP : pause\nMAJ : maj gauche\nBASIC : Maj Droite",0);
            break;
        case 1: // reboot
            Initprog();
            pause6809 = 0;
            break;
        case 2:  // select k7
            dialog_menu("Cassette select",k7list_str,cb_k7);
            break;
        case 3:
            pause6809 = 1-pause6809;
            break;
        case 4 :
            dialog_menu("MicroMo","Micromo est un port\nde l'emulateur DCMO5 v11\nsur la micro Bitbox.\n\n"
            	"DCMO5 (07) Daniel Coulom\nMicroMO (16) Makapuf :)",0);
            break;
    }
}

void main_menu()
{
    dialog_menu("MicroMO","Help\nReset\nSelect k7\nPause\nA propos...",main_cb);
}
