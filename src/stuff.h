#ifndef STUFF_H
#define STUFF_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ncurses.h>
#include "widgets.h"

typedef struct s_Stuff {
    NWWidget *widget;
    int selected;
    struct s_Stuff *next;
} Stuff;

Stuff* Snew(void*, int);
void Sadd(Stuff*, void*);
void Sprint(Stuff*, WINDOW* stdscr);
void Sdelete(Stuff*);

#endif
