#ifndef INSORT
#define INSORT

struct data{
    int val;
    struct data *next;

};


void iSort(int**,int);
struct data* genLL(int*,int);
struct data* mvNode(struct data*,struct data*,struct data*);
struct data* findPrev(struct data*,struct data*);
struct data* seekLL(struct data*,int);
int* freeLL(struct data*);

#endif


