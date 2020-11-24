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
    const char* line = str_repeat("-", header->width);
    char* text = "";
    text = strcat(text, "/ ");
    text = strcat(text, header->text);
    text = strcat(text, " /");
    mvaddstr(header->y, header->x, line);
    mvaddstr(header->y+1, header->x, text);
    mvaddstr(header->y+2, header->x, line);
    free((void *) line);
    /*free((void *) text);*/
}
