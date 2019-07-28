/* File: list.h */
typedef struct listCDT *listADT; 
typedef int listElementT;
listADT EmptyList(void);
listADT Cons(listElementT, listADT); listElementT Head(listADT); listADT Tail(listADT);
int ListIsEmpty(listADT);
