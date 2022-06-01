#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include "libs/data_structures/string/string.h"

// task6
bool isItOrder(char *beginString) {
    WordDescriptor lastWord;
    if (!getWord(beginString, &lastWord))
        return true;

    beginString = lastWord.end;
    WordDescriptor currentWord;
    while (getWord(beginString, &currentWord)) {
        if (areWordsEqual(lastWord, currentWord) > 0)
            return false;
        lastWord = currentWord;
        beginString = lastWord.end;
    }
    return true;
}



int main() {

    return 0;
}