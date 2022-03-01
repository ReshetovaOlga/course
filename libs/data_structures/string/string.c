//
// Created by elen_ on 27.02.2022.
//

#include "string.h"
#include <assert.h>

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
    while (*begin != '\0' && isspace(*begin) != 1)
        begin++;

    assert(*begin != '\0');

    return begin;
}

char *findNonSpaceReverse(char *rbegin, const char *rend){
    while (rbegin != rend && isspace(*rbegin) != 0)
        rbegin--;

    return rbegin;
}

char *findSpaceReverse(char *rbegin, const char *rend){
    while (rbegin != rend && isspace(*rbegin) == 0)
        rbegin--;

    return rbegin;
}

int strcmp_(const char *lhs, const char *rhs) {
    while (*lhs != '\0' && *rhs != '\0' && *lhs == *rhs) {
        lhs++;
        rhs++;
    }

    return *lhs - *rhs;
}

char *copy(const char *beginSource, const char *endSource, char *beginDestination){

}

char *copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int)){

}

char *copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int)){

}