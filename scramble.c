#include <stdlib.h>
#include <time.h>

void scramble(int* ar,int n,int seed){

    int i,ran,temp;

    srand(seed);

    for(i=0;i<n;i++){
        ran = rand()%n;

        temp = ar[ran];
        ar[ran] = ar[i];
        ar[i] = ar[ran];
    }
}