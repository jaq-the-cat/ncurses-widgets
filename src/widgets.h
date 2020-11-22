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

NWHeader NWheader(char* text, size_t text_len);

typedef struct {
    int x;
    int y;
    int width;
    int height;
    char* text;
} NWText;

NWText NWtext(char* text, size_t text_len);

typedef struct {
    int x;
    int y;
    int width;
    int height;
    char* text;
    bool pressed;
} NWButton;

NWButton NWbutton(char* text, size_t text_len);

typedef struct {
    int x;
    int y;
    int width;
    int height;
    char* text;
    bool pressed;
} NWToggle;

NWToggle NWtoggle(char* text, size_t text_len);
