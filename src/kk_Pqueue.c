#ifndef __KK_PQUEUE__C
#define __KK_PQUEUE__C  123
#include <stdio.h>
#include <stdlib.h>
#include <kk_Pqueue.h>
#include <kk_heap.h>
PQueue  *createPQueue(int (*predicate)(void *,void *),bool *success)
{
PQueue  *pQueue;
Heap  *heap;
heap=createHeap(predicate,success);
if( *success==false) return NULL;
pQueue=(PQueue *)malloc(sizeof(PQueue));
if(pQueue ==NULL)
{
// destroy Heap(heap)
if(success) *success=false;
return NULL;
}
pQueue ->heap=heap;
if(success) *success=true;
return pQueue;
}
void addToPQueue(PQueue *pQueue,void *ptr,bool *success)
{
if(success) *success=false;
if(pQueue ==NULL || pQueue ->heap==NULL) return;
addToHeap(pQueue ->heap, ptr,success);
}
void  * removeFromPQueue(PQueue *pQueue, bool *success)
{
void *ptr;
if(success) *success=false;
if(isPQueueEmpty(pQueue)) return NULL;
ptr=removeFromHeap(pQueue->heap,success);  // done
if(success) *success=true;
return ptr;
}
int getSizeofPQueue(PQueue *pQueue)
{
if(pQueue ==NULL || pQueue ->heap==NULL) return 0;
return getSizeOfHeap(pQueue-> heap);
}
void *elementAtFrontofPQueue(PQueue *pQueue,bool *success)
{
void *ptr;
if(success) *success=false;
if(isPQueueEmpty(pQueue)) return NULL;
ptr=elementAtTopOfHeap(pQueue ->heap,success);
if(success) *success=true;
return ptr;
}
bool isPQueueEmpty(PQueue *pQueue)
{
if(pQueue ==NULL) return true;
if(pQueue ->heap==NULL) return true;
if(getSizeOfHeap(pQueue ->heap)==0) return true;
return false;
}
void clearPQueue(PQueue *pQueue)
{
int succ;
if(pQueue ==NULL) return;
if(pQueue ->heap==NULL) return;
while(getSizeOfHeap(pQueue->heap) >0)
{
removeFromHeap(pQueue->heap,&succ);
}
}
void destroyPQueue(PQueue *pQueue)
{
if(pQueue==NULL) return;
destroyHeap(pQueue->heap);
free(pQueue);
}
#endif

