#include "bitbox.h"

#define dialog_nb_lines 8

#define COL_WHITE 255
#define COL_LIGHTGREY 222
#define COL_MIDGREY 181
#define COL_DARKGREY 148
#define COL_BLACK 0

#define BG_TITLE 233 // bg title orange
#define BG_SELECTED 242 // bg selected - orange

#define EMPTY_LINE "...................." //"                    "
#define OK_LINE    "      [  OK  ]      "

#define FONT (rom_mo5+xxx)

enum DialogType {DialogNone, DialogText, DialogMenu};

struct Dialog {
	char* title;
	int nb_elements; // nb of elements in array
	char** elements; // array of strings

	enum DialogType type; // how the dialog si drawn and reacts to buttons

	int pos_y; // Y on screen position of window.
	int pos_y_target;

	int select; // selected option for menu
	int offset;

	(void *callback)(int); // not used for text
};


void dialog_quit();
void dialog_text(char *title, int nblines, char **lines);
void dialog_menu(char *title, int nbitems, char **items, (void *callback)(int));

void dialog_drawline8();
void dialog_buttonpress(int button);
void dialog_frame( void );


// -- snip --

static struct Dialog dialog;

// button : UDLRA, maybe emulated by KB.
void dialog_buttonpress(int button)
{

	switch (dialog.type) {
		case DialogNone :
			// do nothing
			break;

		case DialogText :
			switch(button) {
				case button_A :  hide_dialog(); break;
				case button_up : if (dialog.offset>0) dialog.offset--; break;
				case button_down : if (dialog.offsetdialog.nb_elements) dialog.offset++; break;
			}
			break;

		case DialogMenu :
			switch(button) {
				case button_A :
					dialog.callback(dialog.select);
					dialog_quit();
					break;

				case button_up :
					if (dialog.select>0)
						dialog.select--;
					if (dialog.select < dialog.offset)   // make it visible
						dialog.select = dialog.offset;
					break;

				case button_down :
					if ( dialog.select < nb_elements)
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
	for (int i=0;i<20;i++) {
		char c = FONT[txt[i]][line]];
		for (int j=0;j<8;j++,c<<=1)
			*dst++ = c&80 ? bg : COL_MIDGREY;
	}
}

void dialog_drawline8()
{
	int line = vga_line-BORD_H-dialog.pos_y; // relative line in dialog

	char *draw=((char*)draw_buffer) + BORD_W; // where to draw

	if (line==-1) { // 3d border top
		memset(draw,DIALOG_W*8,COL_LIGHTGREY);
		draw[-1]=COL_WHITE;
		draw[DIALOG_W+1]=COL_MIDGREY;

	} else if (line==8*(dialog_nb_lines+1)+1) { // low 3D border
		memset(draw,DIALOG_W*8,COL_DARKGREY);
		draw[-1]=COL_MIDGREY;
		draw[DIALOG_W*8+1]=COL_BLACK;

	} else {
		// in-window
		if (line/8==0) { // title
			textline(draw,line%8, dialog.title, BG_TITLE);
		} else {
			textline(draw,line%8,
				line/8<dialog.nblines ? dialog.elements[line/8] : EMPTY_LINE,
				line/8==selected-offset ? BG_SELECTED : COL_MIDGREY
				);
		}

		// 3d borders L/R
		draw[-1]=COL_MIDGREY;
		draw[DIALOG_W*8+1]=COL_DARKGREY;
	}
}

// initiates a dialog of type text
void dialog_text(char *title, int nblines, char **lines)
{
	// adds a last line with 'ok', select it
	dialog.title=title;
	dialog.nblines=nblines+1;
	for (int i=0;i<nblines;i++)
		dialog.elements[i]=lines[i];
	dialog.elements[nblines]=OK_LINE;
	dialog.type=DialogText;
	dialog.select=nblines;
	dialog.offset=0;
}

// initialise menu
void dialog_menu(char *title, int nbitems, char **items, (void *callback)(int))
{
	dialog.title=title;
	dialog.nblines=nbitems;
	for (int i=0;i<nblines;i++)
		dialog.elements[i]=items[i];
	dialog.callback=callback;
	dialog.select=0;
	dialog.offset=0;
}

void dialog_quit()
{
	dialog.type=0;
	dialog.pos_y_target=-100;
}
