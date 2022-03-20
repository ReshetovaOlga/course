//
// Created by elen_ on 09.03.2022.
//

#ifndef COURSE_SORTANDDIFFICULTYASSESSMENT_H
#define COURSE_SORTANDDIFFICULTYASSESSMENT_H

#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<time.h>

# define ARRAY_SIZE(a)sizeof(a)/sizeof(a[0])

#define TIME_TEST(testCode, time){ \
clock_t start_time = clock(); \
testCode \
clock_t end_time=clock(); \
clock_t sort_time=end_time-start_time; \
time=(double)sort_time/CLOCKS_PER_SEC; \
}

// возвращает true если массив а размера n упорядочен,
// иначе false
bool isOrdered(const int *a, size_t n);


// функция сортировки
typedef struct SortFunc {
    void (*sort)(int *a, size_t n); // указатель на функцию сортировки
    char name[64]; // имя сортировки, используемое при выводе
} SortFunc;

// функция генерации
typedef struct GeneratingFunc {
    void (*generate)(int *a, size_t n); // указатель на функции генерации последоват.
    char name[64]; // имя генератора, используемое при выводе
} GeneratingFunc;

// совершает обмен переменных,
// расположенных по адресам а и b
void swap(int *a, int *b);

// сортирует обменом массив а размера size
void bubbleSort(int *a, size_t size);

// сортирует выбором массив а размера size
void selectionSort(int *a, size_t size);

// сортирует вставками массив а размера size
void insertionSort(int *a, size_t size);

// сортирует расческой массив а размера size
void combSort(int *a, size_t size);

// сортирует сортировкой Шелла массив а размера size
void sortShell(int *a, size_t size);

// создает массив префиксных сумм
void getPrefixSums(int *a, int n);

// сортирует цифровой сортировкой массив а размера size
void digitSort(int *a, size_t size);

void generateRandomArray(int *a, size_t n);

void generateOrderedArray(int *a, size_t n);

void generateOrderedBackwards(int *a, size_t n);


#endif //COURSE_SORTANDDIFFICULTYASSESSMENT_H
