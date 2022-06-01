#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include "libs/data_structures/string/string.h"

// task5
void replaceWords(char *source, char *w1, char *w2) {
    size_t w1Size = strlen_(w1);
    size_t w2Size = strlen_(w2);
    WordDescriptor word1 = {w1, w1 + w1Size};
    WordDescriptor word2 = {w2, w2 + w2Size};

    char *ptr1, *ptr2;
    if (w1Size >= w2Size) {
        ptr1 = source;
        ptr2 = source;
    } else {
        copy(source, getEndOfString(source), _stringBuffer);
        ptr1 = _stringBuffer;
        ptr2 = source;
    }

    WordDescriptor foundWord;
    while (getIdenticalWord(ptr1, &foundWord, word1)) {
        ptr2 = copy(ptr1, foundWord.begin, ptr2);
        ptr2 = copy(word2.begin, word2.end, ptr2);
        ptr1 = foundWord.end;
    }

    char *endSource = getEndOfString(ptr1);
    ptr2 = copy(ptr1, endSource, ptr2);
    *ptr2 = '\0';
}


int main() {

    return 0;
}