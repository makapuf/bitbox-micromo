#include "dcmo5.h"
#include "../build/binaries.h"

void Drawk7index();
void Initprog();
void Erreur(int n);


// pointeurs vers fonctions d'acces memoire
extern char (*Mgetc)(unsigned short a);
extern void (*Mputc)(unsigned short a, char c);

// 6809 registers
extern int CC;
extern short D, S;
extern char *Ap, *Bp;

// -----------------------------

char *k7_name="SHINRA MO5:FirstEver";
char *k7_data=software_SHR_MO5_FirstEver_k7; // XXX for now no selection of cassette, only one.
int k7_len; // cannot use const here ?
int k7_pos=0; // pos in k7. cannot be used here (const ...)
int k7bit = 0;      // puissance de 2 designant le bit k7 en cours
int k7octet;        // octet de la cassette en cours de traitement

int k7protection;
int fdprotection;


// --------------------------------------------------------------------
// stubs !

void Readsector() {}
void Writesector() {}
void Formatdisk() {}
void Readpenxy() {}

// --------------------------------------------------------------------
void Imprime()
{
    message("imprime: %c", *Bp);
    CC &= 0xfe;
}

// --------------------------------------------------------------------
// Emulation cassette for the bitbox, ( directly from flash data )

void Readoctetk7()
{
    //if (k7_pos==k7_len) {
    if ( k7_pos==software_SHR_MO5_FirstEver_k7_len ) { // XXX use k7_len !
        Initprog(); // reset
        Erreur(12);
        k7_pos=0;
        message("k7 pos : %d\n",k7_pos); // Drawk7index();
    } else {
        *Ap = k7octet = k7_data[k7_pos++];
        Mputc(0x2045, k7octet);
        k7bit = 0;
    }
}

void Readbitk7()
{
    int octet = Mgetc(0x2045) << 1;

    if(k7bit == 0) {
        Readoctetk7();
        k7bit = 0x80;
    }

    if( (k7octet & k7bit) ) {
        octet |= 0x01;
        *Ap = 0xff;
    } else {
        *Ap = 0;
    }

    Mputc(0x2045, octet);
    k7bit >>= 1;
}

void Writeoctetk7()
{
    /*
    if(fk7 == NULL) {
        Initprog();
        Erreur(11);
        return;
    }
    if(k7protection) {
        Initprog();
        Erreur(13);
        return;
    }
    if(fputc(*Ap, fk7) == EOF) {
            Initprog();
            Erreur(13);
            return;
    }
    Mputc(0x2045, 0);
    if( (ftell(fk7) & 511) == 0 ) {
        k7index = ftell(fk7) >> 9;
        Drawk7index();
    }
    */
}

void Loadk7(int cassette_id)
{

    k7_pos = 0;
    Drawk7index();
    // k7protection = 1;

}

void Rewindk7()
{
    k7_pos=0;
}
