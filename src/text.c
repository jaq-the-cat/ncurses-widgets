#include "widgets.h"
#include <string.h>

NWText NWtext(int x, int y, char* text, size_t text_len) {
    NWText t = {
        .x      = x,
        .y      = y,
        .width  = strlen(text) + 2,
        .height = 2,
        .text   = text,
    };
    return t;
}
