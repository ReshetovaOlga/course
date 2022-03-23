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

void shellSort(int *array, size_t size) {
    for (int s = size / 2; s > 0; s /= 2) {
        for (int i = s; i < size; ++i) {
            for (int j = i - s; j >= 0 && array[j] > array[j + s]; j -= s) {
                int temp = array[j];
                array[j] = array[j + s];
                array[j + s] = temp;
            }
        }
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
    int *buffer = malloc(sizeof(int) * size);

    const int STEP = 8;
    const int MASK = 0b11111111;
    for (int byte = 0; byte < sizeof(int); byte++) {
        int values[UCHAR_MAX + 1] = {0};

        for (int i = 0; i < size; i++) {
            int curByte;
            if (byte + 1 == sizeof(int)) {
                curByte = ((a[i] >> (byte * STEP)) + CHAR_MAX + 1) & MASK;
            } else {
                curByte = (a[i] >> (byte * STEP)) & MASK;
            }
            values[curByte]++;
        }


        getPrefixSums(values, UCHAR_MAX + 1);

        for (size_t i = 0; i < size; i++) {
            int curByte;
            if (byte + 1 == sizeof(int)) {
                curByte = ((a[i] >> (byte * STEP)) + CHAR_MAX + 1) & MASK;
            } else {
                curByte = (a[i] >> (byte * STEP)) & MASK;
            }

            buffer[values[curByte]++] = a[i];
        }

        memcpy(a, buffer, sizeof(int) * size);
    }
    free(buffer);
}


void generateRandomArray(int *a, size_t n) {
    srand(time(0));
    for (int i = 0; i < n; i++)
        a[i] = INT_MIN / 2 + rand();
}

void generateOrderedArray(int *a, size_t n) {
    for (int i = 0; i < n; i++)
        a[i] = i;
}

void generateOrderedBackwards(int *a, size_t n) {
    int value = n - 1;
    for (int i = 0; i < n; i++)
        a[i] = value--;

}

long long sortNCompBubbleSort(int *a, size_t size) {
    long long nComps = 0;
    for (size_t i = 0; ++nComps && i < size - 1; i++)
        for (size_t j = size - 1; ++nComps && j > i; j--)
            if (++nComps && a[j - 1] > a[j])
                swap(&a[j - 1], &a[j]);
    return nComps;
}

long long sortNCompSelectionSort(int *a, size_t size) {
    long long nComps = 0;
    for (int i = 0; ++nComps && i < size - 1; i++) {
        int minPos = i;
        for (int j = i + 1; ++nComps && j < size; j++)
            if (++nComps && a[j] < a[minPos])
                minPos = j;

        swap(&a[i], &a[minPos]);
    }

    return nComps;
}

long long sortNCompInsertionSort(int *a, size_t size) {
    long long nComps = 0;
    for (int i = 1; ++nComps && i < size; i++) {
        int t = a[i];
        int j = i;
        while (++nComps && j > 0 && a[j - 1] > t) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = t;
    }
    return nComps;
}

long long sortNCompCombSort(int *a, size_t size) {
    long long nComps = 0;
    size_t step = size;
    int swapped = 1;
    while (++nComps && (step > 1 || swapped)) {
        if (++nComps && step > 1)
            step /= 1.24733;
        swapped = 0;
        for (size_t i = 0, j = i + step; ++nComps && j < size; ++i, ++j)
            if (++nComps && (a[i] > a[j])) {
                swap(&a[i], &a[j]);
                swapped = 1;
            }
    }
    return nComps;
}

long long sortNCompShellSort(int *array, size_t size) {
    long long nComps = 0;
    for (int s = size / 2; ++nComps && s > 0; s /= 2) {
        for (int i = s; ++nComps && i < size; ++i) {
            for (int j = i - s; ++nComps && j >= 0 && array[j] > array[j + s]; j -= s) {
                swap(&array[j], &array[j + s]);
            }
        }
    }
    return nComps;
}

void getPrefixSumsNComps(int *a, int n, long long *nComps) {
    int prev = a[0];
    *a = 0;
    for (int i = 1; ++nComps && i < n; i++) {
        int t = a[i];
        a[i] = prev + a[i - 1];
        prev = t;
    }
}

long long sortNCompDigitSort(int *a, size_t size) {
    int *buffer = malloc(sizeof(int) * size);

    long long nComps = 0;
    const int STEP = 8;
    const int MASK = 0b11111111;
    for (int byte = 0; ++nComps && byte < sizeof(int); byte++) {
        int values[UCHAR_MAX + 1] = {0};

        for (int i = 0; ++nComps && i < size; i++) {
            int curByte;
            if (++nComps && byte + 1 == sizeof(int))
                curByte = ((a[i] >> (byte * STEP)) + CHAR_MAX + 1) & MASK;
            else {
                curByte = (a[i] >> (byte * STEP)) & MASK;
            }
            values[curByte]++;
        }


        getPrefixSumsNComps(values, UCHAR_MAX + 1, &nComps);

        for (size_t i = 0; ++nComps && i < size; i++) {
            int curByte;
            if (++nComps && byte + 1 == sizeof(int)) {
                curByte = ((a[i] >> (byte * STEP)) + CHAR_MAX + 1) & MASK;
            } else {
                curByte = (a[i] >> (byte * STEP)) & MASK;
            }

            buffer[values[curByte]++] = a[i];
        }

        memcpy(a, buffer, sizeof(int) * size);
    }
    free(buffer);

    return nComps;
}

