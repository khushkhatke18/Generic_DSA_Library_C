#ifndef __KK_ARRAY__H
#define __KK_ARRAY__H 123
# include <kk_common.h>
typedef  struct ___array
{
int rows;
void  ***x;
int size;
}  Array;
Array  * createArray (int *success);
void setElementOfArray(Array *array,int index,void *element,int *success);
void *getElementOfArray(Array *array,int index);
int getSizeOfArray(Array *);
void destroyArray(Array *);
# endif
