
#define DIALOG_X 80
#define DIALOG_W 25
#define DIALOG_H 8

// current dialog data
void dialog_quit();
void dialog_menu(char *_title, char *_items, void (*_callback)(int));


// interface with main loop & callbacks
void dialog_drawline8();
void dialog_keypress(struct event e);
void dialog_frame( void );
int dialog_active(); // is dialog active ?


void main_memnu(); // show main menu
