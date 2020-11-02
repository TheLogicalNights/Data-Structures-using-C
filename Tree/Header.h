#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0

typedef struct Node
{
    int iData;
    struct Node * lchild;
    struct Node * rchild;
}NODE,*PNODE,**PPNODE;

typedef int BOOL;

void Insert(PPNODE,int);
BOOL Search(PNODE,int);
void Inorder(PNODE);
void Preorder(PNODE);
void Postorder(PNODE);