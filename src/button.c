#include "widgets.h"

NWButton NWbutton(int x, int y, char* text) {
    NWButton t = {
        .x      = x,
        .y      = y,
        .width  = strlen(text) + 4,
        .height = 1,
        .text   = text,
    };
    return t;
}
