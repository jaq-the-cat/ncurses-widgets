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

int main() {
    // setup ncurses
    initscr();
    cbreak();
    curs_set(false);
    keypad(stdscr, true);

    // init widgets
    NWHeader h = NWheader(1, 1, "Hello!!");
    NWButton b = NWbutton(1, h.y + h.height + 1, "My Button");
    NWText t = NWtext(1, 15, "Text!");
    NWToggle tgl = NWtoggle(1, 10, "Toggle!");
    tgl.pressed = true;

    // driver code
    while (true) {
        clear();
        NWheader_display(&h, stdscr);
        NWbutton_display(&b, stdscr);
        NWtext_display(&t, stdscr);
        NWtoggle_display(&tgl, stdscr);
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
