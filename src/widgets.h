#pragma once
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int x;
    int y;
    int width;
    int height;
    char* text;
} NWHeader;

NWHeader NWheader(int, int, char*, size_t);

typedef struct {
    int x;
    int y;
    int width;
    int height;
    char* text;
} NWText;

NWText NWtext(int, int, char*, size_t);

typedef struct {
    int x;
    int y;
    int width;
    int height;
    char* text;
    bool pressed;
} NWButton;

NWButton NWbutton(int, int, char*, size_t);

typedef struct {
    int x;
    int y;
    int width;
    int height;
    char* text;
    bool pressed;
} NWToggle;

NWToggle NWtoggle(int, int, char*, size_t);
