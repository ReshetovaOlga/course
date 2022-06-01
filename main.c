#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>
#include "libs/data_structures/string/string.h"

// task3_1
    void digitsToStartLettersToEnd(char *beginString) {
        char *beginSearch = beginString;
        WordDescriptor word;

        while (getWord(beginSearch, &word)) {
            digitToStart(word);
            beginSearch = word.end;
        }

    }

// task3_2
void reverseWords(char *beginString) {
    char *beginSearch = beginString;
    WordDescriptor word;

    while (getWord(beginSearch, &word)) {
        reverseWord(word);
        beginSearch = word.end;
    }
}



int main() {



    return 0;
}