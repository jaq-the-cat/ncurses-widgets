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
    struct s_StuffNode *previous;
    struct s_StuffNode *next;
} StuffNode;

typedef struct {
    StuffNode *head;
    StuffNode *selected;
    int length;
    unsigned short yoff;
} Stuff;

enum States {
    END,
    CONTINUE,
    NOTHING,
    DOWN,
    UP,
    CLICK,
};

// Create a new list of widgets (stuff)
Stuff Snew(
    int // initial y offset
);

// Add widget to list
void Sadd(Stuff*, NWWidget*);

// Delete Stuff object
void Sdelete(Stuff*);

// Run the code
void Srun(Stuff*);

#endif
