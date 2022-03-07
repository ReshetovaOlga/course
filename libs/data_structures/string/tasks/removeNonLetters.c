//
// Created by elen_ on 07.03.2022.
//

#include "removeNonLetters.h"
char *getEndOfString(char *s) {
    size_t lengthS = strlen_(s);
    return s + lengthS;
}

void removeNonLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isgraph);
    *destination = '\0';
}
