#include <ncurses.h>

#include <stdlib.h>
#include <stdbool.h>

#define SCR stdscr

int main() {
    // setup ncurses
    initscr();
    nocbreak();
    curs_set(false);

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
