#include "widgets.h"

int get_extra_width(enum NWWidgetType type) {
    return dimensions[type][0];
}

int get_height(enum NWWidgetType type) {
    return dimensions[type][1];
}

NWWidget NWwidget_new(char* text, enum NWWidgetType type) {
    NWWidget w = {
        .x = 2,
        .y = 0,
        .width = strlen(text) + get_extra_width(type),
        .height = get_height(type),
        .text = text,
        .pressed = false,
        .type = type,
    };
    return w;
}
