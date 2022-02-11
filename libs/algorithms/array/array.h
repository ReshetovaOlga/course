//
// Created by elen_ on 16.12.2021.
//

#ifndef COURSE_ARRAY_H
#define COURSE_ARRAY_H

#endif //COURSE_ARRAY_H
#include <stdio.h>

void inputArray_(int *const a, const size_t n);

void outputArray_(const int *const a, const size_t n);

void append_(int *const a, size_t *const n, const int value);

void insert_(int *const a, size_t *const n, const size_t pos, const int value);

void deleteByPosSaveOrder_(int *a, size_t *n, const size_t pos);

void deleteByPosUnsaveOrder_(int *a, size_t *n, size_t pos);
size_t linearSearch_(const int *a, const size_t n, int x);

int any_(const int *a, size_t n, int (*predicate)(int));

int all_(const int *a, size_t n, int (*predicate)(int));

int countIf_(const int *const a, const size_t n, int (*predicate)(int));

void deleteIf_(int *const a, size_t *const n, int (*deletePredicate)(int));

void forEach_(const int *source, int *dest, const size_t n, const int (*predicate )(int));

size_t binarySearch_(const int *a, size_t n, int x);

size_t binarySearchMoreOrEqual_(const int *a, size_t n, int x);

void swapInt(int *a, int *b);

void general_swap(void *a, void *b, size_t size);