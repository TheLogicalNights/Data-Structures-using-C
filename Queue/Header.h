#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int iData;
    struct Node * next;
}NODE,*PNODE,**PPNODE;

void Enqueue(PPNODE,PPNODE,int);
int Dequeue(PPNODE,PPNODE);
int Peek(PNODE);
void Display(PNODE);
int Count(PNODE);