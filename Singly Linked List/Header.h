#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int iData;
    struct Node *next;
};


typedef struct Node NODE;
typedef struct Node * PNODE;
typedef struct Node ** PPNODE;

void InsertFirst(PPNODE,int);
void InsertLast(PPNODE,int);
void InsertAtPos(PPNODE,int,int);
void DeleteFirst(PPNODE);
void DeleteLast(PPNODE);
void DeleteAtPos(PPNODE,int);
int Count(PNODE);
void Display(PNODE);