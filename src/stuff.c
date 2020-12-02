#include "stuff.h"
#include "widgets.h"

Stuff Snew(void *data) {
    StuffNode *t = malloc(sizeof(StuffNode));
    t->widget = data;
    t->next = NULL;
    Stuff st = {
        .head = t,
    };
    return st;
}

StuffNode* _Snew_node(void *data) {
    StuffNode *t = malloc(sizeof(StuffNode));
    t->widget = data;
    t->next = NULL;
    return t;
}

void Sadd(Stuff *stuff, void *data) {
    StuffNode *t = stuff->head;
    while (t->next != NULL)
        t = t->next;
    StuffNode *new = _Snew_node(data);
    t->next = new;
    stuff->length += 1;
}

void Smove(Stuff *stuff, int d) {
    int new_i = stuff->selected + d;
    if (new_i < 0) new_i = 0;
    else if (new_i >= stuff->length) new_i = stuff->length-1;
    stuff->selected = new_i;
}

void Sprint(Stuff *stuff, WINDOW* stdscr) {
    StuffNode *t = stuff->head;
    for (int c=0; t->next != NULL; c++, t = t->next) {
        if (c == stuff->selected) {
            int y = t->widget->y;
            if (t->widget->height > 1)
                 y += (float) (t->widget->height) / 2.0;
            mvaddch((int) y, 0, 'x');
        }
        NWWidget_display(t->widget, stdscr);
    }
}

void _Sdelete_node(StuffNode *node) {
    if (node->next != NULL)
        _Sdelete_node(node->next);
    node->next = NULL;
    free(node);
}

void Sdelete(Stuff *stuff) {
    _Sdelete_node(stuff->head);
}
