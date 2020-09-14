#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int iData;
    struct Node * next;
    struct Node * prev;
};

typedef struct Node NODE;
typedef struct Node * PNODE;
typedef struct Node ** PPNODE;

void InsertFirst(PPNODE,PPNODE,int);
void InsertLast(PPNODE,PPNODE,int);
void InsertAtPos(PPNODE,PPNODE,int,int);
void DeleteFirst(PPNODE,PPNODE);
void DeleteLast(PPNODE,PPNODE);
void DeleteAtPos(PPNODE,PPNODE,int);
int Count(PNODE,PNODE);
void Display(PNODE,PNODE);