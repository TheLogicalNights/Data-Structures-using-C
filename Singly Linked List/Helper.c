///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : InsertFirst
// Parameters    : Address of first pointer,Integer
// Return Value  : None
// Description   : It takes address of first pointer of linked list and integer as input and insert that integer at first position of linked list
// Author        : Swapnil Ramesh Adhav
// Date          : 9th Sept 2020
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Header.h"

void InsertFirst(PPNODE Head,int iNo)
{
    PNODE NewNode = NULL;
    NewNode = (PNODE)malloc(sizeof(NODE));
    NewNode->iData = iNo;
    NewNode->next = NULL;

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
// Parameters    : Address of first pointer,Integer
// Return Value  : None
// Description   : It takes address of first pointer of linked list and integer as input and insert that integer at last position of linked list
// Author        : Swapnil Ramesh Adhav
// Date          : 9th Sept 2020
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void InsertLast(PPNODE Head,int iNo)
{
    PNODE NewNode = NULL;
    PNODE Temp = *Head;
    NewNode = (PNODE)malloc(sizeof(NODE));
    NewNode->iData = iNo;
    NewNode->next = NULL;

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
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : InsertAtPos
// Parameters    : Address of first pointer,Integer
// Return Value  : None
// Description   : It takes address of first pointer of linked list , integer and position as input and insert that integer at that position of linked list
// Author        : Swapnil Ramesh Adhav
// Date          : 9th Sept 2020
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void InsertAtPos(PPNODE Head,int iNo,int iPos)
{
    int iCnt = 0;
    iCnt = Count(*Head);
    int i = 1;
    PNODE Temp = *Head;
    PNODE Helper = NULL;

    if((iPos<1) || (iPos>iCnt+1))
    {
        printf("Error : Invalid Position\n");
        return ;
    }
    else if(iPos==1)
    {
        InsertFirst(Head,iNo);
    }
    else if(iPos==iCnt+1)
    {
        InsertLast(Head,iNo);
    }
    else
    {
        PNODE NewNode = (PNODE)malloc(sizeof(NODE));
        NewNode->iData = iNo;
        NewNode->next = NULL;
        while(i != iPos)
        {
            Helper = Temp;
            Temp = Temp->next;
            i++;
        }
        NewNode->next = Temp;
        Helper->next = NewNode;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : DeleteFirst
// Parameters    : Address of first pointer,Integer
// Return Value  : None
// Description   : It takes address of first pointer of linked list and delete first element of linked list
// Author        : Swapnil Ramesh Adhav
// Date          : 9th Sept 2020
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void DeleteFirst(PPNODE Head)
{
    PNODE Temp = *Head;

    if(*Head==NULL)
    {
        Display(*Head);
        return ;
    }
    else if(Temp->next==NULL)
    {
        free(Temp);
        *Head = NULL;
    }
    else
    {
        *Head = Temp->next;
        free(Temp);
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : DeleteAtPos
// Parameters    : Address of first pointer,Integer
// Return Value  : None
// Description   : It takes address of first pointer of linked list,position and delete element at that position  of linked list
// Author        : Swapnil Ramesh Adhav
// Date          : 9th Sept 2020
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void DeleteAtPos(PPNODE Head,int iPos)
{
    PNODE Temp = *Head;
    PNODE Helper = NULL;

    int iCnt = Count(*Head);
    int iCount = 1;
    if((iPos<0) || (iPos>iCnt))
    {
        printf("Error : Invalid Position\n");
        return ;
    }
    else if(iPos==1)
    {
        DeleteFirst(Head);
    }
    else if(iPos==iCnt)
    {
        DeleteLast(Head);
    }
    else
    {
        while(iCount != iPos)
        {
            Helper = Temp;
            Temp = Temp->next;
            iCount++;
        }
        Helper->next = Temp->next;
        free(Temp);
    }
}

void DeleteLast(PPNODE Head)
{
    PNODE Temp = *Head;
    PNODE Helper = NULL;

    if(Temp==NULL)
    {
        Display(Temp);
        return ;
    }
    else if(Temp->next==NULL)
    {
        free(Temp);
        *Head = NULL;
    }
    else
    {
        while(Temp->next != NULL)
        {
            Helper = Temp;
            Temp = Temp->next;
        }
        free(Temp);
        Helper->next=NULL;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : DeleteLast
// Parameters    : Address of first pointer,Integer
// Return Value  : None
// Description   : It takes address of first pointer of linked list and delete Last element of linked list
// Author        : Swapnil Ramesh Adhav
// Date          : 9th Sept 2020
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : Count
// Parameters    : first pointer,Integer
// Return Value  : Integer
// Description   : It takes first pointer of linked list and return the count of elements from the linked list
// Author        : Swapnil Ramesh Adhav
// Date          : 9th Sept 2020
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int Count(PNODE Head)
{
    int iCnt = 0;
    
    while(Head != NULL)
    {
        iCnt++;
        Head = Head->next;
    }
    
    return iCnt;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : Display
// Parameters    : first pointer,Integer
// Return Value  : None
// Description   : It takes first pointer of linked list and display the linked list
// Author        : Swapnil Ramesh Adhav
// Date          : 9th Sept 2020
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Display(PNODE Head)
{
    while(Head != NULL)
    {
        printf("| %d |->",Head->iData);
        Head = Head->next;
    }
    printf("| NULL |\n");
}
