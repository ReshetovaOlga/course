#include "libs/data_structures/string/string.h"
#include "libs/data_structures/string/tasks/removeNonLetters.h"
#include "libs/data_structures/string/tasks/removeAdjacentEqualLetters.h"
#include "libs/data_structures/string/tasks/firstTheNumbersAreInvertedThenTheLetters.h"
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <malloc.h>

#define ASSERT_STRING(expected, got) assertString (expected, got, \
__FILE__, __FUNCTION__, __LINE__)

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

void test_findNonSpaceReverse() {
    test_findNonSpaceReverse_findBegin();
    test_findNonSpaceReverse_elementBegin();
}

void test_findSpaceReverse() {
    char *str = "After that they are not able to move";
    assert(findSpaceReverse(str + 35, str) == str + 31);
}

void test_strcmp_theRowsAreEqual() {
    char *str1 = "I look good";
    char *str2 = "I look good";
    assert(strcmp_(str1, str2) == 0);
}

void test_strcmp_theRowsAreNotEqual() {
    char *str1 = "I look not good";
    char *str2 = "I look good";
    assert(strcmp_(str1, str2) != 0);
}

void test_strcmp() {
    test_strcmp_theRowsAreEqual();
    test_strcmp_theRowsAreNotEqual();
}

void test_copy() {
    char *str1 = "I thought about it. And then I made my first drawing.";
    char *str2 = "I thought about it.";
    char str3[20];
    copy(str1, str1 + 18, str3);
    *str3 = '\0';
    assert(strcmp_(str3, str2) != 0);
}

int thisElementIsA(int s) {
    return (s == 'a' || s == 'A');
}

void test_copyIf() {
    char *str1 = "an Angel flying into the distance";
    char *str2 = "aAa";
    char str3[5];
    copyIf(str1, str1 + 32, str3, thisElementIsA);
    *str3 = '\0';
    assert(strcmp_(str3, str2) != 0);
}

void test_copyIfReverse() {
    char *str1 = "mama A ma";
    char *str2 = "aAaa";
    char str3[5];
    copyIfReverse(str1 + 8, str1, str3, thisElementIsA);
    *str3 = '\0';
    assert(strcmp_(str3, str2) != 0);
}

void test_lib() {
    test_findNonSpace();
    test_strlen();
    test_find();
    test_findSpace();
    test_findNonSpaceReverse();
    test_findSpaceReverse();
    test_strcmp();
    test_copy();
    test_copyIf();
    test_copyIfReverse();
}


void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName,
                  int line) {
    if (strcmp_(expected, got)) {
        fprintf(stderr, " File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, " Expected : \"%s \"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else
        fprintf(stderr, "%s - OK\n", funcName);
}


void test_removeNonLetters() {
    char s[] = "an Angel flying into the distance";
    removeNonLetters(s);
    ASSERT_STRING ("anAngelflyingintothedistance", s);
}

void test_removeAdjacentEqualLetters() {
    char s[] = "aaabbbccc";
    removeAdjacentEqualLetters(s);
    ASSERT_STRING ("abc", s);
}

void test_removeAdjacentEqualLetters_emptyString() {
    char s[] = "";
    removeAdjacentEqualLetters(s);
    ASSERT_STRING ("", s);
}


void test_firstTheNumbersAreInvertedThenTheLetters(){
    char str[]="a5 4fg5 4f4f5f6";
    firstTheNumbersAreInvertedThenTheLetters(str);
    ASSERT_STRING("5a 54fg 6544fff", str);
}

void test_firstTheNumbersAreInvertedThenTheLetters_emptyString(){
    char str[]="";
    firstTheNumbersAreInvertedThenTheLetters(str);
    ASSERT_STRING("", str);
}

void test_tasks() {
    test_removeNonLetters();
    test_removeAdjacentEqualLetters();
    test_removeAdjacentEqualLetters_emptyString();
    test_firstTheNumbersAreInvertedThenTheLetters();
    test_firstTheNumbersAreInvertedThenTheLetters_emptyString();
}

int main() {
    test_lib();
    test_tasks();

    return 0;
}