#include <stdlib.h>
#include <stdio.h>

int* agen(int seed,int n){
    
    int i, my[n],temp;
    int *retval = (int*)malloc(n*sizeof(int));

    srand(seed);

    for(i=0;i<n;i++) 
        my[i] = i+1;

    i = 0;

    while (i<n)
    {
        temp = (rand())%(n);
        if(my[temp]){
            retval[i] = my[temp];
            my[temp] = 0;
            i++;
        }
        //printf("%d\t",i);
    }

    return retval;
}
