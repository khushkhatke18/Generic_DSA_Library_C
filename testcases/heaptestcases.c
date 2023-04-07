#include<kk_heap.h>
#include<stdio.h>
int comparator(void *left,void *right)
{
int *leftInt,*rightInt;
leftInt=(int *)left;
rightInt=(int *)right;
return(*leftInt)-(*rightInt);
}
int main()
{
Heap *heap;
int succ;
int x1,x2,x3,x4,x5,x6,x7;
int *ptr;
int i;
x1=10;
x2=-3;
x3=44;
x4=5;
x5=60;
x6=4;
heap=createHeap(comparator,&succ);
addToHeap(heap,(void *)&x1,&succ);
addToHeap(heap,(void *)&x2,&succ);
addToHeap(heap,(void *)&x3,&succ);
addToHeap(heap,(void *)&x4,&succ);
addToHeap(heap,(void *)&x5,&succ);
addToHeap(heap,(void *)&x6,&succ);
for(i=0;i<getSizeOfHeap(heap);i++)
{
ptr=getElementFromHeap(heap,i,&succ);
printf("%d\n",*ptr);
}
printf("Now updating\n");
x7=200;
updateElementInheap(heap,0,(void *)&x7,&succ);
for(i=0;i<getSizeOfHeap(heap);i++)
{
ptr=getElementFromHeap(heap,i,&succ);
printf("%d\n",*ptr);
}
return 0;
}