//
// Created by elen_ on 16.12.2021.
//

# ifndef INC_UNORDERED_ARRAY_SET_H
# define INC_UNORDERED_ARRAY_SET_H

# include <stdint.h>
# include <assert.h>
# include <memory.h>
# include <stdio.h>
# include <stdbool.h>
# include <malloc.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
#include <memory.h>

typedef struct unordered_array_set {
    int *data; // элементы множества
    size_t size; // количество элементов в множестве
    size_t capacity; // максимальное количество элементов в множестве
} unordered_array_set;

// вывод множества set
void unordered_array_set_print(unordered_array_set set);

// возвращает пустое множество для capacity элементов
unordered_array_set unordered_array_set_create(size_t capacity);

// возбуждает исключение, если в множество по адресу set
// нельзя вставить элемент
void unordered_array_set_isAbleAppend(unordered_array_set *set);


// возвращает позицию элемента в множестве,
// если значение value имеется в множестве set,
// иначе - n
int unordered_array_set_in(unordered_array_set *set, int value);


// добавляет элемент value в множество set
void unordered_array_set_insert(unordered_array_set *set, int value);

static void unordered_array_set_shrinkToFit(unordered_array_set *a);

// возвращает множество, состоящее из элементов массива a размера size
unordered_array_set unordered_array_set_create_from_array(const int *a, size_t size);

int compare_ints(const void *a, const void *b);


// возвращает значение ’истина’, если элементы множеств set1 и set2 равны
// иначе - ’ложь’
bool unordered_array_set_isEqual(unordered_array_set set1, unordered_array_set set2);

// удаляет элемент value из множества set
void unordered_array_set_deleteElement(unordered_array_set *set, int value);

void inputDoubleArray(int *a, const int *b, size_t n);

// возвращает объединение множеств set1 и set2
unordered_array_set unordered_array_set_union(unordered_array_set set1, unordered_array_set set2);

// возвращает пересечение множеств set1 и set2
unordered_array_set unordered_array_set_intersection(unordered_array_set set1, unordered_array_set set2);


// возвращает разность множеств set1 и set2
unordered_array_set unordered_array_set_difference(unordered_array_set set1, unordered_array_set set2);


// освобождает память, занимаемую множеством set
void unordered_array_set_delete(unordered_array_set set);

// // возвращает симметрическую разность множеств set1 и set2
unordered_array_set unordered_array_set_symmetricDifference(unordered_array_set set1, unordered_array_set set2);


// возвращает дополнение до универсума множества set
unordered_array_set unordered_array_set_complement(unordered_array_set set, unordered_array_set universumSet);


# endif

