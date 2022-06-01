#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include "libs/data_structures/string/string.h"

// task 13
bool areIdenticalWordsInString(char *s) {
    getBagOfWords(&_bag, s);
    WordDescriptor *bagEnd = _bag.words + _bag.size;
    for (WordDescriptor *currentWord1 = _bag.words; currentWord1 < bagEnd; ++currentWord1) {
        for (WordDescriptor *currentWord2 = currentWord1 + 1; currentWord2 < bagEnd; ++currentWord2) {
            if (identicalWords(*currentWord1, *currentWord2))
                return true;
        }
    }

    return false;
}



int main() {

    return 0;
}