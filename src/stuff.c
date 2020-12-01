#include "stuff.h"

Stuff Snew(void *data) {
    Stuff t = {
        data, // widget
        true, // selected
        NULL // next
    };
    return t;
}

void Sadd(Stuff *stuff, void *data) {
    Stuff *t = stuff;
    while (t->next != NULL) {
        t = t->next;
    }
    t->next = data;
}
