#include <string.h>

#include "bitbox.h"
#include "dcmo5.h"
#include "micromo_dialog.h"

// colors
#define COL_WHITE 255
#define COL_LIGHTGREY 222
#define COL_MIDGREY 181
#define COL_DARKGREY 148
#define COL_BLACK 0

#define BG_TITLE 233 // bg title orange
#define BG_SELECTED 242 // bg selected - orange

#define FONT (mo5_rom + 0xfc9e - 0xc000 -1)
#define POS_HIDDEN (-200)

// internal state used for display
static char vram[DIALOG_H][DIALOG_W];
static char vram_title[DIALOG_W];

static int pos_y=POS_HIDDEN; // Y on screen position of window.
static int pos_y_target=POS_HIDDEN;

static int select; // option menu choisie (absolue).
static int offset; // décalage d'affichage

static int nb_elements; // current text/ menu number of lines

// interface data
static const char *title, *items; // titre de la fenetre, lignes de contenu separees par \n, terminée par \0
static void (*callback)(int); // if null display text, else display/interact as menu


#define KB_DN 0x51
#define KB_UP 0x52
#define KB_OK 0x28 // entree
#define KB_ESC 0x29

void redraw()
{
	// copy title
	memset(vram_title,'-',sizeof(vram_title)); // clear title
	int l = strlen(title);
	message("len %d\n",l);
	memcpy(vram_title+(DIALOG_W-l)/2,title,l);

	// copy items, with offset
	memset(vram,' ',sizeof(vram)); // clear screen
	const char *src=items;
	char *dst=&vram[0][0]; // start up left
	int  line=-offset;

	// skip offset lines
	while (*src && line<0) {
		if (*src++=='\n') line+=1;
	}

	while (*src) {
		if (*src=='\n') { // skip line ?
			if (line < DIALOG_H-1) {
				dst = &vram[1+line++][0];
			} else {
				break;
			}
		} else {
			*dst++ = *src;
		}
		src++;
	}
}

void dialog_keypress(struct event e)
{

	int old_offset=offset;

	if (callback) { // menu
		switch (e.kbd.key) {
			case KB_OK :
				dialog_quit();
				callback(select);
				break;

			case KB_UP :
				if (select>0)
					select--;
				if (select < offset)   // make it visible
					offset = select;
				break;

			case KB_DN :
				if ( select < nb_elements)
					select++;
				// make it visible
				if ( select >= offset+DIALOG_H )
					offset = select-DIALOG_H+1;

				break;
			case KB_ESC :
				// no callback
				dialog_quit();
				break;
		}
	} else { // text display : scroll, dismiss after OK
		switch(e.kbd.key) {
			case KB_OK :
			case KB_ESC :
				dialog_quit();
				break;
			case KB_UP :
				if (offset>0)
					offset--;
				break;
			case KB_DN :
				if (offset<nb_elements- DIALOG_H )
					offset++;
				break;
		}
	}

	message("redraw, ofs=%d sel=%d\n",offset,select);

	if (old_offset!=offset)
		redraw();
}


// animate decelerating menu window
void dialog_frame( void )
{
	pos_y += (pos_y_target - pos_y)/16;

	// move at least 1 in the right direction
	if (pos_y > pos_y_target) {
		 pos_y -= 1;
	} else if (pos_y < pos_y_target) {
		pos_y += 1;
	}

}

// blits a line of text on the screen. line = line of char
static inline void textline(char *dst, int line ,char *txt, char bg)
{
	for (int i=0;i<DIALOG_W;i++) {
		char c = FONT[(unsigned char)(txt[i]-' ')*8+(8-line)];

		for (int j=0;j<8;j++,c<<=1) {
			*dst++ = c&0x80 ? COL_BLACK:bg;
		}
	}
}

void dialog_drawline8()
{
	int line = vga_line-TOUR_V-pos_y; // relative line in dialog

	char *draw=((char*)draw_buffer) + TOUR_H + DIALOG_X; // where to draw

	if (line==-1) { // 3d border top
		memset(draw,COL_LIGHTGREY,DIALOG_W*8);
		draw[-1]=COL_WHITE;
		draw[DIALOG_W*8]=COL_MIDGREY;

	} else if (line==8*(DIALOG_H+1)) { // low 3D border
		memset(draw,COL_DARKGREY,DIALOG_W*8);
		draw[-1]=COL_MIDGREY;
		draw[DIALOG_W*8]=COL_BLACK;

	} else if (line>=0 && line <8*(DIALOG_H+1)) {
		if (line/8==0) { // title
			textline(draw,line%8, vram_title, BG_TITLE);
		} else { // text
			textline(draw,line%8,
				vram[line/8-1],
				(line/8==select-offset+1) ? BG_SELECTED : COL_MIDGREY
				);
		}

		// 3d borders L/R
		draw[-1]=COL_MIDGREY;
		draw[DIALOG_W*8]=COL_DARKGREY;
	}
}

// external interface
int dialog_active() {
	return pos_y_target!=POS_HIDDEN;
}


// initialise menu / text
void dialog_menu(const char *_title, const char *_items, void (*_callback)(int))
{
	title = _title;
	items = _items;
	callback=_callback;
	select=callback ? 0 : -1;
	offset=0;
	pos_y_target=8;

	// count number of lines
	nb_elements=0;
	while (*_items++) {
		if (*_items=='\n') nb_elements++;
	}

	redraw();
}

void dialog_quit()
{
	pos_y_target=POS_HIDDEN;
}
