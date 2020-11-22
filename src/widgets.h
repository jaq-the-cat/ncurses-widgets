#pragma once

typedef struct {
    int x;
    int y;
    int width;
    int height;
    char* text;
} NWHeader;

NWHeader NWheader();

typedef struct {
    int x;
    int y;
    int width;
    int height;
    char* text;
} NWText;

NWText NWtext();

typedef struct {
    int x;
    int y;
    int width;
    int height;
    char* text;
    bool pressed;
} NWButton;

NWButton NWbutton();

typedef struct {
    int x;
    int y;
    int width;
    int height;
    char* text;
    bool pressed;
} NWToggle;

NWToggle NWtoggle();
