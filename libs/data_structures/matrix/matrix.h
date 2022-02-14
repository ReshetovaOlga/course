//
// Created by elen_ on 12.02.2022.
//

#ifndef COURSE_MATRIX_H
#define COURSE_MATRIX_H

#endif //COURSE_MATRIX_H

#include <stdbool.h>
#include <stdio.h>

typedef struct matrix {
    int **values;// элементы матрицы
    int nRows;// количество рядов
    int nCols;// количество столбцов
    }matrix;

typedef struct position{
    int rowIndex;
    int colIndex;
    }position;

//1 размещает в динамической памяти
//матрицу размером nRows на nCols
matrix getMemMatrix(int nRows, int nCols);

//2 размещает в динамической памяти
//массив из nMatrices матриц размером nRows на nCols.
matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols);

//3 освобождает память, выделенную под
//хранение матрицы m
void freeMemMatrix(matrix m);

//4 свобождает память,
//выделенную под хранение массива ms из nMatrices матриц.
void freeMemMatrices(matrix *ms, int nMatrices);

//5  ввод матрицы m
void inputMatrix(matrix *m);

//6 ввод массива из
// nMatrices матриц, хранящейся по адресу ms
void inputMatrices(matrix *ms, int nMatrices);

//7  вывод матрицы m
void outputMatrix(matrix m);

//8 вывод массива из
//nMatrices матриц, хранящейся по адресу ms
void outputMatrices(matrix *ms, int nMatrices);

//9 обмен строк с порядковыми
//номерами i1 и i2 в матрице m
void swapRows(matrix m, int i1, int i2);
/*
//
void swapColumns(matrix m, int j1, int j2);

//10
void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(int *, int));

//11
void insertionSortColsMatrixByColCriteria(matrix m, int (*criteria)(int *, int));

//12
bool isSquareMatrix(matrix m);

//13
bool twoMatricesEqual(matrix m1, matrix m2);

//14
bool isEMatrix(matrix m);

//15
bool isSymmetricMatrix(matrix m);

//16
void transposeSquareMatrix(matrix m);

//17
position getMinValuePos(matrix m);

//18
position getMaxValuePos(matrix m);

//19
matrix createMatrixFromArray(const int *a, size_t nRows, size_t nCols);

//20
matrix *createArrayOfMatrixFromArray(const int *values, size_t nMatrices, size_t nRows, size_t nCols);

//21
int getMax(int *a, int n);

//22
void sortRowsByMinElement(matrix m);

//23
int getMin(int *a, int n);

//24
void sortColsByMinElement(matrix m);

//25
matrix mulMatrices(matrix m1, matrix m2);

//26
void getSquareOfMatrixIfSymmetric(matrix *m);

//27
bool isUnique(long long *a, int n);

//28
long long getSum(int *a, int n);

//29
void transposeIfMatrixHasEqualSumOfRows(matrix m, int nRows, int nCols);

//30
bool isMutuallyInverseMatrices(matrix m1, matrix m2);

//31
int max(int a, int b);

//32
long long findSumOfMaxesOfPseudoDiagonal(matrix m);

//33
int getMinInArea(matrix m);

//34
float getDistance(int *a, int n);

//35
void insertionSortRowsMatrixByRowCriteriaF(matrix m, float (*criteria)(int *, int));

//36
void sortByDistances(matrix m);

//37
int cmp_long_long(const void *pa, const void *pb);

//38
int countNUnique(long long *a, int n);

//39
int countEqClassesByRowsSum(matrix m);

//40
int getNSpecialElement(matrix m, int nRows, int nCols);

//41
position getLeftMin(matrix m);

//42
void swapPenultimateRow(matrix m, int n);

//43
bool isNonDescendingSorted(int *a, int n);

//44
bool hasAllNonDescendingRows(matrix m);

//45
int countNonDescendingRowsMatrices(matrix *ms, int nMatrix);

//46
int countValues(const int *a, int n, int value);

//47
int countZeroRows(matrix m);

//48
void printMatrixWithMaxZeroRows(matrix *ms, int nMatrix);

//49
int min2(int a, int b);

//50
int getNSpecialElement2(matrix m);

//51
double getScalarProduct(int *a, int *b, int n);

//52
double getVectorLength(int *a, int n);

//53
double getCosine(int *a, int *b, int n);

//54
int getVectorIndexWithMaxAngle(matrix m, int *b);

//55
long long getScalarProductRowAndCol(matrix m, int i, int j);

//56
long long getSpecialScalarProduct(matrix m, int n);
 */