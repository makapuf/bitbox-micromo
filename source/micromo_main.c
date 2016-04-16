// micromo_main.c

#include <string.h>
#include <bitbox.h>
#include "dcmo5.h"

#define TOUR_H ((VGA_H_PIXELS-320)/2)
#define TOUR_V ((VGA_V_PIXELS-200)/2)

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
	220, // jaune poussin
	109, // bleu ciel
	207, // rose parme
	191, // cyan clair
	209, // orange

};

int pause6809;        // processor pause state
int report;           // nombre de milliemes de cycle a reporter

#define DEBUG_SHOWRAM 0

void graph_frame() {};
void graph_line8(void) {

	if (DEBUG_SHOWRAM) {
		memset(draw_buffer,1,400);
		if (vga_line<0xc0)
			memcpy(draw_buffer,ram+(vga_line*256),256);

		return;
	}

	if (vga_odd) return; // just skip now ? call menu ?

	if ((vga_line<TOUR_V || vga_line>TOUR_V+200)) {
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
			uint8_t fond = palette [ c >> 4 ];
			uint8_t teinte = palette [ c &0xf ];

			// now blit - xx use SEL on device ?
			uint8_t f = *(src++ + 0x2000);
			for (int i=0;i<8;i++,f<<=1) {
				*dst++ = f&0x80?teinte:fond;
			}
		}
	}
}



// 0x1000 block of data
unsigned int crc32b(unsigned char *message) {
   int i, j;
   unsigned int byte, crc, mask;

   i = 0;
   crc = 0xFFFFFFFF;
   while (i<0x100) {
      byte = message[i];            // Get next byte.
      crc = crc ^ byte;
      for (j = 7; j >= 0; j--) {    // Do eight times.
         mask = -(crc & 1);
         crc = (crc >> 1) ^ (0xEDB88320 & mask);
      }
      i = i + 1;
   }
   return ~crc;
}


// make a visual checksum of ram (state) on screen

uint32_t tmpdata[64]; // local copy to avoir polluting ram
void visi_ram()
{
	for (int k=0;k<0xb;k++) {
		for (int i=0;i<0x10;i++){
			// each RAM segment
			tmpdata[i] = crc32b(ram+k*0x1000+i*0x100);
			message("%x %x\n",k*0x1000+i*0x100,tmpdata[i]);
		}

		memcpy(ram+40*k, tmpdata, sizeof(tmpdata));
	}

	memset(ram+0x2000,0xaa,0x2000); // pattern !

}



void game_init() {
    // initialisations
//    Joyinit();                        // Joysticks initialization
//    Keyboardinit();                   // Keyboard initialization
    Initoptions();                    // Option initialization
   // Initfilenames();
    Init6809registerpointers();
    Hardreset();                      // MO5 initialization
}

void game_frame() {
	// sync FRAME now -> sound !
	Run(1000000UL / 60 );
}

// STUBS for BItbox

void Erreur(int n) {}
void Displayline(videolinenumber) {}

// stubs devices
int k7protection;
int fdprotection;

void Readsector() {}
void Writesector() {}
void Formatdisk() {}
void Readbitk7() {}
void Readoctetk7() {}
void Writeoctetk7() {}
void Readpenxy() {}
void Imprime() {}

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