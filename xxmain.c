#include <stdio.h>
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

    printf("Please enter number: ");
    scanf("%d", &n);

    myarr = agen(time(NULL),n);

    printf("Array before sorting:\n");

    for(i=0;i<(n);i++) 
        printf("%d\t",myarr[i]);

    
    printf("\n");
    
    //bSort(myarr,(n));
    mSort(myarr,n);

    printf("Array after sorting:\n");

    for(i=0;i<(n);i++) 
        printf("%d\t",myarr[i]);

    printf("\n");


    return 0;
}