//
// Created by elen_ on 16.12.2021.
//

#include <stdio.h>
#include <assert.h>
#include "bitset.h"

bool bitset_checkValue(bitset set, unsigned value) {
    return value >= 0 && value <= set.maxValue;
}

bitset bitset_create(unsigned maxValue) {
    assert(maxValue < 32);
    return (bitset) {0, maxValue};
}

bool bitset_in(bitset set, unsigned int value) {
    assert(bitset_checkValue(set, value));
    return set.values >> value & 1;
}

bool bitset_isEqual(bitset set1, bitset set2) {
    return set1.values == set2.values;
}

bool bitset_isSubset(bitset subset, bitset set) {
    return (subset.values & set.values) == subset.values;
}

void bitset_insert(bitset *set, unsigned int value) {
    assert(bitset_checkValue(*set, value));
    set->values |= 1 << value;
}

void bitset_deleteElement(bitset *set, unsigned int value) {
    assert(bitset_checkValue(*set, value));
    set->values &= ~(1 << value);
}


bitset bitset_union(bitset set1, bitset set2) {
    assert(set1.maxValue == set2.maxValue);
    return (bitset) {set1.values | set2.values, set1.maxValue};
}

bitset bitset_intersection(bitset set1, bitset set2) {
    assert(set1.maxValue == set2.maxValue);
    return (bitset) {set1.values & set2.values, set1.maxValue};
}

bitset bitset_difference(bitset set1, bitset set2) {
    assert(set1.maxValue == set2.maxValue);
    return (bitset) {set1.values & ~set2.values, set1.maxValue};
}

bitset bitset_symmetricDifference(bitset set1, bitset set2) {
    assert(set1.maxValue == set2.maxValue);
    return (bitset) {set1.values ^ set2.values, set1.maxValue};
}

bitset bitset_complement(bitset set) {
    uint32_t n = sizeof(uint32_t) * 8 - set.maxValue;
    return (bitset) {~set.values << n >> n, set.maxValue};
}

void bitset_print(bitset set) {
    printf("{");
    bool isEmpty = true;
    for (int i = 0; i <= set.maxValue; i++) {
        if (bitset_in(set, i)) {
            printf("%d, ", i);
            isEmpty = false;
        }
    }
    if (isEmpty)
        printf("{\n");
    else
        printf("\b\b}\n");
}