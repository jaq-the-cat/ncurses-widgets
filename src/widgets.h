#pragma once
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

const char* str_repeat(char* str, size_t times)
{
    if (times < 1) return NULL;
    char *ret = (char *) (malloc(sizeof(str) * times + 1));
    if (ret == NULL) return NULL;
    strcpy(ret, str);
    while (--times > 0) {
        strcat(ret, str);
    }
    return ret;
}

