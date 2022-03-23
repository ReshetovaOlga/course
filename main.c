#include "libs/data_structures/sortAndDifficultyAssessment/sortAndDifficultyAssessment.h"
#include "libs/algorithms/array/array.h"
#include <stdio.h>

void checkTime(void (*sortFunc )(int *, size_t),
               void (*generateFunc )(int *, size_t),
               size_t size, char *experimentName) {
    static size_t runCounter = 1;

    int *innerBuffer = (int *) malloc(sizeof(int) * size);
    generateFunc(innerBuffer, size);
    printf("Run #%zu| ", runCounter++);
    printf("Name: %s\n", experimentName);

    double time;
    TIME_TEST ({
                   sortFunc(innerBuffer, size);
               }, time)
    printf("Status: ");
    if (isOrdered(innerBuffer, size)) {
        printf("OK! Time: %.3f s.\n", time);

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

        outputArray_(innerBuffer, size);

        exit(1);
    }
    free(innerBuffer);
}

void checkNComps(long long (*sortFunc)(int *, size_t), void (*generateFunc)(int *, size_t),
                 size_t size, char *experimentName) {
    static size_t runCounter = 1;

    static int innerBuffer[1000000];
    generateFunc(innerBuffer, size);
    printf("Run #%zu| ", runCounter++);
    printf(" Name : %s\n", experimentName);

    long long nComps = sortFunc(innerBuffer, size);

    printf(" Status : ");
    if (isOrdered(innerBuffer, size)) {
        printf("OK! Number of comparisons : %lld\n", nComps);

        char filename[256];
        sprintf(filename, "./data/%s.csv", experimentName);
        FILE *f = fopen(filename, "a");
        if (f == NULL) {
            printf(" FileOpenError %s", filename);
            exit(1);
        }
        fprintf(f, "%zu; %lld\n", size, nComps);
        fclose(f);
    } else {
        printf(" Wrong!\n");

        outputArray_(innerBuffer, size);

        exit(1);
    }
}

void timeExperimentNComps() {
    SortFuncNSorts sorts[] = {
//            {sortNCompSelectionSort, "sortNCompSelectionSort"},
//            {sortNCompBubbleSort, "sortNCompBubbleSort"},
//            {sortNCompInsertionSort, "sortNCompInsertionSort"},
//            {sortNCompCombSort, "sortNCompCombSort"},
//            {sortNCompShellSort, "sortNCompShellSort"},
            {sortNCompDigitSort, "sortNCompDigitSort"},

    };
    const unsigned FUNCS_N = ARRAY_SIZE(sorts);
    GeneratingFunc generatingFuncs[] = {
            {generateRandomArray,      "random"},
            {generateOrderedArray,     "ordered"},
            {generateOrderedBackwards, "orderedBackwards"}
    };
    const unsigned CASES_N = ARRAY_SIZE(generatingFuncs);

    for (size_t size = 10000; size <= 100000; size += 10000) {
        printf("-----------------------------------------\n");
        printf(" Size : %d\n", size);
        for (int i = 0; i < FUNCS_N; i++) {
            for (int j = 0; j < CASES_N; j++) {
                static char filename[128];
                sprintf(filename, "%s_%s_n_comps ",
                        sorts[i].name, generatingFuncs[j].name);
                checkNComps(sorts[i].sort,
                            generatingFuncs[j].generate,
                            size, filename);
            }
        }
        printf("\n");
    }
}


void timeExperiment() {
    SortFunc sorts[] = {
            {bubbleSort,    "bubbleSort"},
            {selectionSort, "selectionSort"},
            {insertionSort, "insertionSort"},
//            {combSort,      "combSort"},
 //           {shellSort,     "shellSort"},
            {digitSort,     "digitSort"},
    };
    const unsigned FUNCS_N = ARRAY_SIZE (sorts);

    GeneratingFunc generatingFuncs[] = {
 //           {generateRandomArray,      " random "},
            {generateOrderedArray,     " ordered "},
//            {generateOrderedBackwards, " orderedBackwards "}
    };
    const unsigned CASES_N = ARRAY_SIZE (generatingFuncs);

/*
    for (size_t size = 10000; size <= 100000; size += 10000) {
        printf("------------------------------\n");
        printf("Size: %d\n", size);
        for (int i = 0; i < FUNCS_N - 3; i++) {
            for (int j = 0; j < CASES_N; j++) {
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


    for (size_t size = 40000; size <= 140000; size += 10000) {
        printf("------------------------------\n");
        printf("Size: %d\n", size);
        size_t i = 2;
        for (int j = 0; j < CASES_N; j++) {
            static char filename[128];
            sprintf(filename, "%s_%s_time ",
                    sorts[i].name, generatingFuncs[j].name);
            checkTime(sorts[i].sort,
                      generatingFuncs[j].generate,
                      size, filename);
        }
        printf("\n");
    }
*/
    for (size_t size = 200000; size <= 2000000; size += 200000) {
        printf("------------------------------\n");
        printf("Size: %d\n", size);
        for (int i = 3; i < FUNCS_N; i++) {
            for (int j = 0; j < CASES_N; j++) {
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
//    timeExperimentNComps();

    return 0;
}