#ifndef  __KK_AVL_TREE__H
#define __KK_AVL_TREE__H 123
#include <kk_common.h>
#include <kk_stack.h>
    typedef struct __$_tm_avl_tree_node
{
    void *ptr;
    struct __$_tm_avl_tree_node *left;
struct __$_tm_avl_tree_node *right;
} AVLTreeNode;
typedef struct __$_tm_avl_tree
{
    struct __$_tm_avl_tree_node *start;
   int (*predicate) (void * , void *);
   int size;
} AVLTree;

typedef struct __$_tm_avl_tree_in_order_iterator
{
AVLTreeNode *node;
Stack *stack;
}AVLTreeInOrderIterator;

typedef struct __$_tm_avl_tree_pre_order_iterator
{
AVLTreeNode *node;
Stack *stack;
} AVLTreepreOrderIterator;

typedef struct __$_tm_avl_tree_Post_order_iterator
{
AVLTreeNode *node;
Stack *stack;
} AVLTreePostOrderIterator;

AVLTree *createAVLTree(bool *success,int ( *predicate ) ( void*,void* ) );
void destroyAVLTree(AVLTree *avlTree);
int getSizeofAVLTree(AVLTree *avlTree);
void insertIntoAVLTree(AVLTree *avlTree, void *ptr, bool *success );
void *removeFromAVLTree(AVLTree *avlTree,void *ptr, bool *success);
void clearAVLTree(AVLTree *avlTree);
void *getFromAVLTree(AVLTree *avlTree,void *ptr, bool *success);
AVLTreeInOrderIterator getAVLTreeInOrderIterator(AVLTree *avlTree,bool *success);
bool hasNextInOrderElementInAVLTree(AVLTreeInOrderIterator *avlTreeInOrderIterator);
void  * getNextInOrderElementFromAVLTree(AVLTreeInOrderIterator *avlTreeInOrderIterator,bool *success);

AVLTreepreOrderIterator getAVLTreepreOrderIterator(AVLTree *avlTree,bool *success);
bool hasNextpreOrderElementInAVLTree(AVLTreepreOrderIterator *avlTreepreOrderIterator);
void  * getNextpreOrderElementFromAVLTree(AVLTreepreOrderIterator *avlTreepreOrderIterator,bool *success);


AVLTreePostOrderIterator getAVLTreePostOrderIterator(AVLTree *avlTree,bool *success);
bool hasNextPostOrderElementInAVLTree(AVLTreePostOrderIterator *avlTreePostOrderIterator);
void  * getNextPostOrderElementFromAVLTree(AVLTreePostOrderIterator *avlTreePostOrderIterator,bool *success);

int getHeightofAVLTree(AVLTreeNode *root);
void balanceAVLTree( AVLTree *avlTree,Stack *stack);
#endif



