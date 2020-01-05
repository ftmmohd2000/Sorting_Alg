#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "agen.h"
#include "bSort.h"
#include "selSort.h"
#include "iSort.h"
#include "mSort.h"
#include "countSort.h"
#include "qSort.h"

int main(){
    
    int i,n;
    int *myarr = NULL;
    clock_t start,end;
    double sum;
    char *sortNames[] = {"Bubble Sort","Selection Sort","Insertion Sort","Merge Sort","Counting Sort","Quick Sort"}; 
    void*

    printf("Enter number of elements to be sorted: ");
    scanf("%d",&n);

    for(i=0;i<5;i++){
        myarr = agen(time(NULL),n);
        start = clock();

    }

    return 0;
}