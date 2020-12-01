#include "stuff.h"

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
    printf("Sdelete()\n");
    if (stuff->next != NULL) {
        printf("delet\n");
        Sdelete(stuff->next);
    }
    printf("fre\n");
    free(stuff);
}
