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
} NWHeader;

NWHeader NWheader(int, int, char*);
void NWheader_display(NWHeader*, WINDOW*);

typedef struct {
    int x;
    int y;
    int width;
    int height;
    char* text;
} NWText;

NWText NWtext(int, int, char*);
void NWtext_display(NWText*, WINDOW*);

typedef struct {
    int x;
    int y;
    int width;
    int height;
    char* text;
    bool pressed;
} NWButton;

NWButton NWbutton(int, int, char*);
void NWbutton_display(NWButton*, WINDOW*);

typedef struct {
    int x;
    int y;
    int width;
    int height;
    char* text;
    bool pressed;
} NWToggle;

NWToggle NWtoggle(int, int, char*);
void NWtoggle_display(NWToggle*, WINDOW*);

const char* str_repeat(char*, size_t);
#endif
