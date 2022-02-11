//
// Created by elen_ on 16.12.2021.
//

#include <stdio.h>
#include "unordered_array_set.h"
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
#include <memory.h>
#include "../../algorithms/array/array.h"

// возвращает пустое множество для capacity элементов
unordered_array_set unordered_array_set_create(size_t capacity) {
    return (unordered_array_set) {malloc(sizeof(int) * capacity),
                                  0,
                                  capacity};
}

// возбуждает исключение, если в множество по адресу set
// нельзя вставить элемент
void unordered_array_set_isAbleAppend(unordered_array_set *set) {
    assert(set->size < set->capacity);
}

// возвращает позицию элемента в множестве,
// если значение value имеется в множестве set,
// иначе - n
int unordered_array_set_in(unordered_array_set *set, int value) {
    return linearSearch_(set->data, set->size, value);
}

// вывод множества set
void unordered_array_set_print(unordered_array_set set) {
    if (set.size == 0)
        printf("{}\n");
    else {
        printf("{");
        for (size_t i = 0; i < set.size - 1; i++)
            printf("%d, ", set.data[i]);
        printf("%d}\n", set.data[set.size - 1]);
    }
}

// добавляет элемент value в множество set
void unordered_array_set_insert(unordered_array_set *set, int value) {
    if (unordered_array_set_in(set, value) == set->size) {
        unordered_array_set_isAbleAppend(set);
        append_(set->data, &set->size, value);
    }
}

static void unordered_array_set_shrinkToFit(unordered_array_set *a) {
    if (a->size != a->capacity) {
        a->data = (int *) realloc(a->data, sizeof(int) * a->size);
        a->capacity = a->size;
    }
}

// возвращает множество, состоящее из элементов массива a размера size
unordered_array_set unordered_array_set_create_from_array(const int *a, size_t size) {
    unordered_array_set set = unordered_array_set_create(size);
    for (size_t i = 0; i < size; i++)
        unordered_array_set_insert(&set, a[i]);
    unordered_array_set_shrinkToFit(&set);
    return set;
}

int compare_ints(const void *a, const void *b) {
    int arg1 = *(const int *) a;
    int arg2 = *(const int *) b;

    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}


// возвращает значение ’истина’, если элементы множеств set1 и set2 равны
// иначе - ’ложь’
bool unordered_array_set_isEqual(unordered_array_set set1, unordered_array_set set2) {
    if (set1.size != set2.size)
        return false;
    qsort(set1.data, set1.size, sizeof(int), compare_ints);
    qsort(set2.data, set2.size, sizeof(int), compare_ints);
    return memcmp(set1.data, set2.data, sizeof(int) * set1.size) == false;
}

// удаляет элемент value из множества set
void unordered_array_set_deleteElement(unordered_array_set *set, int value) {
    for (int i = 0; i <= set->size; i++) {
        if (set->data[i] == value) {
            deleteByPosUnsaveOrder_(set->data, &set->size, i);
        }
    }
}

void inputDoubleArray(int *a, const int *b, size_t n) {
    for (int i = 0; i < n; i++)
        a[i] = b[i];
}

// возвращает объединение множеств set1 и set2
unordered_array_set unordered_array_set_union(unordered_array_set set1, unordered_array_set set2) {
    size_t n = set1.size+set2.size;
    size_t n1 = set1.size;
    int a[n];
    inputDoubleArray(a, set1.data, set1.size);
    for (size_t i = 0; i < set2.size; i++) {
        if (unordered_array_set_in(&set1, set2.data[i])==set1.size){
            append_(a, &n1, set2.data[i]);
        }
    }
    return unordered_array_set_create_from_array(a,n1);
}


// возвращает пересечение множеств set1 и set2
unordered_array_set unordered_array_set_intersection(unordered_array_set set1, unordered_array_set set2) {
    size_t n = 0;
    int a[n];
    for (int i = 0; i < set2.size; i++)
        for (int j = 0; j < set1.size; j++) {
            if (set1.data[j] == set2.data[i]) {
                append_(a, &n, set2.data[i]);
            }
        }

    unordered_array_set set3 = unordered_array_set_create_from_array(a, n);
    return set3;
}


// возвращает разность множеств set1 и set2
unordered_array_set unordered_array_set_difference(unordered_array_set set1, unordered_array_set set2) {
    size_t n = 0;
    int a[n];
    for (int i = 0; i < set1.size; i++) {
        int isDouble = 0;
        for (int j = 0; j < set2.size; j++) {
            if (set1.data[i] == set2.data[j]) {
                isDouble++;
            }
        }
        if (isDouble == 0)
            append_(a, &n, set1.data[i]);
    }

    unordered_array_set set3 = unordered_array_set_create_from_array(a, n);
    return set3;
}


// освобождает память, занимаемую множеством set
void unordered_array_set_delete(unordered_array_set set) {
    free(set.data);
}


unordered_array_set unordered_array_set_symmetricDifference(unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set intersectionSet = unordered_array_set_intersection(set1, set2);
    unordered_array_set unionSet = unordered_array_set_union(set2, set1);
    unordered_array_set set = unordered_array_set_difference(unionSet, intersectionSet);
    unordered_array_set_delete(unionSet);
    unordered_array_set_delete(unionSet);
    return set;
}


// возвращает дополнение до универсума множества set
unordered_array_set unordered_array_set_complement(unordered_array_set set, unordered_array_set universumSet) {
    return (unordered_array_set) unordered_array_set_difference(universumSet, set);
}

