#include "qSort.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void qSort(int* ar,int n){
    
    int i,j;
    int *pv,*lptr,*rptr;

    if(n<=3){
        
        for(i=0;i<n-1;i++)
            for(j=0;j<n-1;j++){
                if(ar[j]>ar[j+1])
                    mySwap(ar+j,ar+j+1);
            }
        return;
    }
    
    pv = findPivot(ar,n);
    
    pv = mySwap(pv,ar+n-1);
    
    while(1){
        lptr = ar;
        rptr = pv - 1;
        for(i=0;i<n-2;i++){
            if((*rptr)<(*pv))
                break;
            else
                rptr--;
        }
        for(i=0;i<n-2;i++){
            if((*lptr)>(*pv))
                break;
            else
                lptr++;
        }
        if(lptr<rptr){
            mySwap(lptr,rptr);
        }
        else
            break;
    }

    pv = mySwap(pv,lptr);
    qSort(ar,pv-ar);
    qSort(pv+1,n-(pv-ar)-1);
}

int* findPivot(int* ar, int n){

    return (ar + rand()%n); 
}

int* mySwap(int* prim, int* sec){
    int temp;

    temp = *sec;
    *sec = *prim;
    *prim = temp;

    return sec;
}