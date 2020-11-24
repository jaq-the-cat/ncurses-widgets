#include "widgets.h"
#include <string.h>

NWToggle NWtoggle(int x, int y, char* text) {
    NWToggle t = {
        .x      = x,
        .y      = y,
        .width  = strlen(text) + 4,
        .height = 1,
        .text   = text,
    };
    return t;
}
