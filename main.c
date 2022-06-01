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

void task3_2(){

}

int main() {
    char s="4l5l";
    digitsToStartLettersToEnd(&s);
    printf("%s", s);


    return 0;
}