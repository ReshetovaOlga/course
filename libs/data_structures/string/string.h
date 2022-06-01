//
// Created by elen_ on 27.02.2022.
//

#ifndef COURSE_STRING_H
#define COURSE_STRING_H
#include <stdio.h>
#include <ctype.h>
#define MAX_STRING_SIZE 100
# define MAX_N_WORDS_IN_STRING 100
# define MAX_WORD_SIZE 20

typedef struct WordDescriptor {
    char *begin; // позиция начала слова
    char *end; // позиция первого символа, после последнего символа слова
} WordDescriptor;

typedef struct BagOfWords {
    WordDescriptor words[MAX_N_WORDS_IN_STRING];
    size_t size;
} BagOfWords;
static char _stringBuffer[MAX_STRING_SIZE + 1];
static BagOfWords _bag;
static BagOfWords _bag2;


// определяет, сколько символов имеется
// от начала строки до первого ноль-символа
// с помощью указателя  begin
size_t strlen_(char * begin );

// возвращает указатель на первый элемент с кодом ch,
// расположенным на ленте памяти между
// адресами begin и end не включая end
char *find(char *begin, const char *end, int ch);

// возвращает указатель на первый
// символ, отличный от пробельных,
// расположенный на ленте памяти,
// начиная с begin и заканчивая ноль-символом
char *findNonSpace(char *begin);

// возвращает указатель на первый пробельный символ,
// расположенный на ленте памяти начиная с адреса begin
// или на первый ноль-символ.
char *findSpace(char *begin);

// возвращает указатель на первый справа символ,
// отличный от пробельных,
// расположенный на ленте памяти,
// начиная с rbegin (последний символ строки, за которым следует ноль-символ)
// и заканчивая rend (адрес символа перед началом строки).
// Если символ не найден, возвращается адрес rend.
char* findNonSpaceReverse(char *rbegin, const char *rend);

// возвращает указатель на первый пробельный символ справа,
// расположенный на ленте памяти,
// начиная с rbegin и заканчивая rend. Если символ не найден,
// возвращается адрес rend.
char* findSpaceReverse(char *rbegin, const char *rend);

// сравнивает строки lhs и rhs,
// если равны возвращает 0, иначе нет
int strcmp_(const char *lhs, const char *rhs);

// записывает по адресу beginDestination фрагмент памяти,
// начиная с адреса beginSource до endSource.
// Возвращает указатель на следующий свободный фрагмент памяти в destination
char *copy(const char *beginSource, const char *endSource, char *beginDestination);

// записывает по адресу beginDestination элементы
// из фрагмента памяти начиная с beginSource заканчивая endSource,
// удовлетворяющие функции-предикату f. Функция возвращает указатель
// на следующий свободный для записи фрагмент в памяти.
char* copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int));

// записывает по адресу beginDestination элементы
// из фрагмента памяти начиная с rbeginSource
// заканчивая rendSource, удовлетворяющие функции-предикату f.
// Функция возвращает значение beginDestination по окончанию работы функции.
char* copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int));

// находит конец строки
char *getEndOfString(char *s);

int getWord(char *beginSearch, WordDescriptor *word);

void digitToStart(WordDescriptor word);

char *copyReverse(char *rbeginSource, const char *rendSource, char *beginDestination);

void reverseWord(WordDescriptor word);

void getBagOfWords(BagOfWords *bag, char *s);

void printWord(WordDescriptor word);

int areWordsEqual(WordDescriptor w1, WordDescriptor w2);

bool identicalWords(WordDescriptor w1, WordDescriptor w2);

int getIdenticalWord(char *beginSearch, WordDescriptor *word, WordDescriptor wordToFind);

int rGetWord(char *rBeginSearch, char *rEndSearch, WordDescriptor *word);

int getSeparatedWord(char *beginSearch, WordDescriptor *word);

#endif //COURSE_STRING_H
