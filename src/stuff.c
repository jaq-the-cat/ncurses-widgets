#include "stuff.h"

Stuff Snew(void *data, bool s) {
    Stuff t = {
        data, // widget
        s, // selected
        NULL // next
    };
    return t;
}

void Sadd(Stuff *stuff, void *data) {
    Stuff *t = stuff;
    while (t->next != NULL)
        t = t->next;
    Stuff* new = malloc(sizeof(Stuff));
    *new = Snew(data, false);
    t->next = new;
}

void Sprint(Stuff *stuff) {
    Stuff *t = stuff;
    unsigned int c = 0;
    while (t->next != NULL) {
        printf("widget %d\n", c);
        c++;
        t = t->next;
    }
    printf("widget %d\n", c);
}

void Sdelete(Stuff *stuff) {
    if (stuff->next != NULL)
        Sdelete(stuff->next);
    free(stuff);
}
