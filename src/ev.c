#include "ev.h"

Event Emake_event() {
    Event e = {
        .type = No,
    };
    return e;
}
