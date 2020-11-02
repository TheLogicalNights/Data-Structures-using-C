///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : Insert
// Parameters    : Address of first pointer,Integer
// Return Value  : None 
// Description   : It is used to insert one integer into the tree
// Author        : Swapnil Ramesh Adhav
// Date          : 12th Oct 2020
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Header.h"

void Insert(PPNODE Root,int iNo)
{
    PNODE NewNode = (PNODE)malloc(sizeof(NODE));
    NewNode->iData=iNo;
    NewNode->lchild=NULL;
    NewNode->rchild=NULL;
    PNODE Temp = *Root;

    if(*Root==NULL)
    {
        *Root = NewNode;
    }
    else
    {
        while(1)
        {
            printf("%d\n",iNo);
            if((Temp->iData)==iNo)
            {
                printf("Element you entered is already present in the tree......\nWe cannot add duplicate elements\n");
                break;
            }
            if(iNo < (Temp->iData))
            {
                if(Temp->lchild==NULL)
                {
                    Temp->lchild = NewNode;
                    break;
                }
                Temp = Temp->lchild;
            }
            else if(iNo > (Temp->iData))
            {
                if(Temp->rchild==NULL)
                {
                    Temp->rchild = NewNode;
                    break;
                }
                Temp = Temp->rchild;
            }
        }
    }   
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : Search
// Parameters    : first pointer,Integer
// Return Value  : Boolean 
// Description   : It is used to search integer in the tree
// Author        : Swapnil Ramesh Adhav
// Date          : 12th Oct 2020
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOL Search(PNODE Root,int iNo)
{
    while(Root != NULL)
    {
        if((Root->iData) == iNo)
        {
            break;
        }
        if((Root->iData) < iNo)
        {
            Root = Root->rchild;
        }
        else 
        {
            Root = Root->lchild;
        }
    }
    if(Root==NULL)
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : Inorder
// Parameters    : first pointer
// Return Value  : None 
// Description   : It is used to data in the tree in Inorder manner
// Author        : Swapnil Ramesh Adhav
// Date          : 12th Oct 2020
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Inorder(PNODE Root)// LDR
{
    if(Root != NULL)
    {
        Inorder(Root->lchild);
        printf("%d\t",Root->iData);
        Inorder(Root->rchild);
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : Preorder
// Parameters    : first pointer
// Return Value  : None 
// Description   : It is used to data in the tree in Preorder manner
// Author        : Swapnil Ramesh Adhav
// Date          : 12th Oct 2020
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Preorder(PNODE Root)// DLR
{
    if(Root != NULL)
    {
        printf("%d\t",Root->iData);
        Preorder(Root->lchild);
        Preorder(Root->rchild);
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : Postorder
// Parameters    : first pointer
// Return Value  : None 
// Description   : It is used to data in the tree in Postorder manner
// Author        : Swapnil Ramesh Adhav
// Date          : 12th Oct 2020
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Postorder(PNODE Root)// LRD
{
    if(Root != NULL)
    {
        Postorder(Root->lchild);
        Postorder(Root->rchild);
        printf("%d\t",Root->iData);
    }
}