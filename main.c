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
#include "scramble.h"

int main(){
    
    int i,n,seed;
    int *myarr;
    clock_t start,end;
    double finalTime,timings[6];
    //char *sortNames[] = {"Bubble Sort","Selection Sort","Insertion Sort","Merge Sort","Counting Sort","Quick Sort"}; 
    FILE* fptr;

    n=500;


    while(n<100000){

        seed = time(NULL);
        myarr = agen(seed,n);

        fptr = fopen("timing.txt","a");
        if(!fopen)
            return -1;
        
        for(i=0;i<6;i++){
            scramble(myarr,n,seed);
            start = clock();
            
            switch (i)
            {
            case 0:
                bSort(myarr,n);
                break;
            case 1:
                selSort(myarr,n);
                break;
            case 2:
                iSort(&myarr,n);
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

            timings[i] = ((double) (end - start)) / CLOCKS_PER_SEC;

            //printf("%s takes %lf seconds with a %d elements in this run.\n",sortNames[i],((double) (end - start)) / CLOCKS_PER_SEC,n);
        }

        fprintf(fptr,"%d ", n);
        for(i=0;i<6;i++)
            fprintf(fptr,"%.7lf ",timings[i]);
        fprintf(fptr,"\n");

        fclose(fptr);

        free(myarr);

        n += 1000;
    }
    return 0;
}