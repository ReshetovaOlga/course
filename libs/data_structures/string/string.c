//
// Created by elen_ on 27.02.2022.
//

#include "string.h"
#include <assert.h>
#include <memory.h>
#include <stdbool.h>

size_t strlen_(char *begin) {
    char *end = begin;
    while (*end != '\0')
        end++;

    return end - begin;
}

char *find(char *begin, const char *end, int ch) {
    while (begin != end && *begin != ch)
        begin++;

    assert(begin != end);

    return begin;
}

char *findNonSpace(char *begin) {
    while (*begin != '\0' && isspace(*begin) != 0)
        begin++;

    return begin;
}

char *findSpace(char *begin) {
    while (*begin != '\0' && isspace(*begin) == 0)
        begin++;

    return begin;
}

char *findNonSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin != rend && isspace(*rbegin) != 0)
        rbegin--;

    return rbegin;
}

char *findSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin != rend && isspace(*rbegin) == 0)
        rbegin--;

    return rbegin;
}

int strcmp_(const char *lhs, const char *rhs) {
    while (*lhs != '\0' && *lhs == *rhs) {
        lhs++;
        rhs++;
    }

    return *lhs - *rhs;
}

char *copy(const char *beginSource, const char *endSource, char *beginDestination) {
    memcpy(beginDestination, beginSource, endSource - beginSource);
    char *endDestination = beginDestination + (endSource - beginSource);
    *endDestination = '\0';
    return endDestination;
}

char *copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int)) {
    while (beginSource < endSource){
        if (f(*beginSource))
            *beginDestination++ = *beginSource;

        beginSource++;
    }

    return beginDestination;
}

char *copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int)) {
    while (rbeginSource > rendSource){
        if (f(*rbeginSource))
            *beginDestination++ = *rbeginSource;

        rbeginSource--;
    }

    return beginDestination;
}

char *getEndOfString(char *s) {
    size_t lengthS = strlen_(s);
    return s + lengthS;
}

int getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return 0;

    word->end = findSpace(word->begin);

    return 1;
}

void digitToStart(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end,
                                 _stringBuffer);
    char *recPosition = copyIfReverse(endStringBuffer - 1,
                                      _stringBuffer - 1,
                                      word.begin, isdigit);
    copyIf(_stringBuffer, endStringBuffer, recPosition, isalpha);
}

char *copyReverse(char *rbeginSource, const char *rendSource, char *beginDestination) {
    while (rbeginSource > rendSource) {
        *beginDestination++ = *rbeginSource;
        rbeginSource--;
    }

    return beginDestination;
}


void reverseWord(WordDescriptor word) {
    char *endStringBuffer = copyReverse(word.end - 1, word.begin - 1,
                                        _stringBuffer);
    copy(_stringBuffer, endStringBuffer, word.begin);
}


void getBagOfWords(BagOfWords *bag, char *s) {
    bag->size = 0;

    WordDescriptor word;
    while (getWord(s, &word)) {
        bag->words[bag->size++] = word;
        s = word.end;
    }
}

void printWord(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end, _stringBuffer);

    *endStringBuffer = '\0';

    printf("%s", _stringBuffer);
}

int areWordsEqual(WordDescriptor w1, WordDescriptor w2) {
    while (w1.begin != w1.end && w2.begin != w2.end && *w1.begin == *w2.begin) {
        w1.begin++;
        w2.begin++;
    }

    return *w1.begin - *w2.begin;
}

bool identicalWords(WordDescriptor w1, WordDescriptor w2) {
    if (w1.end - w1.begin != w2.end - w2.begin)
        return 0;
    while (w1.begin != w1.end) {
        if (*w1.begin != *w2.begin)
            return 0;
        w1.begin++;
        w2.begin++;
    }
    return 1;
}

int getIdenticalWord(char *beginSearch, WordDescriptor *word, WordDescriptor wordToFind) {
    while (getWord(beginSearch, word)) {
        if (identicalWords(*word, wordToFind)) {
            return 1;
        } else {
            beginSearch = word->end;
        }
    }
    return 0;
}





