#include "stuff.h"
#include "display.h"
#include "ev.h"

// Create a new list of widgets (stuff)
Stuff Snew(NWWidget *data) {
    StuffNode *t = malloc(sizeof(StuffNode));
    t->widget = data;
    t->previous = NULL;
    t->next = NULL;
    Stuff st = {
        .head = t,
        .selected = t,
        .length = 0,
        .yoff = 1,
    };
    data->y = st.yoff;
    st.yoff += data->height;
    return st;
}

// Add new node
static StuffNode* Snew_node(StuffNode *curr, void *data) {
    StuffNode *t = malloc(sizeof(StuffNode));
    t->widget = data;
    t->previous = curr;
    t->next = NULL;
    return t;
}

// Add widget to list
void Sadd(Stuff *stuff, NWWidget *data) {
    StuffNode *t = stuff->head;
    while (t->next != NULL)
        t = t->next;
    StuffNode *new = Snew_node(t, data);
    t->next = new;
    stuff->length += 1;
    data->y = stuff->yoff;
    stuff->yoff += data->height;
}

// Move cursor
void Smove(Stuff *stuff, int d) {
    if (d < 0) {
        if (stuff->selected->previous != NULL)
            stuff->selected = stuff->selected->previous;
    }
    else if (d > 0) {
        if (stuff->selected->next != NULL)
            stuff->selected = stuff->selected->next;
    }
}

// Click widget
void Sclick(Stuff *stuff) {
    stuff->selected->widget->pressed ^= true;
}

// Print widget
void Sprint(Stuff *stuff, WINDOW* stdscr) {
    StuffNode *t = stuff->head;
    for (; t != NULL; t = t->next) {
        if (t == stuff->selected) {
            int y = t->widget->y;
            if (t->widget->height > 1)
                 y += (float) (t->widget->height) / 2.0;
            mvaddch((int) y, 0, 'x');
        }
        NWWidget_display(t->widget, stdscr);
    }
}

// Delete node
static void Sdelete_node(StuffNode *node) {
    if (node->next != NULL)
        Sdelete_node(node->next);
    node->next = NULL;
    free(node);
}

// Delete list
void Sdelete(Stuff *stuff) {
    Sdelete_node(stuff->head);
}

// Clear buttons (set pressed to false)
void Sclear_buttons(Stuff* stuff) {
    StuffNode *t = stuff->head;
    for (int c=0; t != NULL; c++, t = t->next) {
        if (t->widget->type == WButton && t->widget->pressed)
            t->widget->pressed = false;
    }
}

// Tick
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

static enum EventType get_event_type(Stuff *stuff) {
    switch (stuff->selected->widget->type) {
        case WToggle:
            return (stuff->selected->widget->pressed) ? ToggleOn : ToggleOff;
        case WButton:
            return ButtonPress;
        default:
            return No;

    }
}

void Srun(Stuff *stuff) {
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
                Sclick(stuff);
                e.type = get_event_type(stuff);
                if (stuff->selected->widget->handler != NULL)
                    stuff->selected->widget->handler(&e);
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
