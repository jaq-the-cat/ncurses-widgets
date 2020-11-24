#include "widgets.h"
#include <string.h>
#include <ncurses.h>

NWHeader NWheader(int x, int y, char* text) {
    NWHeader t = {
        .x      = x,
        .y      = y,
        .width  = strlen(text) + 4,
        .height = 3,
        .text   = text,
    };
    return t;
}

void NWheader_display(NWHeader *header, WINDOW *stdscr) {
    mvaddstr(header->y, header->y, header->text);
}
