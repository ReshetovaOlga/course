#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include "libs/data_structures/string/string.h"

// task 15
void stringWithoutLastWord(char *sRes, char *sOriginal) {
    WordDescriptor lastWord;
    rGetWord(getEndOfString(sOriginal) - 1, sOriginal - 1, &lastWord);

    WordDescriptor currentWord;
    while (getWord(sOriginal, &currentWord)) {
        if (!identicalWords(lastWord, currentWord)) {
            sRes = copy(currentWord.begin, currentWord.end, sRes);
            *sRes = ' ';
            sRes++;
        }
        sOriginal = currentWord.end;
    }

    sRes--;
    *sRes = '\0';
}





int main() {

    return 0;
}