#ifndef __KK_QUEUE__H
#define __KK_QUEUE__H 123
#include <kk_common.h>
#include <kk_sll.h>

typedef struct __$_tm_Queue
{
SinglyLinkedList *singlyLinkedList;
}Queue;

Queue *createQueue(bool *success);
void addToQueue(Queue  *queue, void *ptr,bool *success);
void *removeFromQueue (Queue  *queue,bool *success);
int getSizeofQueue (Queue  *queue);
void *elementAtFrontofQueue (Queue  *queue, bool *success);
bool  isQueueEmpty(Queue  *queue);
void clearQueue (Queue  *queue);
void destroyQueue (Queue  *queue);
#endif
