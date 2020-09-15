/*
    Problem Statement : Create a doubly linear linked list and impliment the following functions.
                        1.InsertFirst
                        2.InsertLast
                        3.InsertAtPos
                        4.DeleteFirst
                        5.DeleteLast
                        6.DeleteAtPos
                        7.Count
                        8.Display
                        9.Exit
*/

#include "Header.h"

int main()
{
    PNODE First = NULL;

    int iChoice = 0,iNo = 0,iRet = 0,iPos = 0;
    while(1)
    {
        printf("1.InsertFirst\n2.InsertLast\n3.InsertAtPos\n4.DeleteFirst\n5.DeleteLast\n6.DeleteAtPos\n7.Count\n8.Display\n9.Exit\n");
        printf("---------------------------\n");
        printf("Enter your choice\n");
        scanf("%d",&iChoice);

        switch(iChoice)
        {
            case 1 : printf("Enter a number\n");
                     scanf("%d",&iNo);
                     InsertFirst(&First,iNo);
                     break;

            case 2 : printf("Enter a number\n");
                     scanf("%d",&iNo);
                     InsertLast(&First,iNo);
                     break;

            case 3 : printf("Enter a number\n");
                     scanf("%d",&iNo);
                     printf("Enter position\n");
                     scanf("%d",&iPos);
                     InsertAtPos(&First,iNo,iPos);
                     break;

            case 4 : DeleteFirst(&First);
                     break;

            case 5 : DeleteLast(&First);
                     break;

            case 6 : printf("Enter position\n");
                     scanf("%d",&iPos);
                     DeleteAtPos(&First,iPos);
                     break;

            case 7 : iRet = Count(First);
                     printf("Number of elements in linked list is : %d\n",iRet);
                     break;

            case 8 : Display(First);
                     break;

            case 9 : exit(0);
            default : printf("Error : Invalid choice\n");
        }
    }
    return 0;
}

/*
PNODE Temp = *Head;
int iCount = 0
int iCnt = 1;
iCount = Count(*Head,*Tail);

if(iPos<1 || iPos>iCount)
{
    return ;
}
if(iPos==1)
{
    DeleteFirst(Head,Tail);
}
if(iPos==iCount)
{
    DeleteLast(Head,Tail);
}
else
{
    while(iCnt != iCount)
    {
        iCnt++;
        Temp = Temp->next;
    }
    Temp->prev->next = Temp->next;
    Temp->next->prev = Temp->prev;
    free(Temp);
}
*/