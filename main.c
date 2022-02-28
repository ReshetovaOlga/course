#include "libs/data_structures/string/string.h"
#include <stdio.h>
#include <assert.h>

//тесты функций библиотеки
void test_findNonSpace_firthElementNonSpace(){
    char *str="Why did I come here?";
    assert(*findNonSpace(str)=='W');
}

void test_findNonSpace_notFirthElementNonSpace(){
    char *str="   I have lived among adults for a long time";
    assert(*findNonSpace(str)=='I');
}

void test_findNonSpace_withoutElement(){
    char *str="";
    assert(*findNonSpace(str)=='\0');
}

int main(){
    test_findNonSpace_firthElementNonSpace();
    test_findNonSpace_notFirthElementNonSpace();
    test_findNonSpace_withoutElement();
}