#include "widgets.h"

const char* str_repeat(char* str, size_t times) {
    if (times < 1) return NULL;
    char *ret = (char *) (malloc(sizeof(str) * times + 1));
    if (ret == NULL) return NULL;
    strcpy(ret, str);
    while (--times > 0) {
        strcat(ret, str);
    }
    return ret;
}

