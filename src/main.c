#include <ncurses.h>

#include <stdlib.h>
#include <stdbool.h>

#define SCR stdscr

int main() {
    initscr();
    clear();

    addstr("Hello, ncurses!");
    getch();

    refresh();
    endwin();
    return 0;
}
