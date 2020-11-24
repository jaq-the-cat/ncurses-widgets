#include "widgets.h"
#include <string.h>

NWHeader NWheader(int x, int y, char* text, size_t text_len) {
    NWHeader t = {
        .x      = x,
        .y      = y,
        .width  = strlen(text) + 4,
        .height = 3,
        .text   = text,
    };
    return t;
}
