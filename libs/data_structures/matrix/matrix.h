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

//1 размещает в динамической памяти матрицу размером nRows на nCols
matrix getMemMatrix(int nRows, int nCols);

//2 размещает в динамической памяти
// массив из nMatrices матриц размером nRows на nCols.
matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols);

//3 освобождает память,
// выделенную под хранение матрицы m
void freeMemMatrix(matrix m);

//4 свобождает память,
//выделенную под хранение массива ms из nMatrices матриц.
void freeMemMatrices(matrix *ms, int nMatrices);

//5  ввод матрицы m
void inputMatrix(matrix m);

//6 ввод массива из nMatrices матриц, хранящейся по адресу ms
void inputMatrices(matrix *ms, int nMatrices);

//7  вывод матрицы m
void outputMatrix(matrix m);

//8 вывод массива из nMatrices матриц, хранящейся по адресу ms
void outputMatrices(matrix *ms, int nMatrices);

//9 обмен строк с порядковыми
// номерами i1 и i2 в матрице m
void swapRows(matrix m, int i1, int i2);

//10 обмен колонок с порядковыми номерами j1 и j2 в матрице m
void swapColumns(matrix m, int j1, int j2);

//11 выполняет сортировку вставками строк
// матрицы m по неубыванию значения функции criteria
// применяемой для строк
void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(const int *, int));

//12 выполняет сортировку вставками
// столбцов матрицы m по неубыванию значения функции criteria
// применяемой для столбцов
void insertionSortColsMatrixByColCriteria(matrix m, int (*criteria)(const int *, int));

//13 выполняет сортировку вставками
// столбцов матрицы m по неубыванию значения функции criteria
// применяемой для столбцов
void choiceSortColsMatrixByColCriteria(matrix m, int (*criteria)(const int *, int));

//14 возвращает значение ’истина’,
// если матрица m является квадратной, ложь – в противном случае
bool isSquareMatrix(matrix m);

//15 возвращает значение ’истина’,
// если матрицы m1 и m2 равны, ложь – в противном случае
bool twoMatricesEqual(matrix m1, matrix m2);

//16 возвращает значение ’истина’,
// если матрица m является единичной, ложь – в противном случае
bool isEMatrix(matrix m);

//17 возвращает значение ’истина’, если
// матрица m является симметричной, ложь – в противном случае
bool isSymmetricMatrix(matrix m);

//18 обмен элементов а и b
void swapElement(int *a, int *b);

//19  транспонирует квадратную матрицу m
void transposeSquareMatrix(matrix m);

//20 возвращает позицию минимального элемента матрицы m.
position getMinValuePos(matrix m);

//21  возвращает позицию максимального элемента матрицы m.
position getMaxValuePos(matrix m);

//22 возвращает матрицу, размера nRows на nCols,
// построенного из элементов массива a, размещенную в динамической памяти
matrix createMatrixFromArray(const int *a, int nRows, int nCols);

//23 возвращает указатель на нулевую матрицу массива из nMatrices матриц, размещенных
// в динамической памяти, построенных из элементов массива a
matrix *createArrayOfMatrixFromArray(const int *values, int nMatrices, int nRows, int nCols);

//24 считает количество нулевых строк в матрице m
int countZeroRows(matrix m);
