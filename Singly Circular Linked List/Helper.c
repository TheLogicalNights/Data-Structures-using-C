///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : InsertFirst
// Parameters    : Address of first pointer , Address of last pointer , Integer
// Return Value  : None
// Description   : it takes address of first and last pointer of singly circular lined list and add element in it at first position
// Author        : Swapnil Ramesh Adhav
// Date          : 12 Sept 2020
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Header.h"

void InsertFirst(PPNODE Head,PPNODE Tail,int iNo)
{
    PNODE NewNode = (PNODE)malloc(sizeof(NODE));
    NewNode->iData = iNo;
    NewNode->next = NULL;

    if(*Head==NULL || *Tail ==NULL)
    {
        *Head = NewNode;
        *Tail = NewNode; 
    }
    else
    {
        NewNode->next = *Head;
        *Head = NewNode;
    }
    (*Tail)->next = *Head;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : InsertLast
// Parameters    : Address of first pointer , Address of last pointer , Integer
// Return Value  : None
// Description   : it takes address of first and last pointer of singly circular linked list and add element in it at last position
// Author        : Swapnil Ramesh Adhav
// Date          : 12 Sept 2020
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void InsertLast(PPNODE Head,PPNODE Tail,int iNo)
{
    PNODE NewNode = (PNODE)malloc(sizeof(NODE));
    NewNode->iData = iNo;
    NewNode->next = NULL;

    if(*Head==NULL || *Tail==NULL)
    {
        *Head = NewNode;
        *Tail = NewNode;
    }
    else
    {
        (*Tail)->next = NewNode;
        *Tail = NewNode;
    }
    (*Tail)->next = *Head;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : InsertLast
// Parameters    : Address of first pointer , Address of last pointer , Integer , Integer
// Return Value  : None
// Description   : it takes address of first and last pointer of singly circular linked list and add element in it at perticular position
// Author        : Swapnil Ramesh Adhav
// Date          : 12 Sept 2020
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void InsertAtPos(PPNODE Head,PPNODE Tail,int iNo,int iPos)
{
    PNODE Temp = *Head;
    PNODE Helper = NULL;
    int iCount = 0;
    iCount = Count(*Head,*Tail);
    int iCnt = 0;

    if(iPos<1 || iPos>iCount+1)
    {
        return ;
    }

    if(iPos==1)
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
        for(iCnt=1;iCnt!=iPos;iCnt++)
        {
            Helper = Temp;
            Temp = Temp->next;
        }
        NewNode->next = Temp;
        Helper->next = NewNode;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : DeleteFirst
// Parameters    : Address of first pointer , Address of last pointer
// Return Value  : None
// Description   : it takes address of first and last pointer of singly circular lined list and delete element at first position
// Author        : Swapnil Ramesh Adhav
// Date          : 12 Sept 2020
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void DeleteFirst(PPNODE Head,PPNODE Tail)
{
    PNODE Temp = *Head;

    if(Head==NULL || Tail==NULL)
    {
        return ;
    }
    else if(*Head == *Tail)
    {
        *Head = NULL;
        *Tail = NULL;
        free(Temp);
    }
    else
    {
        *Head = Temp->next;
        (*Tail)->next = *Head;
        free(Temp);
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : DeleteLast
// Parameters    : Address of first pointer , Address of last pointer
// Return Value  : None
// Description   : it takes address of first and last pointer of singly circular lined list and delete element at last position
// Author        : Swapnil Ramesh Adhav
// Date          : 12 Sept 2020
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void DeleteLast(PPNODE Head,PPNODE Tail)
{
    PNODE Temp = *Head;

    if(*Head==NULL || *Tail==NULL)
    {
        return ;
    }
    else if(*Head == *Tail)
    {
        *Head = NULL;
        *Tail = NULL;
        free(Temp);
    }
    else
    {
        while(Temp->next != *Tail)
        {
            Temp = Temp->next;
        }
        free(*Tail);
        *Tail = Temp;
        (*Tail)->next = *Head;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : DeleteAtPos
// Parameters    : Address of first pointer , Address of last pointer , Integer
// Return Value  : None
// Description   : it takes address of first and last pointer of singly circular lined list and delete element at Perticular position
// Author        : Swapnil Ramesh Adhav
// Date          : 12 Sept 2020
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void DeleteAtPos(PPNODE Head,PPNODE Tail,int iPos)
{
    PNODE Temp = *Head;
    PNODE Helper = NULL;
    int iCount = 0;

    iCount = Count(*Head,*Tail);

    int iCnt = 0;

    if(iPos<1 || iPos>iCount)
    {
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
        for(iCnt=1;iCnt!=iPos;iCnt++)
        {
            Helper = Temp;
            Temp = Temp->next;
        }
        Helper->next = Temp->next;
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
// Date          : 12 Sept 2020
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int Count(PNODE Head,PNODE Tail)
{
    int iCnt = 0;

    if(Head==NULL || Tail==NULL)
    {
        return 0;
    }
    do
    {
        iCnt++;
        Head = Head->next;
    }while(Head != Tail->next);
    
    return iCnt;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : Display
// Parameters    : first pointer , last pointer
// Return Value  : None
// Description   : it takes first and last node of linked list and add display it
// Author        : Swapnil Ramesh Adhav
// Date          : 12 Sept 2020
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Display(PNODE Head,PNODE Tail)
{
    if(Head==NULL || Tail==NULL)
    {
        return ;
    }
    do
    {
        printf("| %d |->",Head->iData);
        Head = Head->next;
    }while(Head != Tail->next);
    
    printf("| NULL |\n");
}