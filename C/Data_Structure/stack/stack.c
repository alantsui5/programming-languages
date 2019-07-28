/*
 * File:stack.c (version 1.0)
 */
#include<stdlib.h>
#include "stack.h"

struct stackCDT{
	stackElementT *elements;
	int count;
	int size;
};

stackADT EmptyStack(void){
	stackADT stack;
	stack=(stackADT)malloc(sizeof(*stack));
	stack->elements = (stackElementT*)malloc(5*sizeof(stackElementT));
	stack->count=0;
	stack->size=5;
	return(stack);
}

void Push(stackADT stack, stackElementT element){
	if(stack->count==stack->size){
	 	stack->size+=5;
		stack->elements=(stackElementT*)realloc(stack->elements,(stack->size)*sizeof(stackElementT));
		stack->elements[(stack->count)++]=element;
    }
}

stackElementT Pop(stackADT stack){
	stackElementT result;
	if(StackIsEmpty(stack)==1){exit{EXIT_FAILURE}}
	result = stack->elements[--(stack->count)];
	if(stack->count <= stack->size-5){
		stack->size -= 5;
		stack->elements = (stackElementT*)realloc(stack->elements,(stack->size)*sizeof(stackElementT));
	return(result);
    }
}


int StackDepth(stackADT stack){
	return(stack->count);
}

int StackIsEmpty(stackADT stack){
	return(stack->count==0);
}

/*End of stack.c*/


