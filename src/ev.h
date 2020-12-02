#ifndef EV_H
#define EV_H

#include "widgets.h"

enum EventType {
    ButtonPress,
    ToggleOn,
    ToggleOff,
    No,
};

typedef struct s_Event {
    enum EventType type;
    NWWidget *source;
} Event;

Event Emake_event() {
    Event e = {
        .type = No,
        .source = NULL,
    };
    return e;
}

#endif
