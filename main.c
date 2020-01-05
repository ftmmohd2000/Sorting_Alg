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
    int *myarr,*temp;
    clock_t start,end;
    double finalTime;
    char *sortNames[] = {"Bubble Sort","Selection Sort","Insertion Sort","Merge Sort","Counting Sort","Quick Sort"}; 
    

    printf("Enter number of elements to be sorted: ");
    scanf("%d",&n);

    temp = agen(time(NULL),n);

    for(i=0;i<6;i++){
        myarr = temp;
        start = clock();
        
        switch (i)
        {
        case 0:
            //bSort(myarr,n);
            break;
        case 1:
            //selSort(myarr,n);
            break;
        case 2:
            //iSort(&myarr,n);
            break;
        case 3:
            mSort(myarr,n);
            break;
        case 4:
            countSort(myarr,n);
            break;
        case 5:
            qSort(myarr,n);
            break;
        default:
            break;
        }
        end = clock();

        printf("%s takes %lf seconds with a %d elements in this run.\n",sortNames[i],((double) (end - start)) / CLOCKS_PER_SEC,n);
    }

    return 0;
}