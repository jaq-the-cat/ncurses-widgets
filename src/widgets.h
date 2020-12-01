#ifndef WIDGETS_H
#define WIDGETS_H
#include <ncurses.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int x;
    int y;
    int width;
    int height;
    char* text;
} NWWidget;

enum NWWidgetType {
    WHeader,
    WButton,
    WToggle,
    WText,
};

NWWidget NWwidget_new(unsigned int, char*, NWWidgetType);

const char* str_repeat(char*, size_t);
#endif
