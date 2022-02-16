//#include "libs/data_structures/matrix/matrix.h"
#include <stdio.h>
#include <malloc.h>

typedef struct matrix {
    int **values;// элементы матрицы
    int nRows;// количество рядов
    int nCols;// количество столбцов
}matrix;

void swapElement(int *a, int *b){
    int t=*a;
    *a=*b;
    *b=t;
}

void transposeSquareMatrix(matrix m){
    for (int i=0; i<m.nRows; i++)
        for (int j=i; j<m.nRows; j++)
            swapElement(&m.values[i][j], &m.values[j][i]);
}

matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);
    for (int i = 0; i < nRows; i++)
        values[i] = (int *) malloc(sizeof(int) * nCols);
    return (matrix) {values, nRows, nCols};
}

void inputMatrix(matrix *m) {
    for (int i = 0; i < m->nRows; i++)
        for (int j = 0; j < m->nCols; j++)
            scanf("%d", &m->values[i][j]);
}

void inputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        inputMatrix(&ms[i]);
}

void outputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++)
            printf("%d ", m.values[i][j]);
        printf("\n");
    }
    printf("\n");
}

int main() {
    matrix m=getMemMatrix(3,3);
    inputMatrix(&m);
    outputMatrix(m);
    transposeSquareMatrix(m);
    outputMatrix(m);
    return 0;
}