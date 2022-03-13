#include "libs/data_structures/sortAndDifficultyAssessment/sortAndDifficultyAssessment.h"
#include <stdio.h>

void outputArray(int *a, size_t size){
    for(int i=0; i<size; i++)
        printf("%d, ", a[i]);
    printf("\n");
}

int main(){
    int a[]={5,4,6,1,9,2,7,3,8};
    combSort(a, 9);
    outputArray(a,9);

    return 0;
}