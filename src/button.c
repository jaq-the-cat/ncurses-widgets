#include "widgets.h"

NWButton NWbutton(int x, int y, char* text) {
    NWButton t = {
        .x      = x,
        .y      = y,
        .width  = strlen(text) + 4,
        .height = 1,
        .text   = text,
    };
    return t;
}

void NWbutton_display(NWButton *w, WINDOW *stdscr) {
    char text[200] = "";
    strcat(text, "[ ");
    strcat(text, w->text);
    strcat(text, " ]");
    mvaddstr(w->y, w->x, text);
}
