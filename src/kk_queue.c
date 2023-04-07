#ifndef __KK_QUEUE__C
#define __KK_QUEUE__C  123
#include <stdio.h>
#include <stdlib.h>
#include <kk_queue.h>
#include <kk_sll.h>
Queue  *createQueue(bool *success)
{
Queue  *queue;
SinglyLinkedList  *singlyLinkedList;
singlyLinkedList=createSinglyLinkedList(success);
if( *success==false) return NULL;
queue=(Queue *)malloc(sizeof(Queue));
if(queue ==NULL)
{
destroySinglyLinkedList(singlyLinkedList);
if(success) *success=false;
return NULL;
}
queue ->singlyLinkedList=singlyLinkedList;
if(success) *success=true;
return queue;
}
void addToQueue(Queue *queue,void *ptr,bool *success)
{
if(success) *success=false;
if(queue ==NULL || queue ->singlyLinkedList==NULL) return;
addToSinglyLinkedList(queue ->singlyLinkedList, ptr,success);
}
void  * removeFromQueue(Queue *queue, bool *success)
{
void *ptr;
if(success) *success=false;
if(isQueueEmpty(queue)) return NULL;
ptr=removeFromSinglyLinkedList(queue->singlyLinkedList,0,success);
if(success) *success=true;
return ptr;
}
int getSizeofQueue(Queue *queue)
{
if(queue ==NULL || queue ->singlyLinkedList==NULL) return 0;
return  getSizeofSinglyLinkedList(queue-> singlyLinkedList);
}
void *elementAtFrontofQueue(Queue *queue,bool *success)
{
void *ptr;
if(success) *success=false;
if(isQueueEmpty(queue)) return NULL;
ptr=getFromSinglyLinkedList(queue ->singlyLinkedList,0,success);
if(success) *success=true;
return ptr;
}
bool isQueueEmpty(Queue *queue)
{
if(queue ==NULL) return true;
if(queue ->singlyLinkedList==NULL) return true;
if(getSizeofSinglyLinkedList(queue ->singlyLinkedList)==0) return true;
return false;
}
void clearQueue(Queue *queue)
{
if(queue ==NULL) return;
if(queue ->singlyLinkedList==NULL) return;
clearSinglyLinkedList(queue->singlyLinkedList);
}
void destroyQueue(Queue *queue)
{
if(queue==NULL) return;
if(queue ->singlyLinkedList==NULL) return ;
destroySinglyLinkedList(queue->singlyLinkedList);
free(queue);
}
#endif

