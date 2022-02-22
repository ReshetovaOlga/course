//
// Created by elen_ on 20.02.2022.
//

#include "matrix_tasks.h"
#include <assert.h>
#include <malloc.h>

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

// 5
// Дана квадратная матрица.
// Если среди сумм элементов строк матрицы нет равных,
// то транспонировать матрицу.
void transposeIfMatrixHasNotEqualSumOfRows(matrix m) {
    assert(isSquareMatrix(m) == 1);

    int *arrayOfSum = (int *) malloc(sizeof(int) * m.nCols);

    for (int i = 0; i < m.nRows; i++)
        arrayOfSum[i] = getSum(m.values[i], m.nCols);
    if (isUnique(arrayOfSum, m.nCols) == 1)
        transposeSquareMatrix(m);
    free(arrayOfSum);
}

int getSum(const int *a, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    return sum;
}

bool isUnique(const int *a, int n) {
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] == a[j])
                return 0;
    return 1;
}

// 6
// Даны две квадратные матрицы 𝐴 и 𝐵.
// Определить, являются ли они взаимно обратными (𝐴 = 𝐵^−1).
bool isMutuallyInverseMatrices(matrix m1, matrix m2) {
    if (isEMatrix(mulMatrices(m1, m2)) == 1)
        return true;
    else
        return false;
}

// 7
// Дана прямоугольная матрица.
// Назовем псевдодиагональю множество элементов этой матрицы,
// лежащих на прямой, параллельной прямой,
// содержащей элементы 𝑎𝑖,𝑖.
// Найти сумму максимальных элементов всех псевдодиагоналей данной матрицы.
int max(int a, int b) {
    return a > b ? a : b;
}

void createAnArray(int *a, int n, int el) {
    for (int i = 0; i < n; i++)
        a[i] = el;
}

long long findSumOfMaxesOfPseudoDiagonal(matrix m) {
    int sizeArray = m.nCols + m.nRows - 1;
    int *arrayMaxEl = (int *) malloc(sizeof(int) * (sizeArray));
    createAnArray(arrayMaxEl, sizeArray, 0);

    int indexArrayMaxEl;
    for (int i = 0; i < m.nRows; i++) {
        indexArrayMaxEl = sizeArray / 2 - i - 1;
        for (int j = 0; j < m.nCols; j++) {
            if (i != j)
                arrayMaxEl[indexArrayMaxEl] = max(arrayMaxEl[indexArrayMaxEl], m.values[i][j]);
            indexArrayMaxEl++;
        }
    }

    return getSum(arrayMaxEl, sizeArray);
}

// 8
// Дана прямоугольная матрица,
// все элементы которой различны.
// Найти минимальный элемент матрицы в выделенной области
int getMinInArea(matrix m){
    position maxElementPos= getMaxValuePos(m);
    position minElementPos=maxElementPos;
    int minBoundary=maxElementPos.colIndex;
    int maxBoundary=minBoundary;
    for (int i=maxElementPos.rowIndex-1; i>=0; i--){
        if (minBoundary>0)
            minBoundary--;
        if (maxBoundary<m.nCols-1)
            maxBoundary++;
        for (int j=minBoundary; j<=maxBoundary; j++)
            if (m.values[i][j]<m.values[minElementPos.rowIndex][minElementPos.colIndex]){
                minElementPos.rowIndex=i;
                minElementPos.colIndex=j;
            }
    }
    return m.values[minElementPos.rowIndex][minElementPos.colIndex];
}