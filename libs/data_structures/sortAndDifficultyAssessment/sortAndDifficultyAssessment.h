//
// Created by elen_ on 09.03.2022.
//

#ifndef COURSE_SORTANDDIFFICULTYASSESSMENT_H
#define COURSE_SORTANDDIFFICULTYASSESSMENT_H

#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<time.h>

// функция сортировки
typedef struct SortFunc {
    void (*sort)(int *a, size_t n); // указатель на функцию сортировки
    char name[64]; // имя сортировки, используемое при выводе
    } SortFunc ;

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

#endif //COURSE_SORTANDDIFFICULTYASSESSMENT_H
