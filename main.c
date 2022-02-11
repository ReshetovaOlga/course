#include "libs/data_structures/unordered_array_set/unordered_array_set.h"
#include "libs/algorithms/array/array.h"

void test1_unordered_array_set_in() {
    unordered_array_set set = unordered_array_set_create_from_array((int[]) {3, 3}, 2);
    int value = 2;
    assert(unordered_array_set_in(&set, value) == 1);
    unordered_array_set_delete(set);
}

void test2_unordered_array_set_in() {
    unordered_array_set set = unordered_array_set_create_from_array((int[]) {3, 2}, 2);
    int value = 3;
    assert(unordered_array_set_in(&set, value) == 0);
    unordered_array_set_delete(set);
}

void test_unordered_array_set_in() {
    test1_unordered_array_set_in();
    test2_unordered_array_set_in();
}

void test_unordered_array_set_insert() {
    int value = 3;
    int n = 2;
    int a[n];
    a[0] = 1;
    a[1] = 2;
    unordered_array_set set1 = {a, n, 3};
    unordered_array_set_insert(&set1, value);
    int b[] = {1, 2, 3};
    unordered_array_set set2 = unordered_array_set_create_from_array(b, 3);
    assert(unordered_array_set_isEqual(set1, set2));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
}

void test1_unordered_array_set_deleteElement() {
    int a[] = {1, 2, 3, 4, 5};
    int value = 2;
    unordered_array_set set1 = unordered_array_set_create_from_array(a, 5);
    unordered_array_set_deleteElement(&set1, value);
    int b[] = {1, 3, 4, 5};
    unordered_array_set set2 = unordered_array_set_create_from_array(b, 4);
    assert(unordered_array_set_isEqual(set1, set2));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
}

void test2_unordered_array_set_deleteElement() {
    int a[] = {1, 2, 3, 4, 5};
    int value = 8;
    unordered_array_set set1 = unordered_array_set_create_from_array(a, 5);
    unordered_array_set_deleteElement(&set1, value);
    int b[] = {1, 2, 3, 4, 5};
    unordered_array_set set2 = unordered_array_set_create_from_array(b, 5);
    assert(unordered_array_set_isEqual(set1, set2));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
}

void test_unordered_array_set_deleteElement() {
    test2_unordered_array_set_deleteElement();
    test1_unordered_array_set_deleteElement();
}

void test2_unordered_array_set_union() {
    int a[] = {1, 2, 3, 4, 5};
    unordered_array_set set1 = unordered_array_set_create_from_array(a, 5);
    int b[] = {1, 2, 7, 6};
    unordered_array_set set2 = unordered_array_set_create_from_array(b, 4);
    unordered_array_set set3 = unordered_array_set_union(set1, set2);
    int c[] = {1, 2, 3, 4, 5, 7, 6};
    unordered_array_set set4 = unordered_array_set_create_from_array(c, 7);
    assert(unordered_array_set_isEqual(set4, set3));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(set3);
    unordered_array_set_delete(set4);

}

void test1_unordered_array_set_union() {
    int a[] = {1, 2, 7};
    unordered_array_set set1 = unordered_array_set_create_from_array(a, 3);
    int b[] = {1, 2, 7};
    unordered_array_set set2 = unordered_array_set_create_from_array(b, 3);
    unordered_array_set set3 = unordered_array_set_union(set1, set2);
    int c[] = {1, 2, 7};
    unordered_array_set set4 = unordered_array_set_create_from_array(c, 3);
    assert(unordered_array_set_isEqual(set4, set3));

}

void test3_unordered_array_set_union() {
    int a[] = {3, 4, 5};
    unordered_array_set set1 = unordered_array_set_create_from_array(a, 3);
    int b[] = {1, 3, 7, 6};
    unordered_array_set set2 = unordered_array_set_create_from_array(b, 4);
    unordered_array_set set3 = unordered_array_set_union(set1, set2);
    int c[] = {1, 3, 7, 6, 4, 5};
    unordered_array_set set4 = unordered_array_set_create_from_array(c, 6);
    assert(unordered_array_set_isEqual(set4, set3));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(set3);
    unordered_array_set_delete(set4);
}

void test_unordered_array_set_union() {
    test2_unordered_array_set_union();
    test1_unordered_array_set_union();
    test3_unordered_array_set_union();
}

void test2_unordered_array_set_intersection() {
    int a[] = {1, 2, 3, 4, 5};
    unordered_array_set set1 = unordered_array_set_create_from_array(a, 5);
    int b[] = {1, 2, 7, 6};
    unordered_array_set set2 = unordered_array_set_create_from_array(b, 4);
    unordered_array_set set3 = unordered_array_set_intersection(set1, set2);
    int c[] = {1, 2};
    unordered_array_set set4 = unordered_array_set_create_from_array(c, 2);
    assert(unordered_array_set_isEqual(set4, set3));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(set3);
    unordered_array_set_delete(set4);
}

void test1_unordered_array_set_intersection() {
    int a[] = {9, 4, 5};
    unordered_array_set set1 = unordered_array_set_create_from_array(a, 3);
    int b[] = {1, 3, 7, 6};
    unordered_array_set set2 = unordered_array_set_create_from_array(b, 4);
    unordered_array_set set3 = unordered_array_set_intersection(set1, set2);
    int c[0];
    unordered_array_set set4 = unordered_array_set_create_from_array(c, 0);
    assert(unordered_array_set_isEqual(set4, set3));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(set3);
    unordered_array_set_delete(set4);
}

void test3_unordered_array_set_intersection() {
    int a[] = {3, 4, 5};
    unordered_array_set set1 = unordered_array_set_create_from_array(a, 3);
    int b[] = {1, 3, 7, 6};
    unordered_array_set set2 = unordered_array_set_create_from_array(b, 4);
    unordered_array_set set3 = unordered_array_set_intersection(set1, set2);
    int c[] = {3};
    unordered_array_set set4 = unordered_array_set_create_from_array(c, 1);

    assert(unordered_array_set_isEqual(set4, set3));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(set3);
    unordered_array_set_delete(set4);
}

void test_unordered_array_set_intersection() {
    test2_unordered_array_set_intersection();
    test1_unordered_array_set_intersection();
    test3_unordered_array_set_intersection();
}

void test1_unordered_array_set_difference() {
    int a[] = {3, 4, 5};
    unordered_array_set set1 = unordered_array_set_create_from_array(a, 3);
    int b[] = {1, 2, 7, 6};
    unordered_array_set set2 = unordered_array_set_create_from_array(b, 4);
    unordered_array_set set3 = unordered_array_set_difference(set1, set2);
    int c[] = {3, 4, 5};
    unordered_array_set set4 = unordered_array_set_create_from_array(c, 3);
    assert(unordered_array_set_isEqual(set4, set3));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(set3);
    unordered_array_set_delete(set4);
}

void test2_unordered_array_set_difference() {
    int a[] = {3, 4, 5};
    unordered_array_set set1 = unordered_array_set_create_from_array(a, 3);
    int b[] = {1, 3, 7, 6};
    unordered_array_set set2 = unordered_array_set_create_from_array(b, 4);
    unordered_array_set set3 = unordered_array_set_difference(set1, set2);
    int c[] = {4, 5};
    unordered_array_set set4 = unordered_array_set_create_from_array(c, 2);
    assert(unordered_array_set_isEqual(set4, set3));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(set3);
    unordered_array_set_delete(set4);
}

void test_unordered_array_set_difference() {
    test1_unordered_array_set_difference();
    test2_unordered_array_set_difference();
}

void test1_unordered_array_set_symmetricDifference() {
    int a[] = {3, 4, 5};
    unordered_array_set set1 = unordered_array_set_create_from_array(a, 3);
    int b[] = {1, 3, 7, 6};
    unordered_array_set set2 = unordered_array_set_create_from_array(b, 4);
    unordered_array_set set3 = unordered_array_set_symmetricDifference(set1, set2);
    int c[] = {1, 7, 6, 4, 5};
    unordered_array_set set4 = unordered_array_set_create_from_array(c, 5);
    assert(unordered_array_set_isEqual(set4, set3));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(set3);
    unordered_array_set_delete(set4);
}

void test2_unordered_array_set_symmetricDifference() {
    int a[] = {9, 4, 5};
    unordered_array_set set1 = unordered_array_set_create_from_array(a, 3);
    int b[] = {1, 3, 7, 6};
    unordered_array_set set2 = unordered_array_set_create_from_array(b, 4);
    unordered_array_set set3 = unordered_array_set_symmetricDifference(set1, set2);
    int c[] = {9, 4, 5, 1, 3, 7, 6};
    unordered_array_set set4 = unordered_array_set_create_from_array(c, 7);
    assert(unordered_array_set_isEqual(set4, set3));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(set3);
    unordered_array_set_delete(set4);
}

void test_unordered_array_set_symmetricDifference() {
    test1_unordered_array_set_symmetricDifference();
    test2_unordered_array_set_symmetricDifference();
}

void test1_unordered_array_set_complement() {
    int a[] = {};
    unordered_array_set set1 = unordered_array_set_create_from_array(a, 0);
    int b[] = {1, 2, 3, 4, 5};
    unordered_array_set set2 = unordered_array_set_create_from_array(b, 5);
    unordered_array_set set3 = unordered_array_set_complement(set1, set2);
    int c[] = {1, 2, 3, 4, 5};
    unordered_array_set set4 = unordered_array_set_create_from_array(c, 5);
    assert(unordered_array_set_isEqual(set4, set3));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(set3);
    unordered_array_set_delete(set4);
}

void test2_unordered_array_set_complement() {
    int a[] = {1, 2, 3};
    unordered_array_set set1 = unordered_array_set_create_from_array(a, 3);
    int b[] = {};
    unordered_array_set set2 = unordered_array_set_create_from_array(b, 0);
    unordered_array_set set3 = unordered_array_set_complement(set1, set2);
    int c[] = {};
    unordered_array_set set4 = unordered_array_set_create_from_array(c, 0);
    assert(unordered_array_set_isEqual(set4, set3));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(set3);
    unordered_array_set_delete(set4);
}

void test3_unordered_array_set_complement() {
    int a[] = {1, 2, 3};
    unordered_array_set set1 = unordered_array_set_create_from_array(a, 3);
    int b[] = {1, 2, 3, 4, 5};
    unordered_array_set set2 = unordered_array_set_create_from_array(b, 5);
    unordered_array_set set3 = unordered_array_set_complement(set1, set2);
    int c[] = {4, 5};
    unordered_array_set set4 = unordered_array_set_create_from_array(c, 2);
    assert(unordered_array_set_isEqual(set4, set3));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(set3);
    unordered_array_set_delete(set4);
}


void test_unordered_array_set_complement() {
    test1_unordered_array_set_complement();
    test2_unordered_array_set_complement();
    test3_unordered_array_set_complement();
}

void test_array_set(){
    test_unordered_array_set_in();
    test_unordered_array_set_insert();
    test_unordered_array_set_deleteElement();
    test_unordered_array_set_union();
    test_unordered_array_set_intersection();
    test_unordered_array_set_difference();
    test_unordered_array_set_symmetricDifference();
    test_unordered_array_set_complement();
}




int main() {
//    test_array_set();
    return 0;
}