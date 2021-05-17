#ifndef EV_H
#define EV_H

enum EventType {
    ButtonPress,
    ToggleOn,
    ToggleOff,
    No,
};

typedef struct s_Event {
    enum EventType type;
} Event;

Event Emake_event();

#endif
