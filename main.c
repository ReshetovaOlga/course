#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include "libs/data_structures/string/string.h"

// task 10
void reverseString(char *beginString) {
    if (*beginString == '\0')
        return;

    char *endStringBuffer = copy(beginString, getEndOfString(beginString), _stringBuffer);
    *endStringBuffer = '\0';

    WordDescriptor word;
    while (rGetWord(endStringBuffer - 1, _stringBuffer - 1, &word)) {
        beginString = copy(word.begin, word.end, beginString);

        *beginString = ' ';
        beginString++;

        endStringBuffer = word.begin;
    }

    beginString--;
    *beginString = '\0';
}






int main() {

    return 0;
}