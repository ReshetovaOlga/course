//
// Created by elen_ on 08.03.2022.
//

#include "firstTheNumbersAreInvertedThenTheLetters.h"



int getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return 0;

    word->end = findSpace(word->begin);

    return 1;
}

void digitToStart(WordDescriptor word) {
    char _stringBuffer[MAX_STRING_SIZE+1];
    char *endStringBuffer = copy(word.begin, word.end,
                                 _stringBuffer);
    char *recPosition = copyIfReverse(endStringBuffer - 1,
                                      _stringBuffer - 1,
                                      word.begin, isdigit);
    copyIf(_stringBuffer, endStringBuffer, recPosition, isalpha);
}

//преобразовать строку таким образом, чтобы цифры
//каждого слова были перенесены в начало слова и изменить порядок следования
//цифр в слове на обратный, а буквы – в конец слова, без изменения порядка
//следования.
void firstTheNumbersAreInvertedThenTheLetters(char *beginString) {
    char *beginSearch = beginString;
    WordDescriptor word;

    while (getWord(beginSearch, &word)) {
        digitToStart(word);
        beginSearch = word.end;
    }
}