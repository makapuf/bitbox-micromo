// dcmoto.h : interface to dcmo5 functions

#include "bitbox.h"

#define TOUR_H ((VGA_H_PIXELS-320)/2)
#define TOUR_V ((VGA_V_PIXELS-200)/2)

// in emulation
extern const unsigned char mo5_rom[];
extern char ram[0xc000];                    // ram 48K.

extern char *ramvideo;                      // pointeur couleurs ou formes . Change selon IO !
extern char *ramuser;                       // pointeur ram utilisateur fixe
extern char *romsys;                        // pointeur rom systeme
extern const char *rombank;                       // pointeur banque rom ou cartouche
extern int bordercolor; 					// couleur du bord 0-f
extern uint8_t touche[];                      // etat des touches MO5

extern char *k7_name;
extern char *k7_data;
extern int k7_len; // cannot use const here ?
extern int k7_pos; // pos in k7. cannot be used here (const ...)
extern int k7bit;
extern int k7protection;
extern int fdprotection;


extern int pause6809; 						// in dcmo5_emulation
void micromo_keyboard();

void Init6809registerpointers();
void Hardreset();
void Initprog();

// in dc6809
int Run6809(); // execs an instruction
int Run(int); // Runs N times

// in main
void Erreur(int n);

// ROM
extern const unsigned char mo5_rom[];
extern const unsigned int mo5_rom_len;
