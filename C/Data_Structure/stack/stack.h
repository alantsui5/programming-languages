/*
 * File:stack.h
 */

typedef struct stackCDT *stackADT;

typedef int stackElementT;

stackADT EmptyStack(void);
void Push(stackADT stack, stackElementT element);
stackElementT Pop(stackADT stack);
int StackDepth(stackADT stack);
int StackIsEmpty(stackADT stack);

