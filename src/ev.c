#include "ev.h"

Event Emake_event() {
    Event e = {
        .type = No,
        .source = NULL,
    };
    return e;
}
