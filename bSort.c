void bSort(int* target,int size){
    int i,j,temp;

    for(i=0;i<size;i++){
        for(j=0;j<size-1;j++){
            if(target[j]>target[j+1]){
                temp = target[j+1];
                target[j+1] = target[j];
                target[j] = temp;
            }
        }
    }
}