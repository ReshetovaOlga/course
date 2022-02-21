//
// Created by elen_ on 20.02.2022.
//

#include "matrix_tasks.h"

// 1
// Дана квадратная матрица,
// все элементы которой различны.
// Поменять местами строки,
// в которых находятся максимальный и минимальный элементы.
void swapRowsWithMaxAndMinElement(matrix m) {
    position minPos = getMinValuePos(m);
    position maxPos = getMaxValuePos(m);
    swapRows(m, minPos.rowIndex, maxPos.rowIndex);
}

// 2
// Упорядочить строки матрицы
// по неубыванию наибольших элементов строк.
void sortRowsByMaxElement(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, getMax);
}


int getMax(const int *array, int arraySize) {
    int maxElementIndex = 0;
    for (int i = 0; i < arraySize; i++)
        if (array[i] > array[maxElementIndex])
            maxElementIndex = i;
    return array[maxElementIndex];
}

// 3
// Упорядочить столбцы матрицы по неубыванию
// минимальных элементов столбцов

void sortColsByMinElement(matrix m) {
    choiceSortColsMatrixByColCriteria(m, getMin);
}

int getMin(const int *array, int arraySize) {
    int maxElementIndex = 0;
    for (int i = 0; i < arraySize; i++)
        if (array[i] < array[maxElementIndex])
            maxElementIndex = i;
    return array[maxElementIndex];
}

// 4
// Если данная квадратная матрица 𝐴 симметрична,
// то заменить 𝐴 ее квадратом (𝐴^2)
void getSquareOfMatrixIfSymmetric(matrix *m) {
    if (isSquareMatrix(*m) == 1)
        *m = mulMatrices(*m, *m);
}

matrix mulMatrices(matrix m1, matrix m2) {
    matrix m = getMemMatrix(m1.nRows, m2.nCols);

    for (int i = 0; i < m1.nRows; i++)
        for (int j = 0; j < m2.nCols; j++) {
            m.values[i][j] = 0;

            for (int k = 0; k < m1.nCols; k++)
                m.values[i][j] += m1.values[i][k] * m2.values[k][j];
        }

    return m;
}