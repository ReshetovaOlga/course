#include "libs/data_structures/matrix/matrix.h"
#include <stdio.h>
#include <malloc.h>
#include <assert.h>

void test_countZeroRows_withZeroRows() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 1, 0,
                    0, 0, 0,
                    0, 0, 1,
                    0, 0, 0,
                    0, 1, 1,
            },
            5, 3
    );

    assert (countZeroRows(m) == 2);

    freeMemMatrix(m);
}

void test_countZeroRows_allZeroRows() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    0, 0, 0,
                    0, 0, 0,
                    0, 0, 0,
                    0, 0, 0,
                    0, 0, 0,
            },
            5, 3
    );

    assert (countZeroRows(m) == 5);

    freeMemMatrix(m);
}

void test_countZeroRows_withoutZeroRows() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    0, 0, 0,
                    0, 0, 0,
                    0, 0, 0,
                    0, 0, 0,
                    0, 0, 0,
            },
            5, 3
    );

    assert (countZeroRows(m) == 5);

    freeMemMatrix(m);
}

void test_countZeroRows() {
    test_countZeroRows_withoutZeroRows();
    test_countZeroRows_withZeroRows();
    test_countZeroRows_allZeroRows();
}

void test_getMaxValuePos() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    0, 0, 0,
                    0, 0, 0,
                    0, 0, 2,
                    0, 0, 0,
                    0, 1, 0,
            },
            5, 3
    );

    position check = getMaxValuePos(m);

    assert (check.rowIndex == 2 && check.colIndex == 2);

    freeMemMatrix(m);
}


void test_getMinValuePos() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 1, 1,
                    0, 1, 1,
                    1, 1, 2,
                    1, 1, 1,
                    1, 1, 1,
            },
            5, 3
    );

    position check = getMinValuePos(m);

    assert (check.rowIndex == 1 && check.colIndex == 0);

    freeMemMatrix(m);
}

void test_transposeSquareMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 4, 4,
                    5, 2, 4,
                    5, 5, 3,

            },
            3, 3
    );

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1, 5, 5,
                    4, 2, 5,
                    4, 4, 3,

            },
            3, 3
    );

    transposeSquareMatrix(m1);

    assert(twoMatricesEqual(m1, m2) == 1);

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_isEMatrix_true() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 0, 0,
                    0, 1, 0,
                    0, 0, 1,
            },
            3, 3
    );

    assert(isEMatrix(m1) == 1);

    freeMemMatrix(m1);
}

void test_isEMatrix_false() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 0, 0,
                    0, 1, 0,
                    0, 1, 1,
            },
            3, 3
    );

    assert(isEMatrix(m1) == 0);

    freeMemMatrix(m1);
}

void test_isEMatrix() {
    test_isEMatrix_false();
    test_isEMatrix_true();
}

void test_isSymmetricMatrix_true() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    2, 1, 0,
                    3, 0, 1,
            },
            3, 3
    );

    assert(isSymmetricMatrix(m1) == 1);

    freeMemMatrix(m1);
}

void test_isSymmetricMatrix_false() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    2, 1, 0,
                    4, 0, 1,
            },
            3, 3
    );

    assert(isSymmetricMatrix(m1) == 0);

    freeMemMatrix(m1);
}

void test_isSymmetricMatrix() {
    test_isSymmetricMatrix_false();
    test_isSymmetricMatrix_true();
}


void test_isSquareMatrix_true() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    2, 1, 0,
                    3, 0, 1,
            },
            3, 3
    );

    assert(isSquareMatrix(m1) == 1);

    freeMemMatrix(m1);
}

void test_isSquareMatrix_false() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    2, 1, 0,
                    4, 0, 1,
                    4, 4, 4,
            },
            4, 3
    );

    assert(isSquareMatrix(m1) == 0);

    freeMemMatrix(m1);
}

void test_isSquareMatrix() {
    test_isSquareMatrix_false();
    test_isSquareMatrix_true();
}


void test_swapRows_thereIsAnExchange() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 1, 1,
                    2, 2, 2,
                    3, 3, 3,

            },
            3, 3
    );

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    2, 2, 2,
                    1, 1, 1,
                    3, 3, 3,

            },
            3, 3
    );

    swapRows(m1, 0, 1);

    assert(twoMatricesEqual(m1, m2) == 1);

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}


void test_swapRows_thereIsNoExchange() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 1, 1,
                    2, 2, 2,
                    3, 3, 3,

            },
            3, 3
    );

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1, 1, 1,
                    2, 2, 2,
                    3, 3, 3,

            },
            3, 3
    );

    swapRows(m1, 0, 0);

    assert(twoMatricesEqual(m1, m2) == 1);

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_swapRows() {
    test_swapRows_thereIsNoExchange();
    test_swapRows_thereIsAnExchange();
}

int sumElementOfArray(const int *array, int arraySize) {
    int sum = 0;
    for (int i = 0; i < arraySize; i++)
        sum += array[i];
    return sum;
}

// выполняет сортировку вставками строк матрицы m
// по неубыванию значения функции criteria
// применяемой для строк
void test_insertionSortRowsMatrixByRowCriteria() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 2, 1,
                    2, 2, 2,
                    1, 2, 1,

            },
            3, 3
    );

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1, 2, 1,
                    1, 2, 1,
                    2, 2, 2,

            },
            3, 3
    );

    insertionSortRowsMatrixByRowCriteria(m1, sumElementOfArray);

    assert(twoMatricesEqual(m1, m2) == 1);

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_insertionSortColsMatrixByColCriteria() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 3, 3,
                    1, 2, 2,
                    1, 2, 1,

            },
            3, 3
    );

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1, 3, 3,
                    1, 2, 2,
                    1, 1, 2,

            },
            3, 3
    );

    insertionSortColsMatrixByColCriteria(m1, sumElementOfArray);

    assert(twoMatricesEqual(m1, m2) == 1);

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test() {
    test_countZeroRows();
    test_getMaxValuePos();
    test_getMinValuePos();
    test_transposeSquareMatrix();
    test_isEMatrix();
    test_isSymmetricMatrix();
    test_isSquareMatrix();
    test_swapRows();
    test_insertionSortRowsMatrixByRowCriteria();
    test_insertionSortColsMatrixByColCriteria();
}


int main() {
    test();

    return 0;
}