#include "widgets.h"

NWText NWtext(int x, int y, char* text) {
    NWText t = {
        .x      = x,
        .y      = y,
        .width  = strlen(text) + 1,
        .height = 2,
        .text   = text,
    };
    return t;
}

void NWtext_display(NWText *w, WINDOW *stdscr) {
    const char* line = str_repeat("-", w->width);
    mvaddstr(w->y, w->x, w->text);
    mvaddstr(w->y+1, w->x, line);
}
