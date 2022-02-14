#include "libs/data_structures/matrix/matrix.h"

int main() {
//    matrix m=getMemMatrix(3,3);
//    inputMatrix(&m);
//    outputMatrix(m);
    matrix *ms=getMemArrayOfMatrices(2,3,3);
    inputMatrices(ms, 2);
    outputMatrices(ms,2);
    return 0;
}