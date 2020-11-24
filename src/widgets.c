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

NWToggle NWtoggle(int x, int y, char* text, size_t text_len) {

}
