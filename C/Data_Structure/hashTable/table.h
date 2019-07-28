/* File: symtab.h */

typedef struct symtabCDT *symtabADT;

symtabADT EmptySymbolTable(void);
void Enter(symtabADT table, char *key, void *value);
void *Lookup(symtabADT table, char *key);
