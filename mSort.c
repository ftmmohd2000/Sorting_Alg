#include <stdlib.h>
#include <stdio.h>

void mSort(int* ar, int n){
    int* tempAr = (int*) malloc(sizeof(int)*n);
    int temp,rem,i,j,k,half;
    if(n==2){
        if(*ar > *(ar+1)){
            temp = *ar;
            *(ar) = *(ar+1);
            *(ar+1) = temp;
        }
        return;
    }
    else if(n==3){
        for(i=0;i<2;i++)
            for(j=0;j<2;j++){
                if(*(ar+j)>*(ar+j+1)){
                    temp = *(ar+j);
                    *(ar+j) = *(ar+j+1);
                    *(ar+j+1) = temp;
                }
            }
        return;
    }
    else{
        half = n/2;
        rem = n-half;
        mSort(ar,half);
        mSort(ar+half,rem);
    }

    i = j = 0;

    for(k=0;k<n;k++){
        if(i == half){
            *(tempAr + k) = *(ar + half + j);
            j++;
        }
        else if(j == rem){
            *(tempAr + k) = *(ar + i);
            i++;
        } 
        else{
            if(*(ar + i) < *(ar + half + j)){
                *(tempAr + k) = *(ar + i);
                i++;
            }
            else{
                *(tempAr + k) = *(ar + half + j);
                j++;
            }
        }
        
    }

    for(i=0;i<n;i++)
        *(ar+i) = *(tempAr + i);

    free(tempAr);
    return;
}