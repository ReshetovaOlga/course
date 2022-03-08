//
// Created by elen_ on 08.03.2022.
//

#ifndef COURSE_FIRSTTHENUMBERSAREINVERTEDTHENTHELETTERS_H
#define COURSE_FIRSTTHENUMBERSAREINVERTEDTHENTHELETTERS_H
#include "../../string/string.h"

typedef struct WordDescriptor {
    char * begin ; // позиция начала слова
    char * end ; // позиция первого символа, после последнего символа слова
    } WordDescriptor ;

int getWord(char *beginSearch, WordDescriptor *word);

void digitToStart(WordDescriptor word);

void firstTheNumbersAreInvertedThenTheLetters(char *beginString);


#endif //COURSE_FIRSTTHENUMBERSAREINVERTEDTHENTHELETTERS_H
