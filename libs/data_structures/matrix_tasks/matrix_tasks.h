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

// умножает матрицу m1 на матрицу m2
matrix mulMatrices(matrix m1, matrix m2);

// возводит матрицу m в квадрат, если та симметрична
void getSquareOfMatrixIfSymmetric(matrix *m);

// возвращает сумму элементов массива а размера n
int getSum(const int *a, int n);

// возвращает 1
// если элементы массива а размера n не равны, иначе 0
bool isUnique(const int *a, int n);

// транспонирует матрицу,
// если среди сумм элементов строк матрицы нет равных
void transposeIfMatrixHasNotEqualSumOfRows(matrix m);

// возвращает 1, если матрицы m1 и m2 взаимнообратные, иначе 0
bool isMutuallyInverseMatrices(matrix m1, matrix m2);

// возвращает максимальный из двух переменных а и b
int max(int a, int b);

// возвращает сумму максимальных
// элементов всех псевдодиагоналей матрицы m
long long findSumOfMaxesOfPseudoDiagonal(matrix m);

// забивает массив а размера n элементом el
void createAnArray(int *a, int n, int el);

#endif //COURSE_MATRIX_TASKS_H
