#include "widgets.h"

NWText NWtext(int y, char* text) {
    NWText t = {
        .x      = 2,
        .y      = y,
        .width  = strlen(text),
        .height = 1,
        .text   = text,
    };
    return t;
}

void NWtext_display(NWText *w, WINDOW *stdscr) {
    mvaddstr(w->y, w->x, w->text);
}
