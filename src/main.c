#include <ncurses.h>

#include <stdlib.h>
#include <stdbool.h>

#define ss stdscr

int main() {
    // setup ncurses
    initscr();
    cbreak();
    curs_set(false);
    keypad(ss, true);

    // driver code
    clear();

    addstr("Hello, ncurses!"); 
    getch();

    refresh();

    // end
    curs_set(true);
    nocbreak();
    endwin();
    return 0;
}
