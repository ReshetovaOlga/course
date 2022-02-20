//
// Created by elen_ on 20.02.2022.
//

#include "matrix_tasks.h"

// 1
// Дана квадратная матрица,
// все элементы которой различны.
// Поменять местами строки,
// в которых находятся максимальный и минимальный элементы.
void swapRowsWithMaxAndMinElement(matrix m){
    position minPos = getMinValuePos(m);
    position maxPos = getMaxValuePos(m);
    swapRows(m, minPos.rowIndex, maxPos.rowIndex);
}