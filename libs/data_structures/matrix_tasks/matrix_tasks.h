//
// Created by elen_ on 20.02.2022.
//

#ifndef COURSE_MATRIX_TASKS_H
#define COURSE_MATRIX_TASKS_H

#include "../matrix/matrix.h"

// меняет местами строки,
// в которых находятся максимальный и минимальный элементы
void swapRowsWithMaxAndMinElement(matrix m);

// поиск максимального элемента массива а размера n
int getMax(const int *array, int arraySize);

// упорядочивает строки матрицы m
// по неубыванию наибольших элементов строк
void sortRowsByMaxElement(matrix m);

// поиск минимального элемента массива а размера n
int getMin(const int *a, int n);

// упорядочивает столбцы матрицы m
// по неубыванию наименьших элементов строк
void sortColsByMinElement(matrix m);

#endif //COURSE_MATRIX_TASKS_H
