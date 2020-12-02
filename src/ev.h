#ifndef EV_H
#define EV_H

#include "widgets.h"

enum EventType {
    ButtonPress,
    ToggleOn,
    ToggleOff
};

typedef struct s_Events {
    enum EventType type;
    NWWidget *source;
} Events;

#endif
