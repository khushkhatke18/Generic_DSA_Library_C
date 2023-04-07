#include<kk_array.h>
#include<stdio.h>
int main()
{
int i;
Array *array;
int x1,x2,x3;
int succ,*ptr;
array=createArray(&succ);
if(!succ)
{
printf("Unable to allocate array\n");
return 0;
}
x1=100;
x2=300;
x3=350;
setElementOfArray(array,2,(void *)&x1,&succ);
setElementOfArray(array,25,(void *)&x2,&succ);
setElementOfArray(array,1432,(void *)&x3,&succ);
for(i=0;i<getSizeOfArray(array);i++)
{
ptr=(int *)getElementOfArray(array,i);
if(ptr!=NULL) printf( "(%d--------> %d)",i,*ptr);
else printf("(%d------>)",i);
}
return 0;
}