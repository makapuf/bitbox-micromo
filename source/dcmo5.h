// dcmoto.h

#include "bitbox.h"

#define TOUR_H ((VGA_H_PIXELS-320)/2)
#define TOUR_V ((VGA_V_PIXELS-200)/2)

// in emulation
extern const char mo5rom[];
extern char ram[0xc000];                    // ram 48K.

extern char *ramvideo;                      // pointeur couleurs ou formes . Change selon IO !
extern char *ramuser;                       // pointeur ram utilisateur fixe
extern char *romsys;                        // pointeur rom systeme
extern const char *rombank;                       // pointeur banque rom ou cartouche
extern int bordercolor; 					// couleur du bord 0-f
extern uint8_t touche[];                      // etat des touches MO5


extern int k7protection;
extern int fdprotection;


extern int pause6809; 						// in dcmo5_emulation
void micromo_keyboard();

void Init6809registerpointers();
void Initfilenames( );
void Hardreset();
void Initoptions();

void Joyinit();                        // Joysticks initialization
void Keyboardinit();                   // Keyboard initialization


// in dc6809
int Run6809(); // execs an instruction
int Run(int); // Runs N times

// in main
void Erreur(int n);
