//
// Created by elen_ on 08.03.2022.
//

#ifndef COURSE_FIRSTLETTERSTHENNUMBERS_H
#define COURSE_FIRSTLETTERSTHENNUMBERS_H
#include "../../string/tasks/firstTheNumbersAreInvertedThenTheLetters.h"

void letterToStart(WordDescriptor word);

void firstLettersThenNumbers(char *beginString);

//считывает слово с конца строки
int getWordReverse(char *rbegin, char *rend, WordDescriptor *word);

#endif //COURSE_FIRSTLETTERSTHENNUMBERS_H
