#ifndef WIDGETS_H
#define WIDGETS_H
#include <ncurses.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "ev.h"

enum NWWidgetType {
    WHeader,
    WButton,
    WToggle,
    WText,
};

typedef struct {
    int x;
    int y;
    int width;
    int height;
    int bottom;
    char *text;
    enum NWWidgetType type;
    bool pressed;
    void (*handler)(Event*);
} NWWidget;

NWWidget NWwidget_new(
    char*, // content
    enum NWWidgetType, // type
    int, // bottom padding
    void (*)(Event*) // event handler
);
#endif
