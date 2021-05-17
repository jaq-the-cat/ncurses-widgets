#include <ncurses.h>

#include <stdlib.h>
#include <stdbool.h>

#include "widgets.h"
#include "stuff.h"

void handler(Event *ev) {
    mvprintw(0, 0, "Asasdkaslkfnsajkgbajkthk lm,fhsflkhKHDJKAFHAFHJWKD");
}

int main() {
    // setup ncurses
    initscr();
    cbreak();
    curs_set(false);
    noecho();
    nodelay(stdscr, true);
    keypad(stdscr, true);

    // init widgets
    NWWidget header = NWwidget_new("Hello!!", WHeader, 2, NULL);
    NWWidget btn = NWwidget_new("My Button", WButton, 2, handler);
    NWWidget text = NWwidget_new("Text!", WText, 0, NULL);
    NWWidget toggles[5];
    for (int i=0; i<5; i++) {
        NWWidget tgl = NWwidget_new("Toggle!", WToggle, 0, handler);
        toggles[i] = tgl;
    }

    // config widgets

    // add widgets
    Stuff s = Snew(&header);
    Sadd(&s, &btn);
    Sadd(&s, &text);
    for (int i=0; i<5; i++)
        Sadd(&s, &toggles[i]);

    // mainloop
    Srun(&s);

    return 0;
}
