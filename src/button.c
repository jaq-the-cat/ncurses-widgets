#include "widgets.h"
#include <string.h>

NWButton NWbutton(int x, int y, char* text, size_t text_len) {
    NWButton t = {
        .x      = x,
        .y      = y,
        .width  = strlen(text) + 4,
        .height = 1,
        .text   = text,
    };
    return t;
}
