///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : Enqueue
// Parameters    : Address of first node,Address of last node,Integer
// Return Value  : None
// Desription    : It takes address of first and last pointe of queue and add the integer into queue
// Author        : Swapnil Ramesh Adhav
// Date          : 19th Sept 2020
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Header.h"

void Enqueue(PPNODE Head,PPNODE Tail,int iNo)
{
    PNODE NewNode = (PNODE)malloc(sizeof(NODE));
    NewNode->iData = iNo;
    NewNode->next = NULL;

    if(*Head==NULL && *Tail==NULL)
    {
        *Head = NewNode;
        *Tail = NewNode;
    }
    else
    {
        (*Tail)->next = NewNode;
        *Tail = NewNode;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : Dequeue
// Parameters    : Address of first node
// Return Value  : Integer
// Desription    : It takes address of first queue and add remove first element from queue
// Author        : Swapnil Ramesh Adhav
// Date          : 19th Sept 2020
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int Dequeue(PPNODE Head,PPNODE Tail)
{
    int iRet = 0;
    PNODE Temp = *Head;
    if(*Head==NULL)
    {
        return -1;
    }
    else if(Temp->next==NULL)
    {
        iRet = Temp->iData;
        free(Temp);
        *Head = NULL;
        *Tail = NULL;
    }
    else 
    {
        iRet = Temp->iData;
        *Head = Temp->next;
        free(Temp);
    }
    return iRet;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : Display
// Parameters    : first node,last node,Integer
// Return Value  : None
// Desription    : It takes first and last node of queue and display queue
// Author        : Swapnil Ramesh Adhav
// Date          : 19th Sept 2020
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int Peek(PNODE Head)
{
    int iRet = 0;
    if(Head==NULL)
    {
        return -1;
    }
    else
    {
        return Head->iData;
    }  
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : Display
// Parameters    : first node,last node
// Return Value  : None
// Desription    : It takes first and last node of queue and display queue
// Author        : Swapnil Ramesh Adhav
// Date          : 19th Sept 2020
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Display(PNODE Head)
{
    if((Head==NULL))
    {
        printf("Queue is empty\n");
        return ;
    }
    else
    {
        while(Head != NULL)
        {
            printf("| %d |.",Head->iData);
            Head = Head->next;
        }
    }
    printf("\n");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : Count
// Parameters    : first node,last node
// Return Value  : Integer
// Desription    : It takes first and last node of queue and count the elements in the queue
// Author        : Swapnil Ramesh Adhav
// Date          : 19th Sept 2020
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int Count(PNODE Head)
{
    int iCnt = 0;
    if((Head==NULL))
    {
        printf("Queue is empty\n");
        return 0;
    }
    else
    {
        while(Head != NULL)
        {
            iCnt++;
            Head = Head->next;
        }
    }
    return iCnt;
}