#include "libs/data_structures/sortAndDifficultyAssessment/sortAndDifficultyAssessment.h"
#include "libs/algorithms/array/array.h"
#include <stdio.h>
#define SIZE 1000000

void outputArray(int *a, size_t size) {
    for (int i = 0; i < size; i++)
        printf("%d, ", a[i]);
    printf("\n");
}


void checkTime(void (*sortFunc )(int *, size_t),
               void (*generateFunc )(int *, size_t),
               size_t size, char *experimentName) {
    static size_t runCounter = 1;

// генерация последовательности
    static int *innerBuffer = NULL;
    if (innerBuffer == NULL) {
        innerBuffer = malloc(sizeof(int) * SIZE);
    }

    generateFunc(innerBuffer, size);
    printf("Run #%zu| ", runCounter++);
    printf("Name: %s\n", experimentName);
// замер времени
    double time;
    TIME_TEST ({
                   sortFunc(innerBuffer, size);
               }, time)
// результаты замера
    printf("Status: ");
    if (isOrdered(innerBuffer, size)) {
        printf("OK! Time: %.3f s.\n", time);

// запись в файл
        char filename[256];
        sprintf(filename, "./data/%s.csv", experimentName);
        FILE *f = fopen(filename, "a");
        if (f == NULL) {
            printf("FileOpenError %s", filename);
            exit(1);
        }
        fprintf(f, "%zu; %.3f\n", size, time);
        fclose(f);
    } else {
        printf("Wrong!\n");

// вывод массива, который не смог быть отсортирован
        outputArray_(innerBuffer, size);

        exit(1);
    }
}


void checkTime1(void (*sortFunc )(int *, size_t),
               void (*generateFunc )(int *, size_t),
               size_t size, char *experimentName) {
    static size_t runCounter = 1;
    // генерация последовательности
    static int innerBuffer[1000000];
    generateFunc(innerBuffer, size);
    printf("Run #%zu| ", runCounter++);
    printf("Name: %s\n", experimentName);

    double time;
    TIME_TEST({
                  sortFunc(innerBuffer, size);
              }, time)

    printf("status: ");
    if (isOrdered(innerBuffer, size))
        if (isOrdered(innerBuffer, size)) {
            printf("OK! Time: %.3f s.\n", time);

            // запись в файл
            char filename[256];
            sprintf(filename, "./data/%s.csv", experimentName);
            FILE *f = fopen(filename, "a");
            if (NULL == f) {
                printf("FileOpenError %s", filename);
                exit(1);
            }
            fprintf(f, "%zu; %.3f\n", size, time);
            fclose(f);
        } else {
            printf("Wrong !\n");

            // вывод массива, который не смог быть отсортирован
            outputArray_(innerBuffer, size);

            exit(1);
        }
}


void timeExperiment1() {
    // описание функций сортировки
    SortFunc sorts[] = {
            {selectionSort, " selectionSort "},
            {insertionSort, " insertionSort "},
//            {bubbleSort, "bubbleSort"},
            {combSort,"combSort"},
            {sortShell, "sortShell"},
            {digitSort, "digitSort"},
            // вы добавите свои сортировки
    };
    const unsigned FUNCS_N = ARRAY_SIZE (sorts);

    // описание функций генерации
    GeneratingFunc generatingFuncs[] = {
            // генерируется случайный массив
            {generateRandomArray,      "random"},
            // генерируется массив 0, 1, 2, ..., n - 1
            {generateOrderedArray,     "ordered"},
            // генерируется массив n - 1, n - 2, ..., 0
            {generateOrderedBackwards, "orderedBackwards"}
    };
    const unsigned CASES_N = ARRAY_SIZE (generatingFuncs);

    // запись статистики в файл
    for (size_t size = 10000; size <= 100000; size += 10000) {
        printf("------------------------------\n");
        printf("Size: %d\n", size);
        for (int i = 0; i < FUNCS_N; i++) {
            for (int j = 0; j < CASES_N; j++) {
                // генерация имени файла
                static char filename[128];
                sprintf(filename, "%s_%s_time",
                        sorts[i].name, generatingFuncs[j].name);
                checkTime(sorts[i].sort,
                          generatingFuncs[j].generate,
                          size, filename);
            }
        }
        printf("\n");
    }
}


void timeExperiment() {
// описание функций сортировки
    SortFunc sorts[] = {
            {selectionSort, " selectionSort "},
            {insertionSort, " insertionSort "},
            {bubbleSort, "bubbleSort"},
            {combSort,"combSort"},
            {sortShell, "sortShell"},
//            {digitSort, "digitSort"},
            // вы добавите свои сортировки
    };
    const unsigned FUNCS_N = ARRAY_SIZE (sorts);

// описание функций генерации
    GeneratingFunc generatingFuncs[] = {
// генерируется случайный массив
            {generateRandomArray, " random "},
// генерируется массив 0, 1, 2, ..., n - 1
            {generateOrderedArray, " ordered "},
// генерируется массив n - 1, n - 2, ..., 0
            {generateOrderedBackwards, " orderedBackwards "}
    };
    const unsigned CASES_N = ARRAY_SIZE (generatingFuncs);

// запись статистики в файл
    for (size_t size = 10000; size <= 100000; size += 10000) {
        printf("------------------------------\n");
        printf("Size: %d\n", size);
        for (int i = 0; i < FUNCS_N; i++) {
            for (int j = 0; j < CASES_N; j++) {
// генерация имени файла
                static char filename[128];
                sprintf(filename, "%s_%s_time ",
                        sorts[i].name, generatingFuncs[j].name);
                checkTime(sorts[i].sort,
                          generatingFuncs[j].generate,
                          size, filename);
            }
        }
        printf("\n");
    }
}


int main() {
    timeExperiment();

    return 0;
}