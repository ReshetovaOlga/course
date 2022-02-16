#include "libs/data_structures/matrix/matrix.h"
#include <stdio.h>
#include <malloc.h>

void SwapRowsWithMaxiAndMinElements(matrix m){
    position max= getMaxValuePos(m);
    position min= getMinValuePos(m);
    swapRows(m, max.rowIndex, min.rowIndex);
}

//находит максимальный элемент массива а размера n
int getMax(const int *a, int n){
    int max = a[0];
    for (int i=1; i<n; i++)
        if()
}


int main() {
    matrix m=getMemMatrix(3,3);
    inputMatrix(&m);
    position max= getMaxValuePos(m);
    position min= getMinValuePos(m);
    printf("%d\n", max.rowIndex);
    outputMatrix(m);
    return 0;
}