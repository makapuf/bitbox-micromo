// dcmoto.h

#include "bitbox.h"

#define MO5KEY_MAX 58        // nombre de touches du clavier MO5

// in emulation
extern char ram[0xc000];                    // ram 48K.

extern char *ramvideo;                      // pointeur couleurs ou formes . Change selon IO !
extern char *ramuser;                       // pointeur ram utilisateur fixe
extern char *romsys;                        // pointeur rom systeme
extern const char *rombank;                       // pointeur banque rom ou cartouche
extern int bordercolor; 					// couleur du bord 0-f
extern uint8_t touche[58];                      // etat des touches MO5


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
