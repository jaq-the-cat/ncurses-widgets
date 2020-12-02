#ifndef STUFF_H
#define STUFF_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ncurses.h>
#include "widgets.h"
#include "ev.h"

typedef struct s_StuffNode {
    NWWidget *widget;
    struct s_StuffNode *next;
} StuffNode;

typedef struct {
    StuffNode* head;
    StuffNode *selected;
    int length;
} Stuff;

enum States {
    END,
    CONTINUE,
    NOTHING,
    DOWN,
    UP,
    CLICK,
};

Stuff Snew(void*);
void Sadd(Stuff*, void*);
void Smove(Stuff*, int);
void Sclick(Stuff*);
void Sprint(Stuff*, WINDOW* stdscr);
void Sdelete(Stuff*);
void Stick(Stuff*);
void Srun(Stuff*, void (*)(Event*));

#endif
