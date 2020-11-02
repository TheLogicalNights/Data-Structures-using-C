/*
    Problem Statement : Create one binary search tree(BST) and impliment the following functions
                        1.Insert
                        2.Search
                        3.InorderDisplay
                        4.PreorderDisplay
                        5.PostorderDisplay
*/

#include "Header.h"

int main()
{
    PNODE First = NULL;
    int iNo = 0;
    int iChoice = 1;
    BOOL bRet = FALSE;
    while(iChoice!=0)
    {
        printf("1.Insert\n2.Search\n3.InorderDisplay\n4.PreorderDisplay\n5.PostorderDisplay\n0.Exit\n");
        printf("-------------------------------\n");
        printf("Enter your choice.....\n");
        scanf("%d",&iChoice);

        switch(iChoice)
        {
            case 1 : printf("Enter a number\n");
                     scanf("%d",&iNo);
                     Insert(&First,iNo);
                     break;

            case 2 : printf("Enter a number that you want to search\n");
                     scanf("%d",&iNo);
                     bRet = Search(First,iNo);
                     if(bRet==TRUE)
                     {
                         printf("Element is present in tree\n");
                     }
                     else
                     {
                         printf("There is no such element\n");
                     }
                     
                     break;
            
            case 3 : Inorder(First);
                     printf("\n");
                     break;
            
            case 4 : Preorder(First);
                     printf("\n");
                     break;
            
            case 5 : Postorder(First);
                     printf("\n");
                     break;
            
            case 0 : printf("Thank you for using our application...\n");
                     break;
        }
    }

    return 0;
}