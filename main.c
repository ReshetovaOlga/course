#include "libs/data_structures/matrix_tasks/matrix_tasks.h"
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


void test_choiceSortColsMatrixByColCriteria() {
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

    choiceSortColsMatrixByColCriteria(m1, sumElementOfArray);

    assert(twoMatricesEqual(m1, m2) == 1);

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}


void test_lib() {
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
    test_choiceSortColsMatrixByColCriteria();
}


void test_swapRowsWithMaxAndMinElement() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 9,

            },
            3, 3
    );

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    7, 8, 9,
                    4, 5, 6,
                    1, 2, 3,

            },
            3, 3
    );

    swapRowsWithMaxAndMinElement(m1);

    assert(twoMatricesEqual(m1, m2) == 1);

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_sortRowsByMaxElement() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    0, 2, 0,
                    3, 1, 1,
                    0, 0, 1,

            },
            3, 3
    );

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    0, 0, 1,
                    0, 2, 0,
                    3, 1, 1,

            },
            3, 3
    );

    sortRowsByMaxElement(m1);

    assert(twoMatricesEqual(m1, m2) == 1);

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_sortColsByMinElement() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 5, 2, 5, 3, 4,
                    2, 5, 1, 8, 5, 7,
                    6, 0, 4, 5, 8, 4,

            },
            3, 6
    );

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    5, 2, 3, 3, 4, 5,
                    5, 1, 2, 5, 7, 8,
                    0, 4, 6, 8, 4, 5,

            },
            3, 6
    );

    sortColsByMinElement(m1);

    assert(twoMatricesEqual(m1, m2) == 1);

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_getSquareOfMatrixIfSymmetric() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 5, 2,
                    2, 5, 1,
                    6, 0, 4,

            },
            3, 3
    );

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    31, 40, 19,
                    22, 35, 13,
                    42, 30, 28,

            },
            3, 3
    );

    getSquareOfMatrixIfSymmetric(&m1);

    assert(twoMatricesEqual(m1, m2) == 1);

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}


void test_transposeIfMatrixHasNotEqualSumOfRows_notEqual() {
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
                    1, 2, 3,
                    1, 2, 3,
                    1, 2, 3,

            },
            3, 3
    );

    transposeIfMatrixHasNotEqualSumOfRows(m1);

    assert(twoMatricesEqual(m1, m2) == 1);

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_transposeIfMatrixHasNotEqualSumOfRows_equal() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 1, 1,
                    1, 1, 1,
                    3, 3, 3,

            },
            3, 3
    );

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1, 1, 1,
                    1, 1, 1,
                    3, 3, 3,

            },
            3, 3
    );

    transposeIfMatrixHasNotEqualSumOfRows(m1);

    assert(twoMatricesEqual(m1, m2) == 1);

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_transposeIfMatrixHasNotEqualSumOfRows() {
    test_transposeIfMatrixHasNotEqualSumOfRows_equal();
    test_transposeIfMatrixHasNotEqualSumOfRows_notEqual();
}

void test_isMutuallyInverseMatrices() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 1, 1,
                    1, 2, 1,
                    1, 1, 2,

            },
            3, 3
    );

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    3, -1, -1,
                    -1, 1, -0,
                    -1, 0, 1,

            },
            3, 3
    );

    assert(isMutuallyInverseMatrices(m1, m2) == 1);

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_findSumOfMaxesOfPseudoDiagonal() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 2, 5, 4,
                    1, 3, 6, 3,
                    3, 2, 1, 2,

            },
            3, 4
    );

    int needRes = 20;

    assert(findSumOfMaxesOfPseudoDiagonal(m1) == needRes);
}

void test_getMinInArea() {

    matrix m1 = createMatrixFromArray(
            (int[]) {
                    10, 7, 5, 6,
                    3, 11, 8, 9,
                    4, 1, 12, 2,

            },
            3, 4
    );

    int needRes = 5;

    assert(getMinInArea(m1) == needRes);

};


void test_sortByDistances() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 3, 3,
                    2, 2, 2,
                    1, 1, 1,

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

    sortByDistances(m1);

    assert(twoMatricesEqual(m1, m2) == 1);

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}


void test_countEqClassesByRowsSum() {

    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 7,
                    2, 7,
                    4, 5,
                    4, 3,
                    1, 6,
                    8, 0,


            },
            6, 2
    );

    int needRes = 3;

    assert(countEqClassesByRowsSum(m1) == needRes);

};

void test_getNSpecialElement() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 5, 5, 4,
                    2, 3, 6, 7,
                    12, 2, 1, 2,


            },
            3, 4
    );

    int needRes = 2;

    assert(getNSpecialElement(m1) == needRes);

};


void test_swapPenultimateRow() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 2, 2,
                    2, 2, 2,
                    3, 3, 3,

            },
            3, 3
    );

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1, 2, 2,
                    1, 2, 3,
                    3, 3, 3,

            },
            3, 3
    );

    swapPenultimateRow(m1);

    assert(twoMatricesEqual(m1, m2) == 1);

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_countNonDescendingRowsMatrices() {
    matrix *ms = createArrayOfMatrixFromArray(
            (int[]) {
                    7, 1,
                    1, 1,

                    1, 6,
                    2, 2,

                    5, 4,
                    2, 3,

                    1, 3,
                    7, 9,
            }, 4, 2, 2
    );

    int needRez = 2;

    assert(countNonDescendingRowsMatrices(ms, 4) == needRez);

    freeMemMatrices(ms, 4);
}


void test_tasks() {
    test_swapRowsWithMaxAndMinElement();
    test_sortRowsByMaxElement();
    test_sortColsByMinElement();
    test_getSquareOfMatrixIfSymmetric();
    test_transposeIfMatrixHasNotEqualSumOfRows();
    test_isMutuallyInverseMatrices();
    test_findSumOfMaxesOfPseudoDiagonal();
    test_getMinInArea();
    test_sortByDistances();
    test_countEqClassesByRowsSum();
    test_getNSpecialElement();
    test_swapPenultimateRow();
    test_countNonDescendingRowsMatrices();
}

void test() {
    test_lib();
    test_tasks();
}

int main() {
    test();
    matrix *ms1 = createArrayOfMatrixFromArray(
            (int[]) {
                    0, 0,
                    1, 1,

                    0, 0,
                    0, 1,

                    0, 1,
                    1, 0,

                    1, 3,
                    7, 9,
            }, 4, 2, 2
    );

    printMatrixWithMaxZeroRows(ms1, 4);

    matrix *ms2 = createArrayOfMatrixFromArray(
            (int[]) {
                    7, 1,
                    1, 1,

                    1, -5,
                    2, 2,

                    5, 4,
                    2, 3,

                    1, 3,
                    7, 9,
            }, 4, 2, 2
    );

    printMatrixWithMinMaxAboutModuleInMatrix(ms2, 4);

    freeMemMatrices(ms2, 4);
    freeMemMatrices(ms1, 4);

    return 0;
}
