#include <stdlib.h>
#include <stdio.h>

void countSort(int* ar, int n){
    int *refArr;
    int i,j,max,min,range;

    max = ar[0];
    for(i=0;i<n;i++)
        if(ar[i]>max)
            max = ar[i];

    min = ar[0];
    for(i=0;i<n;i++)
        if(ar[i]<min)
            min = ar[i];

    range = max-min+1;

    //printf("range: %d\tmax: %d\tmin: %d\n",range,max,min);

    refArr = (int*)malloc((range)*sizeof(int));

    for(i=0;i<(range);i++)
        refArr[i] = 0;

    for(i=0;i<n;i++)
        refArr[ar[i]-min]++;
    
    for(i=1;i<(range);i++)
        refArr[i] += refArr[i-1];

    j = 0;
    for(i=0;i<(range);i++){
        while(j!=refArr[i]){
            ar[j] = min+i;
            j++;
        }
    }
    
    //free(refArr);
}