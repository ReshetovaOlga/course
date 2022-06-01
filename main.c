#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include "libs/data_structures/string/string.h"

// task19
bool areAllLettersInString(char *s, WordDescriptor word) {
    bool availability[CHAR_MAX + 1] = {false};
    char *end = getEndOfString(s);
    while (s != end) {
        availability[*s] = true;
        s++;
    }

    while (word.begin != word.end) {
        if (!availability[*word.begin])
            return false;
        word.begin++;
    }
    return true;
}


int main() {

    return 0;
}