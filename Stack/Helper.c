///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : Push
// Parameters    : Address of first node , Integer
// Return Value  : None
// Description   : It takes address of first node and Integer and add that element into stack frame
// Author        : Swapnil Ramesh Adhav
// Date          : 15th Sept 2020
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Header.h"

void Push(PPNODE Head,int iNo)
{
    PNODE NewNode = (PNODE)malloc(sizeof(NODE));
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
// Function Name : Pop
// Parameters    : Address of first node
// Return Value  : Integer
// Description   : It takes address of first node and remove upper most element from the stack frame and return that element.
// Author        : Swapnil Ramesh Adhav
// Date          : 15th Sept 2020
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int Pop(PPNODE Head)
{
    PNODE Temp = *Head;
    int iNo = 0;
    if(*Head==NULL)
    {
        return -1;
    }
    else
    {
        iNo = (*Head)->iData;
        *Head = Temp->next;
        free(Temp);
    }
    return iNo;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : Peep
// Parameters    : Address of first node
// Return Value  : Integer
// Description   : It takes address of first node and return the upper most element from the stack.
// Author        : Swapnil Ramesh Adhav
// Date          : 15th Sept 2020
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int Peep(PNODE Head)
{
    int iNo = 0;
    if(Head==NULL)
    {
        return -1;
    }
    else
    {
        iNo = Head->iData;
    }
    return iNo;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : Display
// Parameters    : first node
// Return Value  : None
// Description   : It takes first node and display the elements of stack 
// Author        : Swapnil Ramesh Adhav
// Date          : 15th Sept 2020
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void Display(PNODE Head)
{
    while(Head!=NULL)
    {
        printf("| %d |->",Head->iData);
        Head = Head->next;
    }
    printf("| NULL |\n");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : Count
// Parameters    : first node
// Return Value  : None
// Description   : It takes first node and count the number element in the stack
// Author        : Swapnil Ramesh Adhav
// Date          : 15th Sept 2020
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int Count(PNODE Head)
{
    int iCnt = 0;
    while(Head!=NULL)
    {
        iCnt++;
        Head = Head->next;
    }
    return iCnt;
}
