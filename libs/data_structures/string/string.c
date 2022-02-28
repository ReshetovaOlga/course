//
// Created by elen_ on 27.02.2022.
//

#include "string.h"

size_t strlen_(char *begin) {
    char *end = begin;
    while (*end != '\0')
        end++;

    return end - begin;
}

char *find(char *begin, const char *end, int ch) {
    while (begin != end && *begin != ch)
        begin++;

    return begin;
}

char *findNonSpace(char *begin){
    while(*begin!='\0' && isspace(*begin) != 0)
        begin++;

    return begin;
}