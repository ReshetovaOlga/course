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

// Находит и возвращает минимальный
// элемент матрицы m в нужной области области
int getMinInArea(matrix m);

// возвращает расстояние
double getDistance(const int *a, int n);

// упорядочивает точки
// по неубыванию их расстояний до начала координат
void sortByDistances(matrix m);

int cmp_long_long(const void *pa, const void *pb);

// возвращает количиство впервые встречающихся элементов массива а размера n
int countNUnique(const long long *a, int n);

// возвращает количество классов эквивалентных строк
// данной матрицы m
int countEqClassesByRowsSum(matrix m);

// возвращает количество элементов,
// которые больше суммы других элементов в столбце
int getNSpecialElement(matrix m);

// находит координаты раннего по столбцам минимума
position getLeftMin(matrix m);

// заменяет предпоследнюю строку нужным столбцом
void swapPenultimateRow(matrix m);

// если массив а размера n упорядочен по неубыванию,
// возвращвет 1, иначе 0
bool isNonDescendingSorted(const int *a, int n);

// если все строки матрицы m упорядочены по неубыванию,
// возвращвет 1, иначе 0
bool hasAllNonDescendingRows(matrix m);

// возвращает число матриц в массиве ms размера nMatrix,
// строки которых упорядочены по неубыванию элементов
int countNonDescendingRowsMatrices(matrix *ms, int nMatrix);

// возвращает матрицы массива ms размера nMatrix
// с максимальным количеством нулевых строк
void printMatrixWithMaxZeroRows(matrix *ms, int nMatrix);

// возвращает максимальный по модулю элемент матрицы m
int maxElementInMatrixAboutModule(matrix m);

// выводит матрицы из массива матриц ms размера nMatrix
// с минимальным максимальным модулем элемента
void printMatrixWithMinMaxAboutModuleInMatrix(matrix *ms, int nMatrix);

#endif //COURSE_MATRIX_TASKS_H
