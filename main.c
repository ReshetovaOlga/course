#include "libs/data_structures/string/string.h"
#include <stdio.h>
#include <assert.h>

//тесты функций библиотеки
void test_findNonSpace_firthElementNonSpace() {
    char *str = "Why did I come here?";
    assert(*findNonSpace(str) == 'W');
}

void test_findNonSpace_notFirthElementNonSpace() {
    char *str = "   I have lived among adults for a long time";
    assert(*findNonSpace(str) == 'I');
}

void test_findNonSpace_withoutElement() {
    char *str = "";
    assert(*findNonSpace(str) == '\0');
}

void test_findNonSpace() {
    test_findNonSpace_firthElementNonSpace();
    test_findNonSpace_notFirthElementNonSpace();
    test_findNonSpace_withoutElement();
}

void test_strlen_thereAreSymbols() {
    char *str = "Once when I was six years old I saw a magnificent picture in a book";
    assert(strlen_(str) == 67);
}

void test_strlen_thereAreNotSymbols() {
    char *str = "";
    assert(strlen_(str) == 0);
}

void test_strlen() {
    test_strlen_thereAreSymbols();
    test_strlen_thereAreNotSymbols();
}

void test_find() {
    char *str = "called True Stories from Nature, about the primeval forest.";
    assert(find(str, str + 30, 'a') == str + 1);
}

void test_findSpace() {
    char *str = "It was a picture of a boa which was swallowing an animal.";
    assert(findSpace(str) == str + 2);
}

void test_findNonSpaceReverse_findBegin() {
    char *str = "In the book it said     ";
    assert(findNonSpaceReverse(str + 23, str) == str + 18);
}

void test_findNonSpaceReverse_elementBegin() {
    char *str = "Boas swallow their prey whole, they do not chew it";
    assert(findNonSpaceReverse(str + 49, str) == str + 49);
}

void test_findNonSpaceReverse(){
        test_findNonSpaceReverse_findBegin();
        test_findNonSpaceReverse_elementBegin();
}

void test_findSpaceReverse() {
    char *str = "After that they are not able to move";
    assert(findSpaceReverse(str + 35, str) == str + 31);
}

void test_strcmp_theRowsAreEqual(){
    char *str1 = "I look good";
    char *str2 = "I look good";
    assert(strcmp_(str1, str2) == 0);
}

void test_strcmp_theRowsAreNotEqual(){
    char *str1 = "I look not good";
    char *str2 = "I look good";
    assert(strcmp_(str1, str2) != 0);
}

void test_strcmp(){
    test_strcmp_theRowsAreEqual();
    test_strcmp_theRowsAreNotEqual();
}



void test_lib() {
    test_findNonSpace();
    test_strlen();
    test_find();
    test_findSpace();
    test_findNonSpaceReverse();
    test_findSpaceReverse();
    test_strcmp();
}


int main() {

}