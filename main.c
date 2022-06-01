#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>

typedef struct matrix {
    int **values;// элементы матрицы
    int nRows;// количество рядов
    int nCols;// количество столбцов
}matrix;

typedef struct position{
    int rowIndex;
    int colIndex;
}position;

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

void swapElement(matrix m) {
    position maxPos = getMaxValuePos(m);

}

int main() {

    return 0;
}