#include "widgets.h"
#include <string.h>

NWHeader NWheader(char* text, size_t text_len) {
    NWHeader h = {
        .x = 0,
        .y = 0,
        strlen(text) + 4,
        3,
        text,
    };
    return h;
}

NWText NWtext(char* text, size_t text_len) {

}

NWButton NWbutton(char* text, size_t text_len) {

}

NWToggle NWtoggle(char* text, size_t text_len) {

}
