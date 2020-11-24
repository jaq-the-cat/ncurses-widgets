#include <ncurses.h>

#include <stdlib.h>
#include <stdbool.h>

#include "widgets.h"

enum States {
    END,
    CONTINUE,
    NOTHING
};

enum States process_key() {
    int c;
    switch (c = getch()) {
        case KEY_BACKSPACE:
            return END;
        default:
            break;
    }
    return NOTHING;
}

extern NWHeader NWheader_display(NWHeader *header, WINDOW *scr);

int main() {
    // setup ncurses
    initscr();
    cbreak();
    curs_set(false);
    keypad(stdscr, true);

    // init widgets
    NWHeader h = NWheader(1, 1, "Hello!!");

    // driver code
    while (true) {
        clear();
        mvaddstr(h.y, h.x, h.text);
        switch (process_key()) {
            case END:
                goto end;
            case CONTINUE:
                continue;
            case NOTHING:
                break;
        };
        refresh();
        napms(25);
    }


    // end
    end:
    curs_set(true);
    nocbreak();
    endwin();
    return 0;
}
