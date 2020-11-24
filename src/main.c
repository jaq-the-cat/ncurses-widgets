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
    int yoff = 1;
    NWHeader h = NWheader(0, yoff, "Hello!!");
    yoff += h.height;
    NWButton b = NWbutton(0, yoff, "My Button");
    yoff += b.height;
    NWText t = NWtext(0, yoff, "Text!");
    yoff += t.height;
    NWToggle tgl = NWtoggle(0, yoff, "Toggle!");
    tgl.pressed = true;
    yoff += tgl.height;

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
