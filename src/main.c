#include <ncurses.h>

#include <stdlib.h>
#include <stdbool.h>

#include "widgets.h"
#include "stuff.h"

enum States {
    END,
    CONTINUE,
    NOTHING,
    DOWN,
    UP,
    CLICK,
};

enum States process_key() {
    int c;
    switch (c = getch()) {
        case KEY_BACKSPACE:
            return END;
        case KEY_UP:
            return UP;
        case KEY_DOWN:
            return DOWN;
        case 10:
        case KEY_ENTER:
            return CLICK;
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
    noecho();
    keypad(stdscr, true);

    // init widgets
    int yoff = 1;

    NWWidget header = NWwidget_new(yoff, "Hello!!", WHeader);
    yoff += header.height;

    NWWidget btn = NWwidget_new(yoff, "My Button", WButton);
    yoff += btn.height;

    NWWidget text = NWwidget_new(yoff, "Text!", WText);
    yoff += text.height;

    NWWidget toggles[5];
    for (int i=0; i<5; i++) {
        NWWidget tgl = NWwidget_new(yoff, "Toggle!", WToggle);
        yoff += tgl.height;
        tgl.pressed = true;
        toggles[i] = tgl;
    }

    // config widgets
    
    // add widgets
    Stuff s = Snew(&header);
    Sadd(&s, &btn);
    Sadd(&s, &text);
    for (int i=0; i<5; i++)
        Sadd(&s, &toggles[i]);

    // driver code
    while (true) {
        clear();
        Stick(&s);
        Sprint(&s, stdscr);
        switch (process_key()) {
            case END:
                goto end;
            case CONTINUE:
                continue;
            case NOTHING:
                break;
            case DOWN:
                Smove(&s, 1);
                break;
            case UP:
                Smove(&s, -1);
                break;
            case CLICK:
                Sclick(&s);
                break;
        };
        refresh();
        napms(25);
    }

    // end
    end:
    Sdelete(&s);
    echo();
    curs_set(true);
    nocbreak();
    endwin();
    return 0;
}
