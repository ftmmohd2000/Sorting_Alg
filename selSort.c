void selSort(int *ar, int n){
    int temp,min,i,j;

    for(i=0;i<n-1;i++){
        min = i;
        for(j=i;j<n;j++){
            if(ar[j]<ar[min])
                min = j;
        }
        temp = ar[min];
        ar[min] = ar[i];
        ar[i] = temp;
    }
}