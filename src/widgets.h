#ifndef WIDGETS_H
#define WIDGETS_H
#include <ncurses.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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
    char* text;
    enum NWWidgetType type;
    bool pressed;
} NWWidget;

NWWidget NWwidget_new(unsigned int, char*, enum NWWidgetType);

const char* str_repeat(char*, size_t);
#endif
