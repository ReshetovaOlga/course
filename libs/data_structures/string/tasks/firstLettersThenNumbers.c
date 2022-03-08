
//
// Created by elen_ on 08.03.2022.
//

#include "firstLettersThenNumbers.h"


int getWordReverse(char *rbegin, char *rend, WordDescriptor *word){
    word->end = findNonSpaceReverse(rbegin,rend);
    if (*word->end == *rend)
        return 0;

    word->begin = findSpaceReverse(word->end, rend);

    return 1;
}

void letterToStart(WordDescriptor word) {
    char _stringBuffer[MAX_STRING_SIZE+1];
    char *endStringBuffer = copy(word.begin, word.end, _stringBuffer);
    char *recPosition = copyIf(_stringBuffer, endStringBuffer, word.begin, isalpha);
    copyIf(_stringBuffer, endStringBuffer, recPosition, isdigit);
}

// Преобразовать строку таким образом, чтобы цифры каждого слова были
// перенесены в конец слова без изменения порядка следования их в слове, а
// буквы – в начало.
void firstLettersThenNumbers(char *beginString) {
    char *beginSearch = beginString;
    WordDescriptor word;

    while (getWord(beginSearch, &word)) {
        letterToStart(word);
        beginSearch = word.end;
    }
}
