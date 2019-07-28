#include"list.h"
#include"stdlib.h"
typedef struct listCDT *listADT;
struct listCDT { 
    listElementT h; 
    listADT t;
};

listADT EmptyList() {
    return((listADT)NULL);
}

listADT Cons(listElementT h1, listADT t1){ 
    listADT list = (listADT)malloc(sizeof(*list));
    list->h = h1;
    list->t = t1;
    return (list);
 }

listElementT Head(listADT list) {
    if (ListIsEmpty(list)) exit(0);
    return (list->h);
} 

listADT Tail(listADT list) {
    if (ListIsEmpty(list)) exit(0);
    return (list->t);
}

int ListIsEmpty(listADT list) {
    return (list == NULL);
} 


