#ifndef __KK_HEAP__H
#define __KK_HEAP__H 123
# include <kk_common.h>
#include<kk_array.h>
typedef   struct ___heap
{
Array *array;
int (*comparator)(void *,void *);
int size;
} Heap;

Heap *createHeap(int (*comparator)(void *,void *),int *success);
void addToHeap(Heap *heap,void *element,int * success);
void  *removeFromHeap(Heap *heap,int *success);
void *elementAtTopOfHeap(Heap *heap,int *success);
int getSizeOfHeap(Heap *heap);
void destroyHeap(Heap *heap);
void *getElementFromHeap(Heap *heap,int index,int *success);
void updateElementInheap(Heap *heap,int index,void *element,int *success);
#endif