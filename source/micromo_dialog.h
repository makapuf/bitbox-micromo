
#define DIALOG_X 80
#define DIALOG_W 25
#define DIALOG_H 8

// Main interface
void dialog_quit();

/* shows a text or a menu
 title : string with title, <DIALOG_W chars
 items : \n separated list of items.
 callback to call when menu has been selected. set to NULL to show simple text.
*/
void dialog_menu(char *_title, char *_items, void (*_callback)(int));


// interface with main loop & callbacks
void dialog_drawline8();
void dialog_keypress(struct event e);
void dialog_frame( void );
int dialog_active(); // is dialog active ?


