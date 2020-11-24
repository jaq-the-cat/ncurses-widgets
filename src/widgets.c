#include "widgets.h"
#include <string.h>

NWHeader NWheader(int x, int y, char* text, size_t text_len) {
    NWHeader h = {
        .x = x,
        .y = y,
        strlen(text) + 4,
        3,
        text,
    };
    return h;
}

NWText NWtext(int x, int y, char* text, size_t text_len) {

}

NWButton NWbutton(int x, int y, char* text, size_t text_len) {

}

NWToggle NWtoggle(int x, int y, char* text, size_t text_len) {

}
