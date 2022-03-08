//
// Created by elen_ on 08.03.2022.
//

#ifndef COURSE_REMOVEADJACENTEQUALLETTERS_H
#define COURSE_REMOVEADJACENTEQUALLETTERS_H
#include "../../string/string.h"

char *copyIfElementsNitDabble(char *beginSource, const char *endSource, char *beginDestination);

// Преобразовывает строку s,
// оставляя только один символ в каждой
// последовательности подряд идущих одинаковых символо
void removeAdjacentEqualLetters(char *s);

#endif //COURSE_REMOVEADJACENTEQUALLETTERS_H
