#include "widgets.h"

static const int dimensions[][2] = { // extra width, height
    {4, 3}, // WHeader
    {4, 1}, // WButton
    {4, 1}, // WToggle
    {0, 1}, // WText
};

static int get_extra_width(enum NWWidgetType type) {
    return dimensions[type][0];
}

static int get_height(enum NWWidgetType type) {
    return dimensions[type][1];
}

NWWidget NWwidget_new(char* text, enum NWWidgetType type, int bottom, void (*handler)(Event*)) {
    NWWidget w = {
        .x = 2,
        .y = 0,
        .width = strlen(text) + get_extra_width(type),
        .height = get_height(type),
        .bottom = bottom,
        .text = text,
        .pressed = false,
        .type = type,
        .handler = handler,
    };
    return w;
}
