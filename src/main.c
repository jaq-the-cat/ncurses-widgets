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
    NWWidget h = NWwidget_new(yoff, "Hello!!", WHeader);
    yoff += h.height;
    Stuff s = Snew(&h);

    NWWidget b = NWwidget_new(yoff, "My Button", WButton);
    yoff += b.height;
    Sadd(&s, &b);

    NWWidget t = NWwidget_new(yoff, "Text!", WText);
    yoff += t.height;
    Sadd(&s, &t);

    NWWidget tgl = NWwidget_new(yoff, "Toggle!", WToggle);
    tgl.pressed = true;
    yoff += tgl.height;

    Sadd(&s, &tgl);

    // driver code
    while (true) {
        clear();
        Sprint(&s, stdscr);
        char st[10];
        sprintf(st, "%d", s.selected);
        mvaddstr(40, 0, st);
        switch (process_key()) {
            case END:
                goto end;
            case CONTINUE:
                continue;
            case NOTHING:
                break;
            case DOWN:
                s.selected += 1;
                break;
            case UP:
                s.selected -= 1;
                break;
        };
        refresh();
        napms(25);
    }

    // end
    end:
    Sdelete(&s);
    curs_set(true);
    nocbreak();
    endwin();
    return 0;
}
