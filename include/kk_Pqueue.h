#ifndef __KK_PQUEUE__H
#define __KK_PQUEUE__H 123
#include <kk_common.h>
#include <kk_heap.h>

typedef struct __$_tm_Queue
{
Heap *heap;
}PQueue;

PQueue *createPQueue(int (*predicate )(void *,void *),bool *success);
void addToPQueue(PQueue  *pQueue, void *ptr,bool *success);
void *removeFromPQueue (PQueue  *pQueue,bool *success);
int getSizeofPQueue (PQueue  *pQueue);
void *elementAtFrontofPQueue (PQueue  *pQueue, bool *success);
bool  isPQueueEmpty(PQueue  *pQueue);
void clearPQueue (PQueue  *pQueue);
void destroyPQueue (PQueue  *pQueue);
#endif
