#include "stuff.h"
#include "widgets.h"

Stuff* Snew(void *data, bool s) {
    Stuff *t = (Stuff *) malloc(sizeof(Stuff));
    t->widget = data;
    t->selected = s;
    t->next = NULL;
    return t;
}

void Sadd(Stuff *stuff, void *data) {
    Stuff *t = stuff;
    while (t->next != NULL)
        t = t->next;
    Stuff* new = Snew(data, false);
    t->next = new;
}

void Sprint(Stuff *stuff, WINDOW* stdscr) {
    Stuff *t = stuff;
    unsigned int c = 0;
    while (t->next != NULL) {
        if (t->selected) {
            int y = t->widget->y + ((float) (t->widget->height) / 2.0);
            mvaddch((int) y, 0, 'x');
        }
        NWWidget_display(t->widget, stdscr);
        c++;
        t = t->next;
    }
}

void Sdelete(Stuff *stuff) {
    if (stuff->next != NULL)
        Sdelete(stuff->next);
    stuff->next = NULL;
    free(stuff);
}
