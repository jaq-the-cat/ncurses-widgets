#pragma once

typedef struct {
    int x;
    int y;
    int width;
    int height;
    char* text;
} Header;

typedef struct {
    int x;
    int y;
    int width;
    int height;
    char* text;
} Text;

typedef struct {
    int x;
    int y;
    int width;
    int height;
    char* text;
    bool pressed;
} Button;

typedef struct {
    int x;
    int y;
    int width;
    int height;
    char* text;
    bool pressed;
} Toggle;
