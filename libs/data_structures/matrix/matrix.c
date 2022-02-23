//
// Created by elen_ on 12.02.2022.
//

#include "matrix.h"
#include <malloc.h>

matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);

    for (int i = 0; i < nRows; i++)
        values[i] = (int *) malloc(sizeof(int) * nCols);

    return (matrix) {values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols) {
    matrix *ms = (matrix *) malloc(sizeof(matrix) * nMatrices);

    for (int i = 0; i < nMatrices; i++)
        ms[i] = getMemMatrix(nRows, nCols);

    return ms;
}

void freeMemMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++)
        free(m.values[i]);

    free(m.values);
}

void freeMemMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        freeMemMatrix(*ms);
}

void inputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            scanf("%d", &m.values[i][j]);
}

void inputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        inputMatrix(ms[i]);
}

void outputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++)
            printf("%d ", m.values[i][j]);
        printf("\n");
    }
    printf("\n");
}

void outputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        outputMatrix(ms[i]);
}

void swapRows(matrix m, int i1, int i2) {
    if (i1 != i2) {
        int *t = m.values[i1];
        m.values[i1] = m.values[i2];
        m.values[i2] = t;
    }
}

void swapColumns(matrix m, int j1, int j2) {
    for (int i = 0; i < m.nRows; i++) {
        int t = m.values[i][j1];
        m.values[i][j1] = m.values[i][j2];
        m.values[i][j2] = t;
    }
}


void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(const int *, int)) {
    int *criteriaArray = (int *) malloc(sizeof(int) * m.nRows);

    for (int i = 0; i < m.nRows; i++)
        criteriaArray[i] = criteria(m.values[i], m.nCols);

    for (int i = 0; i < m.nRows; i++) {
        int *t1 = m.values[i];
        int t2 = criteriaArray[i];
        int j = i;
        while (j - 1 >= 0 && t2 < criteriaArray[j - 1]) {
            criteriaArray[j] = criteriaArray[j - 1];
            m.values[j] = m.values[j - 1];
            j--;
        }

        criteriaArray[j] = t2;
        m.values[j] = t1;
    }

    free(criteriaArray);
}

void insertionSortColsMatrixByColCriteria(matrix m, int (*criteria)(const int *, int)) {
    int *criteriaArray = (int *) malloc(sizeof(int) * m.nCols);

    for (int i = 0; i < m.nCols; i++) {
        int *col = (int *) malloc(sizeof(int) * m.nRows);
        for (int j = 0; j < m.nRows; j++)
            col[j] = m.values[j][i];
        criteriaArray[i] = criteria(col, m.nRows);

        free(col);
    }

    for (int i = 1; i < m.nCols; i++) {
        int t = criteriaArray[i];
        int j = i - 1;
        while (j >= 0 && t < criteriaArray[j]) {
            criteriaArray[j + 1] = criteriaArray[j];
            swapColumns(m, j + 1, j);
            j--;
        }

        criteriaArray[j + 1] = t;
    }

    free(criteriaArray);
}

void choiceSortColsMatrixByColCriteria(matrix m, int (*criteria)(const int *, int)) {
    int *criteriaArray = (int *) malloc(sizeof(int) * m.nCols);

    for (int i = 0; i < m.nCols; i++) {
        int *col = (int *) malloc(sizeof(int) * m.nRows);
        for (int j = 0; j < m.nRows; j++)
            col[j] = m.values[j][i];
        criteriaArray[i] = criteria(col, m.nRows);

        free(col);
    }

    for (int i = 0; i < m.nCols - 1; i++) {
        int minPos = i;
        for (int j = i + 1; j < m.nCols; j++)
            if (criteriaArray[j] < criteriaArray[minPos])
                minPos = j;
        swapElement(&criteriaArray[i], &criteriaArray[minPos]);
        swapColumns(m, i, minPos);
    }

    free(criteriaArray);
}

bool isSquareMatrix(matrix m) {
    return m.nRows == m.nCols;
}

bool twoMatricesEqual(matrix m1, matrix m2) {
    if (m1.nRows != m2.nRows || m1.nCols != m2.nCols)
        return false;
    else {
        for (int i = 0; i < m1.nRows; i++)
            for (int j = 0; j < m1.nCols; j++)
                if (m1.values[i][j] != m2.values[i][j])
                    return false;
    }

    return true;
}

bool isEMatrix(matrix m) {
    if (isSquareMatrix(m) == 0)
        return false;
    else {
        for (int i = 0; i < m.nRows; i++)
            for (int j = 0; j < m.nCols; j++)
                if (i == j) {
                    if (m.values[i][j] != 1)
                        return false;
                } else if (m.values[i][j] != 0)
                    return false;
    }

    return true;
}

bool isSymmetricMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++)
        for (int j = i; j < m.nCols; j++)
            if (m.values[i][j] != m.values[j][i])
                return false;

    return true;
}

void swapElement(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void swapElementDouble(double *a, double *b) {
    double t = *a;
    *a = *b;
    *b = t;
}

void transposeSquareMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++)
        for (int j = i; j < m.nRows; j++)
            swapElement(&m.values[i][j], &m.values[j][i]);
}

position getMinValuePos(matrix m) {
    position posMinElement = (position) {0, 0};

    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            if (m.values[i][j] < m.values[posMinElement.rowIndex][posMinElement.colIndex]) {
                posMinElement.rowIndex = i;
                posMinElement.colIndex = j;
            }

    return posMinElement;
}

position getMaxValuePos(matrix m) {
    position posMaxElement = (position) {0, 0};

    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++) {
            if (m.values[i][j] > m.values[posMaxElement.rowIndex][posMaxElement.colIndex]) {
                posMaxElement.rowIndex = i;
                posMaxElement.colIndex = j;
            }
        }

    return posMaxElement;
}

matrix createMatrixFromArray(const int *a, int nRows, int nCols) {
    matrix m = getMemMatrix(nRows, nCols);

    int k = 0;
    for (int i = 0; i < nRows; i++)
        for (int j = 0; j < nCols; j++)
            m.values[i][j] = a[k++];

    return m;
}

matrix *createArrayOfMatrixFromArray(const int *values, int nMatrices, int nRows, int nCols) {
    matrix *ms = getMemArrayOfMatrices(nMatrices, nRows, nCols);

    int l = 0;
    for (int k = 0; k < nMatrices; k++)
        for (int i = 0; i < nRows; i++)
            for (int j = 0; j < nCols; j++)
                ms[k].values[i][j] = values[l++];

    return ms;
}

int countZeroRows(matrix m) {
    int totalZeroRows = 0;
    for (int i = 0; i < m.nRows; i++) {
        int elementDoNotZero = 1;
        int j = 0;
        while (j < m.nCols && elementDoNotZero == 1) {
            if (m.values[i][j] != 0)
                elementDoNotZero--;
            j++;
        }
        if (elementDoNotZero == 1)
            totalZeroRows++;
    }

    return totalZeroRows;
}
