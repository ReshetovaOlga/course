//
// Created by elen_ on 27.02.2022.
//

#ifndef COURSE_STRING_H
#define COURSE_STRING_H
#include <stdio.h>
#include <ctype.h>

// определяет, сколько символов имеется
// от начала строки до первого ноль-символа
// с помощью указателя  begin
size_t strlen_ (char * begin );

// возвращает указатель на первый элемент с кодом ch,
// расположенным на ленте памяти между
// адресами begin и end не включая end
char *find(char *begin, const char *end, int ch);

// возвращает указатель на первый
// символ, отличный от пробельных,
// расположенный на ленте памяти,
// начиная с begin и заканчивая ноль-символом
char *findNonSpace(char *begin);

#endif //COURSE_STRING_H
