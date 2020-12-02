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
    char *text;
    enum NWWidgetType type;
    bool pressed;
} NWWidget;

NWWidget NWwidget_new(unsigned int, char*, enum NWWidgetType);

void NWheader_display(NWWidget*, WINDOW*);
void NWbutton_display(NWWidget*, WINDOW*);
void NWtext_display(NWWidget*, WINDOW*);
void NWtoggle_display(NWWidget*, WINDOW*);
void NWWidget_display(NWWidget*, WINDOW*);

const char* str_repeat(char*, size_t);
#endif
