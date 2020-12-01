#ifndef STUFF_H
#define STUFF_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct s_Stuff {
    void *widget;
    bool selected;
    struct s_Stuff *next;
} Stuff;

Stuff Snew(void*, bool);
void Sadd(Stuff*, void*);
void Sprint(Stuff*);

#endif
