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
    NWHeader h = NWheader(yoff, "Hello!!");
    yoff += h.height;
    NWButton b = NWbutton(yoff, "My Button");
    yoff += b.height;
    NWText t = NWtext(yoff, "Text!");
    yoff += t.height;
    NWToggle tgl = NWtoggle(yoff, "Toggle!");
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
