
#define dialog_nb_lines 8
#define DIALOG_X 80
#define DIALOG_W 20
#define COL_WHITE 255
#define COL_LIGHTGREY 222
#define COL_MIDGREY 181
#define COL_DARKGREY 148
#define COL_BLACK 0

#define BG_TITLE 233 // bg title orange
#define BG_SELECTED 242 // bg selected - orange

#define EMPTY_LINE "...................." //"                    "
#define OK_LINE    "      [  OK  ]      "

#define FONT (mo5rom + 0xfc9e - 0xc000 -1) // mapping is NOT ascii !

enum DialogType {DialogNone, DialogText, DialogMenu};

struct Dialog {
	char* title;
	int nb_elements; // nb of elements in array
	char** elements; // array of strings

	enum DialogType type; // how the dialog is drawn and reacts to buttons

	int pos_y; // Y on screen position of window.
	int pos_y_target;

	int select; // selected option for menu
	int offset;

	void (*callback)(int); // not used for text
};


void dialog_quit();
void dialog_text(char *title, int nblines, char **lines);
void dialog_menu(char *title, int nbitems, char **items, void (*callback)(int));

void dialog_drawline8();
void dialog_buttonpress(struct event e);
void dialog_frame( void );

