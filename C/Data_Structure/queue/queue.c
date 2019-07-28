/*
 * File: queue.c
 */
#include "queue.h"
#include <stdlib.h>
#include <stdio.h>
typedef struct cellT{
	queueElementT value;
	struct cellT *next;
}cellT;

struct queueCDT{
	cellT *front;
	cellT *rear;
};

queueADT EmptyQueue(void){
	queueADT queue;
	queue=(queueADT)malloc(sizeof(*queue));
	queue->front =NULL;
	queue->rear =NULL;
	return(queue);
}

void Enqueue(queueADT queue, queueElementT element){
    cellT *cp;
    cp = (cellT*)malloc(sizeof(cellT));
    cp->value=element;
    cp->next=NULL;
    if(queue->front==NULL)
        queue->front = cp;
    else
        queue->rear->next = cp;
    queue->rear = cp;
}


queueElementT Dequeue(queueADT queue){
   queueElementT result;
   if (queue->front==NULL){ 
       printf("Queue is empty.\n");
       exit(EXIT_FAILURE);
   }
   result = queue->front->value;
   queue->front = queue->front->next;
   return(result);
}

int QueueLength(queueADT queue) {
    int n=0;
    cellT *cp;
    for(cp=queue->front; cp!=NULL; cp=cp->next) n++;
    return(n);
} 

int QueueIsEmpty(queueADT queue) {
    return(queue->front==NULL);
 } 
