#include<stdlib.h>
#include<string.h>
#include"table.h"

typedef struct cellT { 
    char *key;
    void *value;
    struct cellT *next;
} cellT;

struct symtabCDT {
    cellT *buckets[101];
};

symtabADT EmptySymbolTable(void) {
    symtabADT table;
    int i;
    table = (symtabADT)malloc(sizeof(*table));
    for (i=0; i<101; i++)
        table->buckets[i]=NULL;
    return(table);
}

//Private members
static cellT *FindCell(cellT *cp, char *key) {
    while ((cp != NULL ? strcmp(cp->key, key) != 0 : 0))
        cp = cp->next;
        return(cp);
}

//Hash
int Hash(char *s, int nBuckets) {
    int i;
    unsigned long hashcode;
    hashcode = 0;
    for (i=0; s[i]!='\0'; i++)
        hashcode = (hashcode<<5) + s[i];
         /* (hashcode << 5) means hashcode * 32. */
    return (int) (hashcode % nBuckets);
} 

#define Multiplier 27
int Hash2(char *s, int nBuckets){
    int i;
    unsigned long hashcode;
    hashcode = 0;
    for (i=0; s[i]!='\0'; i++)
        hashcode = hashcode*Multiplier + s[i];
    return (int)(hashcode % nBuckets);
    /* R is a prime number smaller than nBuckets. */
}

void Enter(symtabADT table, char *key, void *value) {
    int hashCode;
    cellT *cp;
    hashCode=Hash(key, 101);
    cp=FindCell(table->buckets[hashCode], key);
    if (cp==NULL) {
        cp = (cellT*)malloc(sizeof(*cp));
        cp->key=(char*)malloc(sizeof(char)*(strlen(key)+1));
        strcpy(cp->key, key);
        cp->next=table->buckets[hashCode];
        table->buckets[hashCode]=cp;
     }
    cp->value=value;
}



void *Lookup(symtabADT table, char *key) {
    int hashCode;
    cellT *cp;
    hashCode =Hash(key, 101);
    cp=FindCell(table->buckets[hashCode], key);
    if (cp==NULL) return(NULL);
    return(cp->value);
}


