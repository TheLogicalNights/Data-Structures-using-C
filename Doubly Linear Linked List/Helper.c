///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : InsertFirst
// Parameters    : Address of First Node ,Integer
// Return Value  : None
// Description   : it takes address of first node of linked list and insert a integer at first position in it
// Author        : Swapnil Ramesh Adhav
// Date          : 15th Sept 2020
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Header.h"

void InsertFirst(PPNODE Head,int iNo)
{
    PNODE NewNode = (PNODE)malloc(sizeof(NODE));
    NewNode->iData = iNo;
    NewNode->next = NULL;
    NewNode->prev = NULL;

    if(*Head==NULL)
    {
        *Head = NewNode;
    }
    else
    {
        NewNode->next = *Head;
        *Head = NewNode;
    }
    
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : InsertLast
// Parameters    : Address of First Node ,Integer
// Return Value  : None
// Description   : it takes address of first node of linked list and insert a integer at last position in it
// Author        : Swapnil Ramesh Adhav
// Date          : 15th Sept 2020
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void InsertLast(PPNODE Head,int iNo)
{
    PNODE NewNode = (PNODE)malloc(sizeof(NODE));
    NewNode->iData = iNo;
    NewNode->next = NULL;
    NewNode->prev = NULL;
    PNODE Temp = *Head;

    if(*Head==NULL)
    {
        *Head = NewNode;
    }
    else
    {
        while(Temp->next != NULL)
        {
            Temp = Temp->next;
        }
        Temp->next = NewNode;
        NewNode->prev = Temp;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : InsertAtPos
// Parameters    : Address of First Node ,Integer,Integer
// Return Value  : None
// Description   : it takes address of first node of linked list and insert a integer at perticular position in it
// Author        : Swapnil Ramesh Adhav
// Date          : 15th Sept 2020
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void InsertAtPos(PPNODE Head,int iNo,int iPos)
{
    int iCnt = 1;
    int iCount = Count(*Head);
    PNODE Temp = *Head;

    if(iPos<1 || iPos>iCount+1)
    {
        return ;
    }
    else if(iPos==1)
    {
        InsertFirst(Head,iNo);
    }
    else if(iPos==iCount+1)
    {
        InsertLast(Head,iNo);
    }
    else
    {
        PNODE NewNode = (PNODE)malloc(sizeof(NODE));
        NewNode->iData = iNo;
        NewNode->next = NULL;
        NewNode->prev = NULL;

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
// Parameters    : Address of First Node
// Return Value  : None
// Description   : it takes address of first node of linked list and delete first elemet from it.
// Author        : Swapnil Ramesh Adhav
// Date          : 15th Sept 2020
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void DeleteFirst(PPNODE Head)
{
    PNODE Temp = *Head;
    if(*Head==NULL)
    {
        return ;
    }
    else if(Temp->next == NULL)
    {
        free(Temp);
        *Head = NULL;
    }
    else
    {
        *Head = Temp->next;
        free(Temp);
        (*Head)->prev = NULL;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : DeleteLast
// Parameters    : Address of First Node
// Return Value  : None
// Description   : it takes address of first node of linked list and delete Last elemet from it.
// Author        : Swapnil Ramesh Adhav
// Date          : 15th Sept 2020
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void DeleteLast(PPNODE Head)
{
    PNODE Temp = *Head;

    if(*Head==NULL)
    {
        return ;
    }
    if(Temp->next==NULL)
    {
        free(Temp);
        *Head = NULL;
    }
    else
    {
        while(Temp->next != NULL)
        {
            Temp = Temp->next;
        }
        Temp = Temp->prev;
        free(Temp->next);
        Temp->next=NULL;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : DeleteAtPos
// Parameters    : Address of First Node , Integer
// Return Value  : None
// Description   : it takes address of first node of linked list and delete element at perticular position from it.
// Author        : Swapnil Ramesh Adhav
// Date          : 15th Sept 2020
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void DeleteAtPos(PPNODE Head,int iPos)
{
    int iCnt = 1,iCount = 0;
    iCount = Count(*Head);
    if(iPos<1 || iPos>iCount)
    {
        return ;
    }
    else if(iPos==1)
    {
        DeleteFirst(Head);
    }
    else if(iPos==iCount)
    {
        DeleteLast(Head);
    }
    else
    {
        PNODE Temp = *Head;
        while(iCnt!=iPos)
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
// Function Name : Display
// Parameters    : First Node
// Return Value  : None
// Description   : it takes first node of linked list and Display it
// Author        : Swapnil Ramesh Adhav
// Date          : 15th Sept 2020
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Display(PNODE Head)
{
    while (Head != NULL)
    {
        printf("| %d |<=>",Head->iData);
        Head = Head->next;
    }
    printf("| NULL |\n");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : Count
// Parameters    : First Node
// Return Value  : Integer
// Description   : it takes first node of linked list and count the number of elements
// Author        : Swapnil Ramesh Adhav
// Date          : 15th Sept 2020
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int Count(PNODE Head)
{
    int iCnt = 0;
    while (Head != NULL)
    {
        iCnt++;
        Head = Head->next;
    }
    return iCnt;
}