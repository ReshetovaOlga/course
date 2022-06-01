#include <stdio.h>
#include "libs/data_structures/string/string.h"

// task7
void printWordsLineInReversedOrder(char *beginString) {
    getBagOfWords(&_bag, beginString);

    for (int i = _bag.size - 1; i >= 0; i--) {
        printWord(_bag.words[i]);
        printf("\n");
    }
}

int main() {

    return 0;
}