#include "widgets.h"

NWWidget NWwidget_new(unsigned int y, char* text, enum NWWidgetType type) {
    NWWidget w = {
        .x = 2,
        .y = y,
        .width = strlen(text) + 4,
        .height = 1,
        .text = text,
    };
    return w;
}

int get_extra_width(enum NWWidgetType type) {
    switch (type) {
        case WHeader:
            return 4;
        case WButton:
            return 4;
        case WToggle:
            return 4;
        default:
            return 0;
    }
}
