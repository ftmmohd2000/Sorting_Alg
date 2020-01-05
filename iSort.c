#include "iSort.h"
#include <stdlib.h>

void iSort(int** ar,int n){

    struct data *tbm,*check,*head = genLL(*ar,n);
    int i,j,flag;

    for(i=1;i<n;i++){
        
        tbm = seekLL(head,i);
        check = head;
        for(j=0;j<i;j++){
            if((check->val)>(tbm->val)){
                head = mvNode(head,check,tbm);
                break;
            }
            check = check->next;
        }
        
    }
    free(*ar);

    *ar = freeLL(head);
}

struct data* genLL(int *ar,int n){

    struct data *temp = NULL;
    struct data *head = (struct data*)malloc(sizeof(struct data));
    int i;

    head->val = *ar;
    head->next = NULL;
    temp = head;
    for(i=1;i<n;i++){
        temp->next = (struct data*)malloc(sizeof(struct data));
        temp = temp->next;
        temp->val = ar[i];
        temp->next = NULL;
    }
    return head;
}

struct data* mvNode(struct data* head, struct data* beforeThis, struct data* target){

    if(target == head)
        head = target->next;
    else{
        findPrev(head,target)->next = target->next;
    }

    if(beforeThis == head){
        target->next = head;
        return target;
    }
    else{
        findPrev(head,beforeThis)->next = target;
        target->next = beforeThis;
        return head;
    }

}

struct data* findPrev(struct data* head, struct data* target){
    
    struct data* ptr;
    
    if(head == target)
        return NULL;
    
    ptr = head;

    while(ptr->next != target)
        ptr = ptr->next;

    return ptr;
}

struct data* seekLL(struct data* head, int n){
    int i = 0;
    struct data* ptr = head;

    for(i=0;i<n;i++){
        if(!ptr)
            return NULL;
        else
            ptr = ptr->next;
    }

    return ptr;
}

int* freeLL(struct data* head){
    int i,n=0;
    int* ar = NULL;
    struct data* ptr = head;
    
    while(ptr){
        n++;
        ptr = ptr->next;
    }

    ar = (int*)malloc(n*sizeof(int));

    ptr = head;

    for(i=0;i<n;i++){
        ar[i] = ptr->val;
        ptr = ptr->next;
    }

    return ar;
}