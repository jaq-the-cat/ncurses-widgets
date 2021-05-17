#include "display.h"

void NWheader_display(NWWidget *header, WINDOW *stdscr) {
    const char* line = str_repeat("-", header->width);
    char text[200] = "";
    strcat(text, "| ");
    strcat(text, header->text);
    strcat(text, " |");
    mvaddstr(header->y, header->x, line);
    mvaddstr(header->y+1, header->x, text);
    mvaddstr(header->y+2, header->x, line);
    free((void *) line);
}

void NWbutton_display(NWWidget *w, WINDOW *stdscr) {
    char text[200] = "";
    if (w->pressed == false) {
        strcat(text, "[ ");
        strcat(text, w->text);
        strcat(text, " ]");
    } else {
        strcat(text, "{ ");
        strcat(text, w->text);
        strcat(text, " }");
    }
    mvaddstr(w->y, w->x, text);
}

void NWtext_display(NWWidget *w, WINDOW *stdscr) {
    mvaddstr(w->y, w->x, w->text);
}

void NWtoggle_display(NWWidget *w, WINDOW *stdscr) {
    char text[200] = "";
    strcat(text, "[");
    strcat(text, w->pressed ? "X" : " ");
    strcat(text, "] ");
    strcat(text, w->text);
    mvaddstr(w->y, w->x, text);
}

void NWWidget_display(NWWidget *w, WINDOW *stdscr) {
    switch (w->type) {
        case WHeader:
            NWheader_display(w, stdscr);
            break;
        case WButton:
            NWbutton_display(w, stdscr);
            break;
        case WToggle:
            NWtoggle_display(w, stdscr);
            break;
        case WText:
            NWtext_display(w, stdscr);
            break;
    }
}
