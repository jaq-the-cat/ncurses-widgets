#include "widgets.h"

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
    mvaddstr(header->y, header->x, "---------");
    mvaddstr(header->y+1, header->x, header->text);
    mvaddstr(header->y+2, header->x, "---------");
}
