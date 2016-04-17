#include <string.h>

#include "bitbox.h"
#include "dcmo5.h"
#include "micromo_dialog.h"

// color : bg menu dark title, hauteur differente selon menu, semi trans ?  ...

static struct Dialog dialog;
char *dialog_items[dialog_nb_lines];

#define KB_DN 0x51
#define KB_UP 0x52
#define KB_OK 0x28 // entree

void dialog_buttonpress(struct event e)
{

	switch (dialog.type) {
		case DialogNone :
			// do nothing
			break;

		case DialogText :
			switch(e.kbd.key) {
				case KB_OK :
					dialog_quit();
					break;
				case KB_UP :
					if (dialog.offset>0)
						dialog.offset--;
					break;
				case KB_DN :
					if (dialog.offset<dialog.nb_elements)
						dialog.offset++;
					break;
			}
			break;

		case DialogMenu :
			switch(e.kbd.key) {
				case KB_OK :
					dialog.callback(dialog.select);
					dialog_quit();
					break;

				case KB_UP :
					if (dialog.select>0)
						dialog.select--;
					if (dialog.select < dialog.offset)   // make it visible
						dialog.select = dialog.offset;
					break;

				case KB_DN :
					if ( dialog.select < dialog.nb_elements)
						dialog.select++;
					if ( dialog.select > dialog.offset+dialog_nb_lines ) // make it visible
						dialog.select = dialog.offset+dialog_nb_lines;
					break;
			}
			break;
	}
	//
}


// animate decelerating menu window
void dialog_frame( void )
{
	dialog.pos_y += (dialog.pos_y_target - dialog.pos_y)/16;

	// move at least 1 in the right direction
	if (dialog.pos_y > dialog.pos_y_target) {
		 dialog.pos_y -= 1;
	} else if (dialog.pos_y < dialog.pos_y_target) {
		dialog.pos_y += 1;
	}

}

// blits a line of text on the screen. line = line of char
static inline void textline(char *dst, int line ,char *txt, char bg)
{
	for (int i=0;i<DIALOG_W;i++) {
		char c = FONT[(unsigned char)(txt[i]-' ')*8+(8-line)];

		for (int j=0;j<8;j++,c<<=1) {
			*dst &= 0xaa;
			*dst++ |= c&0x80 ? COL_BLACK:bg;
		}
	}
}

void dialog_drawline8()
{
	int line = vga_line-TOUR_V-dialog.pos_y; // relative line in dialog

	char *draw=((char*)draw_buffer) + TOUR_H + DIALOG_X; // where to draw

	if (line==-1) { // 3d border top
		memset(draw,COL_LIGHTGREY,DIALOG_W*8);
		draw[-1]=COL_WHITE;
		draw[DIALOG_W*8]=COL_MIDGREY;

	} else if (line==8*(dialog_nb_lines+1)) { // low 3D border
		memset(draw,COL_DARKGREY,DIALOG_W*8);
		draw[-1]=COL_MIDGREY;
		draw[DIALOG_W*8]=COL_BLACK;

	} else if (line>=0 && line <8*(dialog_nb_lines+1)) {
		// in-window
		if (line/8==0) { // title
			textline(draw,line%8, dialog.title, BG_TITLE);
		} else {
			textline(draw,line%8,
				(line/8<dialog.nb_elements) ? dialog.elements[line/8] : EMPTY_LINE,
				(line/8==dialog.select-dialog.offset) ? BG_SELECTED : COL_MIDGREY
				);
		}

		// 3d borders L/R
		draw[-1]=COL_MIDGREY;
		draw[DIALOG_W*8]=COL_DARKGREY;
	}
}

// initiates a dialog of type text
void dialog_text(char *title, int nblines, char **lines)
{
	// adds a last line with 'ok', select it
	dialog.title=title;
	dialog.nb_elements=nblines+1;
	// blit it with chars, better
	dialog.elements = dialog_items;
	for (int i=0;i<nblines;i++)
		dialog.elements[i]=lines[i];
	dialog.elements[nblines]=OK_LINE;
	dialog.type=DialogText;
	dialog.select=nblines;
	dialog.offset=0;
	dialog.pos_y_target=8;

	dialog.pos_y=-100; // for starter !

}

// initialise menu
void dialog_menu(char *title, int nbitems, char **items, void (*callback)(int))
{
	dialog.title=title;
	dialog.nb_elements=nbitems;
	dialog.elements = dialog_items;
	for (int i=0;i<nbitems;i++)
		dialog.elements[i]=items[i];
	dialog.callback=callback;
	dialog.select=0;
	dialog.offset=0;
	dialog.pos_y_target=8;
}

void dialog_quit()
{
	dialog.type=0;
	dialog.pos_y_target=-100;
}
