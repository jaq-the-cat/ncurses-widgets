#include <ncurses.h>

#include <stdlib.h>
#include <stdbool.h>

#include "widgets.h"
#include "stuff.h"

void event_handler(Event* e) {
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

    NWWidget header = NWwidget_new("Hello!!", WHeader);
    NWWidget btn = NWwidget_new("My Button", WButton);
    NWWidget text = NWwidget_new("Text!", WText);
    NWWidget toggles[5];
    for (int i=0; i<5; i++) {
        NWWidget tgl = NWwidget_new("Toggle!", WToggle);
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
    Srun(&s, event_handler);

    return 0;
}
