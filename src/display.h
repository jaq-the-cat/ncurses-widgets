#ifndef DISPLAY_H
#define DISPLAY_H
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include "widgets.h"

void NWheader_display(NWWidget*, WINDOW*);
void NWbutton_display(NWWidget*, WINDOW*);
void NWtext_display(NWWidget*, WINDOW*);
void NWtoggle_display(NWWidget*, WINDOW*);
void NWWidget_display(NWWidget*, WINDOW*);

const char* str_repeat(char*, size_t);
#endif
