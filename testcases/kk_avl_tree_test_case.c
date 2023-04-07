#include<kk_avl_tree.h>
#include<stdio.h>
#include<stdlib.h>
int myComparator(void *left,void *right)
{
int *leftInt , *rightInt;
leftInt=(int *)left;
rightInt=(int *)right;
return (*leftInt)-(*rightInt);
}
int main()
{
int ch;
AVLTreeInOrderIterator inOrderIterator;
AVLTreepreOrderIterator preOrderIterator;
AVLTreePostOrderIterator   PostOrderIterator;
char more;
int *x;
int num;
AVLTree *tree;
int success;
tree=createAVLTree(&success,myComparator);
if(success==false)
{
printf("Unable to create tree,low on memory\n");
return 0;
}
while(1)
{
printf("1.Insert\n");
printf("2.In Order Traversal\n");
printf("3. Remove\n");
printf("4.Search\n");
printf("5.Pre Order Traversal\n");
printf("6.Post Order Traverse\n");
printf("7.Exit\n");
printf("Enter Your choice\n");
scanf("%d",&ch);
fflush(stdin);

if(ch==1)
{
printf("Enter number to be inserted in tree:");
scanf("%d",&num);
fflush(stdin);
x=(int *)malloc(sizeof(int));
*x=num;
insertIntoAVLTree(tree,(void *)x,&success);
if(success) printf("Address of item that contains %d inserted in tree",num);
else printf("Unable to insert in tree\n");
}
if(ch==2)
{
printf("In Order Iterator starts\n");
inOrderIterator=getAVLTreeInOrderIterator(tree,&success);
if(success)
{
while(hasNextInOrderElementInAVLTree(& inOrderIterator))
{
x=(int *)getNextInOrderElementFromAVLTree(&inOrderIterator, &success);
printf("%d\n", *x);
}
}
}
if(ch==3)
{
printf("Enter number to remove:");
scanf("%d",&num);
fflush(stdin);
x=removeFromAVLTree(tree,&num,& success);
if(success) printf("%d found and remove\n", *x);
else printf("%d not found\n", num);
}
if(ch==4)
{
printf("Enter number to search :");
scanf("%d" ,&num);
fflush(stdin);
x=getFromAVLTree(tree,&num,&success);
if(success) printf("%d found\n", *x);
else printf("%d not found\n",num);
}
if(ch==5)
{
printf("pre Order Iterator starts\n");
preOrderIterator=getAVLTreepreOrderIterator(tree,& success);
if(success)
{
while(hasNextpreOrderElementInAVLTree(&preOrderIterator))
{
x=(int *)getNextpreOrderElementFromAVLTree(&preOrderIterator,&success);
printf("%d\n",*x);
}
}
}
if(ch==6)
{
printf("Post Order Iterator starts\n");
PostOrderIterator=getAVLTreePostOrderIterator(tree,& success);
if(success)
{
while(hasNextPostOrderElementInAVLTree(&PostOrderIterator))
{
x=(int *)getNextPostOrderElementFromAVLTree(&PostOrderIterator,&success);
printf("%d\n",*x);
}
}
}

if(ch==7) break;
}
destroyAVLTree(tree);
return 0;
}
