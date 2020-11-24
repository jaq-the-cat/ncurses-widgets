#include "widgets.h"

NWToggle NWtoggle(int x, int y, char* text) {
    NWToggle t = {
        .x      = 2,
        .y      = y,
        .width  = strlen(text) + 4,
        .height = 1,
        .text   = text,
    };
    return t;
}

void NWtoggle_display(NWToggle *w, WINDOW *stdscr) {
    char text[200] = "";
    strcat(text, "[");
    strcat(text, w->pressed ? "X" : " ");
    strcat(text, "] ");
    strcat(text, w->text);
    mvaddstr(w->y, w->x, text);
}
