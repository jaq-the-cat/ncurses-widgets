#include "stuff.h"
#include "widgets.h"
#include "ev.h"

Stuff Snew(void *data) {
    StuffNode *t = malloc(sizeof(StuffNode));
    t->widget = data;
    t->next = NULL;
    Stuff st = {
        .head = t,
        .selected = t,
        .length = 0,
    };
    return st;
}

StuffNode* _Snew_node(void *data) {
    StuffNode *t = malloc(sizeof(StuffNode));
    t->widget = data;
    t->next = NULL;
    return t;
}

void Sadd(Stuff *stuff, void *data) {
    StuffNode *t = stuff->head;
    while (t->next != NULL)
        t = t->next;
    StuffNode *new = _Snew_node(data);
    t->next = new;
    stuff->length += 1;
}

void Smove(Stuff *stuff, int d) {
    stuff->selected = stuff->selected->next;
}

void Sclick(Stuff *stuff) {
    stuff->selected->widget->pressed = !(stuff->selected->widget->pressed);
}

void Sprint(Stuff *stuff, WINDOW* stdscr) {
    StuffNode *t = stuff->head;
    for (int c=0; t != NULL; c++, t = t->next) {
        if (c == stuff->selected) {
            int y = t->widget->y;
            if (t->widget->height > 1)
                 y += (float) (t->widget->height) / 2.0;
            mvaddch((int) y, 0, 'x');
        }
        NWWidget_display(t->widget, stdscr);
    }
}

void _Sdelete_node(StuffNode *node) {
    if (node->next != NULL)
        _Sdelete_node(node->next);
    node->next = NULL;
    free(node);
}

void Sdelete(Stuff *stuff) {
    _Sdelete_node(stuff->head);
}

void Sclear_buttons(Stuff* stuff) {
    StuffNode *t = stuff->head;
    for (int c=0; t != NULL; c++, t = t->next) {
        if (t->widget->type == WButton && t->widget->pressed)
            t->widget->pressed = false;
    }
}

void Stick(Stuff* stuff) {
    static int n = 0;
    if (n > 10) {
        n = 0;
        Sclear_buttons(stuff);
    } else
        n++;
}

enum States process_key() {
    int c;
    switch (c = getch()) {
        case KEY_BACKSPACE:
            return END;
        case KEY_UP:
            return UP;
        case KEY_DOWN:
            return DOWN;
        case 10:
        case KEY_ENTER:
            return CLICK;
        default:
            break;
    }
    return NOTHING;
}

void Srun(Stuff* stuff, void (*handler)(Event*)) {
    initscr();
    cbreak();
    curs_set(false);
    noecho();
    nodelay(stdscr, true);
    keypad(stdscr, true);

    while (true) {
        clear();
        Stick(stuff);
        Sprint(stuff, stdscr);
        Event e = Emake_event();
        switch (process_key()) {
            case END:
                goto end;
            case CONTINUE:
                continue;
            case NOTHING:
                break;
            case DOWN:
                Smove(stuff, 1);
                break;
            case UP:
                Smove(stuff, -1);
                break;
            case CLICK:
                (*handler)(&e);
                Sclick(stuff);
                break;
        };
        refresh();
        napms(25);
    }

    end:
    Sdelete(stuff);
    echo();
    curs_set(true);
    nocbreak();
    endwin();
}
