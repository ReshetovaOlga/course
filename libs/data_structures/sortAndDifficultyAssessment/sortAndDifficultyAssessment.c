//
// Created by elen_ on 09.03.2022.
//

#include "sortAndDifficultyAssessment.h"
#include "../../algorithms/array/array.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

bool isOrdered(const int *a, size_t n) {
    for (int i = 1; i < n; i++)
        if (a[i - 1] > a[i])
            return false;
    return true;
}



void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void bubbleSort(int *a, size_t size) {
    for (size_t i = 0; i < size - 1; i++)
        for (size_t j = size - 1; j > i; j--)
            if (a[j - 1] > a[j])
                swap(&a[j - 1], &a[j]);
}

void selectionSort(int *a, size_t size) {
    for (int i = 0; i < size - 1; i++) {
        int minPos = i;
        for (int j = i + 1; j < size; j++)
            if (a[j] < a[minPos])
                minPos = j;

        swap(&a[i], &a[minPos]);
    }
}

void insertionSort(int *a, size_t size) {
    for (int i = 1; i < size; i++) {
        int t = a[i];
        int j = i;
        while (j > 0 && a[j - 1] > t) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = t;
    }
}

void combSort(int *a, size_t size) {
    size_t step = size;
    int swapped = 1;
    while (step > 1 || swapped) {
        if (step > 1)
            step /= 1.24733;
        swapped = 0;
        for (size_t i = 0, j = i + step; j < size; ++i, ++j)
            if (a[i] > a[j]) {
                swap(&a[i], &a[j]);
                swapped = 1;
            }
    }
}


void sortShell(int *a, size_t size) {
    int range = size / 2;
    while (range > 0) {
        for (int i = 1; i < size; i += range) {
            int t = a[i];
            int j = i;
            while (j > 0 && a[j - 1] > t) {
                a[j] = a[j - 1];
                j--;
            }
            a[j] = t;
        }
        range /= 2;
    }
}

void getPrefixSums(int *a, int n) {
    int prev = a[0];
    *a = 0;
    for (int i = 1; i < n; i++) {
        int t = a[i];
        a[i] = prev + a[i - 1];
        prev = t;
    }
}

void digitSort(int *a, size_t size) {
    int buffer[size];

    const int STEP = 8;
    const int MASK = 0b11111111; // MASK = 255 = 2^8-1
    for (int byte = 0; byte < sizeof(int); byte++) {//цикл размером 4 (так как в int 4 байта)
        int values[UCHAR_MAX + 1] = {0};// создает массив размером 256,
        // заполненый нулями; UCHAR_MAX = 255


        for (int i = 0; i < size; i++) {
            int curByte; // текущий байт
            if (byte + 1 == sizeof(int)) { // если последний (то-есть первый)
                // байт чисел цикла (он у всех наступает одинаково,
                // так как все числа интовые, их размер равен 4 байтам)
                curByte = ((a[i] >> (byte * STEP)) + CHAR_MAX + 1) & MASK; //CHAR_MAX = 127
                // (a[i] >> (byte * STEP)
                //
            }
            else {
                curByte = (a[i] >> (byte * STEP)) & MASK;
            }
            values[curByte]++;
        }


        getPrefixSums(values, UCHAR_MAX + 1);

        for (size_t i = 0; i < size; i++) {
            int curByte; // текущий байт
            if (byte + 1 == sizeof(int)) {
                curByte = ((a[i] >> (byte * STEP)) + CHAR_MAX + 1) & MASK;
            } else {
                curByte = (a[i] >> (byte * STEP)) & MASK;
            }

            buffer[values[curByte]++] = a[i];
        }

        memcpy(a, buffer, sizeof(int) * size);
    }
}

void generateRandomArray(int *a, size_t n){
    srand(time(0));
     for (int i=0; i<n; i++)
         a[i]=INT_MIN/2+rand();
}

void generateOrderedArray(int *a, size_t n){
    for(int i=0;i<n; i++)
        a[i]=i;
}

void generateOrderedBackwards(int *a, size_t n){
    int value=n-1;
    for(int i=0; i<n; i++)
        a[i]=value--;

}