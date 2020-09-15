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

void Push(PPNODE,int);
int Pop(PPNODE);
int Peep(PNODE);
void Display(PNODE);
int Count(PNODE);