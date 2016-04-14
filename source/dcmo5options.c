// new menu for option-setting & file loading

#include <stdio.h>

#include "dcmo5global.h"

#define DIRLIST_LENGTH 32
#define DIRLIST_NMAX 500

int language;                        // 0=francais 1=anglais
int frequency;                       // frequence 6809 en kHz

int dialog = 0;                             // 0=rien 1=message, 2=options 3=clavier 4=menu
int mouselastx, mouselasty;                 // position souris dans dialogbox
int dircount;                               // nombre de fichiers dans le repertoire
char dirlist[DIRLIST_NMAX][DIRLIST_LENGTH]; // liste des fichiers du repertoire
int dirmin, dirmax;                         // plage de numeros de fichiers affiches
void (*Load[3]) (char *name);               // pointeur fonction de chargement de fichier

extern int ystatus;

extern int xbitmap, ybitmap, xclient, yclient, ystatus, framedelay;
extern int k7protection;             // protection k7 (0=lecture/ecriture 1=lecture seule)
extern int fdprotection;             // protection fd (0=lecture/ecriture 1=lecture seule)
extern char *msg[LANG_MAX][MSG_MAX]; // messages en plusieurs langues

void Initoptions()
{
    language = 0;          // francais
    //xclient = 2 * xbitmap; // zoomx 2
    //yclient = 2 * ybitmap; // zoomy 2
    //framedelay = 2;        // nombre de vbl entre deux affichages
    frequency = 1000;      // 1000 kHz
    k7protection = 1;      // protection cassette
    fdprotection = 1;      // protection disquette

    // ouverture fichier dcmo5.ini
    /*
    char string[256];
    fpi = fopen("dcmo5.ini", "rb+");                   // s'il existe ouverture
    if (fpi == NULL) fpi = fopen("dcmo5.ini", "wb+");  // s'il n'existe pas : creation
    fread(string, 12, 1, fpi);                         // lecture identifiant
    if (strcmp("dcmo5ini-01", string) != 0) return;
    // initialisation des options
    fread(&language, 4, 1, fpi);                       // langue
    fread(&frequency, 4, 1, fpi);                      // frequence 6809
    fread(&xclient, 4, 1, fpi);                        // largeur ecran
    fread(&yclient, 4, 1, fpi);                        // hauteur ecran
    fread(&framedelay, 4, 1, fpi);
    fread(&k7protection, 4, 1, fpi);
    fread(&fdprotection, 4, 1, fpi);

    // controle
    if (language < 0) language = 0;
    if ( language > (LANG_MAX - 1) ) language = LANG_MAX - 1;
    if (frequency < 100) frequency = 100;
    if (frequency > 9000) frequency = 9000;
    if (xclient < xbitmap) xclient = xbitmap;
    if ( xclient > (4 * xbitmap) ) xclient = 4 * xbitmap;
    if (yclient < ybitmap) yclient = ybitmap;
    if ( yclient > (4 * ybitmap) ) yclient = 4 * ybitmap;
    if (framedelay < 1) framedelay = 1;
    if (framedelay > 64) framedelay = 64;
    if (k7protection) k7protection = 1;
    if (fdprotection) fdprotection = 1;
    */
}


// Traitement des clics souris ////////////////////////////////////////////////
void Mouseclick()
{
    extern int xmouse, ymouse, pause6809;
    extern void Menuclick();
    pause6809 = 1;

    /*
    // clic dans la barre de statut
    if(ymouse < ystatus) {
        Statusclick();
        pause6809 = 0;
        return;
    }
    */

    // clic dans la boite de dialogue
        /*
        if(dialog > 0)
        if(xmouse > dialogrect.x) if( xmouse < (dialogrect.x + dialogrect.w) )
                if(ymouse > dialogrect.y) if( ymouse < (dialogrect.y + dialogrect.h) )
                    {
                        if(dialog > 999)
                            Menuclick();
                        else
                            Dialogclick();
                    }
        */

    // redemarrage de l'emulation, meme si elle etait arretee
    // sinon il n'y a pas d'affichage
    pause6809 = 0;
}


void Saveoptions()
{
    // do nothing now
}

