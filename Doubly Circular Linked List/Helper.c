///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : InsertFirst
// Parameters    : Address of first pointer , Address of last pointer , Integer
// Return Value  : None
// Description   : it takes address of first and last pointer of doubly circular lined list and add element in it at first position
// Author        : Swapnil Ramesh Adhav
// Date          : 13 Sept 2020
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Header.h"

void InsertFirst(PPNODE Head,PPNODE Tail,int iNo)
{
    PNODE NewNode = NULL;
    NewNode = (PNODE)malloc(sizeof(NODE));
    NewNode->iData = iNo;
    NewNode->next = NULL;
    NewNode->prev = NULL;

    if(*Head==NULL && *Tail==NULL)
    {
        *Head = NewNode;
        *Tail = NewNode;
    }
    if((*Head)->prev == *Tail)
    {
        NewNode->next= *Head;
        (*Head)->prev = NewNode;
        *Head = NewNode;
    }
    (*Tail)->next = *Head;
    (*Head)->prev = *Tail;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : InsertLast
// Parameters    : Address of first pointer , Address of last pointer , Integer
// Return Value  : None
// Description   : it takes address of first and last pointer of singly circular linked list and add element in it at last position
// Author        : Swapnil Ramesh Adhav
// Date          : 13 Sept 2020
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void InsertLast(PPNODE Head,PPNODE Tail,int iNo)
{
    PNODE NewNode = (PNODE)malloc(sizeof(NODE));
    NewNode->iData = iNo;
    NewNode->next = NULL;
    NewNode->prev = NULL;

    if(*Head==NULL && *Tail==NULL)
    {
        *Head = NewNode;
        *Tail = NewNode;
    }
    else
    {
        (*Tail)->next = NewNode;
        NewNode->prev = *Tail;
        *Tail = NewNode;
    }
    (*Tail)->next = *Head;
    (*Head)->prev = *Tail;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : InsertAtPos
// Parameters    : Address of first pointer , Address of last pointer , Integer , Integer
// Return Value  : None
// Description   : it takes address of first and last pointer of singly circular linked list and add element in it at perticular position
// Author        : Swapnil Ramesh Adhav
// Date          : 13 Sept 2020
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void InsertAtPos(PPNODE Head,PPNODE Tail,int iNo,int iPos)
{
    int iCount = Count(*Head,*Tail);
    PNODE Temp = *Head;
    int iCnt = 1;
    if(iPos<1 || iPos>iCount+1)
    {
        printf("Error : Invalid Position\n");
        return ;
    }
    else if(iPos==1)
    {
        InsertFirst(Head,Tail,iNo);
    }
    else if(iPos==iCount+1)
    {
        InsertLast(Head,Tail,iNo);
    }
    else
    {
        PNODE NewNode = (PNODE)malloc(sizeof(NODE));
        NewNode->iData = iNo;
        NewNode->next = NULL;
        NewNode->prev = NULL;\

        while(iCnt != iPos)
        {
            Temp = Temp->next;
            iCnt++;
        }
        NewNode->next = Temp;
        NewNode->prev = Temp->prev;
        Temp->prev->next = NewNode;
        Temp->prev = NewNode; 
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : DeleteFirst
// Parameters    : Address of first pointer , Address of last pointer
// Return Value  : None
// Description   : it takes address of first and last pointer of singly circular lined list and delete element at first position
// Author        : Swapnil Ramesh Adhav
// Date          : 13 Sept 2020
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void DeleteFirst(PPNODE Head,PPNODE Tail)
{
    if(*Head==NULL && *Tail==NULL)
    {
        return ;
    }
    else if(*Head == *Tail)
    {
        free(*Head);
        *Head = NULL;
        *Tail = NULL;
    }
    else
    {
        *Head = (*Head)->next;
        free((*Head)->prev);
        (*Head)->prev = *Tail;
        (*Tail)->next = *Head;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : DeleteLast
// Parameters    : Address of first pointer , Address of last pointer
// Return Value  : None
// Description   : it takes address of first and last pointer of singly circular lined list and delete element at last position
// Author        : Swapnil Ramesh Adhav
// Date          : 13 Sept 2020
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void DeleteLast(PPNODE Head,PPNODE Tail)
{
    if(*Head==NULL && *Tail==NULL)
    {
        return ;
    }
    else if(*Head == *Tail)
    {
        free(*Head);
        *Head = NULL;
        *Tail = NULL;
    }
    else
    {
        *Tail = (*Tail)->prev;
        free((*Tail)->next);
        (*Tail)->next = *Head;
        (*Head)->prev = *Tail;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : DeleteAtPos
// Parameters    : Address of first pointer , Address of last pointer , Integer
// Return Value  : None
// Description   : it takes address of first and last pointer of singly circular lined list and delete element at Perticular position
// Author        : Swapnil Ramesh Adhav
// Date          : 13 Sept 2020
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void DeleteAtPos(PPNODE Head,PPNODE Tail,int iPos)
{
    int iCount = Count(*Head,*Tail);
    PNODE Temp = *Head;
    int iCnt = 1;

    if(iPos<1 || iPos>iCount)
    {
        printf("Error : Invalid Position\n");
        return ;
    }
    else if(iPos==1)
    {
        DeleteFirst(Head,Tail);
    }
    else if(iPos==iCount)
    {
        DeleteLast(Head,Tail);
    }
    else
    {
        while(iCnt != iPos)
        {
            Temp = Temp->next;
            iCnt++;
        }
        Temp->prev->next = Temp->next;
        Temp->next->prev = Temp->prev;
        free(Temp);
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : Count
// Parameters    : first pointer , last pointer
// Return Value  : Integer
// Description   : it takes first and last node of linked list Count the number of nodes in it
// Author        : Swapnil Ramesh Adhav
// Date          : 13 Sept 2020
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int Count(PNODE Head,PNODE Tail)
{
    int iCnt = 0;

    if(Head==NULL && Tail==NULL)
    {
        return 0;
    }
    do
    {
        iCnt++;
        Head = Head->next;
    }while(Tail->next != Head);

    return iCnt;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : Display
// Parameters    : first pointer , last pointer
// Return Value  : None
// Description   : it takes first and last node of linked list and add display it
// Author        : Swapnil Ramesh Adhav
// Date          : 13 Sept 2020
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Display(PNODE Head,PNODE Tail)
{
    if(Head==NULL || Tail==NULL)
    {
        printf("| NULL |\n");
        return ;
    }
    do
    {
        printf("| %d |->",Head->iData);
        Head = Head->next;
    }while(Tail->next != Head);
    printf("| NULL |\n");
}