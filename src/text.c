#include "widgets.h"

NWText NWtext(int x, int y, char* text) {
    NWText t = {
        .x      = x,
        .y      = y,
        .width  = strlen(text) + 2,
        .height = 2,
        .text   = text,
    };
    return t;
}
