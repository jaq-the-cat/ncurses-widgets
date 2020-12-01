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
    Stuff *t = NULL;
    while (stuff->next != NULL) {

    }
}
