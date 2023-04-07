#include<kk_Pqueue.h>
#include<stdio.h>
int myComparator(void *left,void *right)
{
int *leftInt;
int *rightInt;
leftInt=(int *)left;
rightInt=(int *)right;
return (*leftInt) -(*rightInt);
}
int main()
{
int x1,x2,x3,x4,x5;
int succ;
int *ptr;
PQueue *pQueue;
pQueue=createPQueue(myComparator,&succ);
if(!succ)
{
printf("Low on memory\n");
return 0;
}
x1=100;
x2=30;
x3=50;
x4=25;
x5=15;
addToPQueue(pQueue,&x1,&succ);
addToPQueue(pQueue,&x2,&succ);
addToPQueue(pQueue,&x3,&succ);
addToPQueue(pQueue,&x4,&succ);
addToPQueue(pQueue,&x5,&succ);
while(getSizeofPQueue(pQueue)>0)
{
ptr=removeFromPQueue(pQueue,&succ);
printf("%d\n",*ptr);
}
// destory PQueue(pQueue)
}