
#include "Header.h"

int main()
{
    PNODE First = NULL;
    int iChoice = 1,iNo = 0,iRet = 0;

    while(iChoice != 0)
    {
        printf("1.Push\n2.Pop\n3.Peep\n4.Display\n5.Count the elements of stack\n0.Exit\n");
        printf("-----------------------------------\n");
        printf("Enter your choice\n");
        scanf("%d",&iChoice);

        switch(iChoice)
        {
            case 1 : printf("Enter a number\n");
                     scanf("%d",&iNo);
                     Push(&First,iNo);
                     break; 

            case 2 : iRet = Pop(&First);
                     printf("Popped element is : %d\n",iRet);
                     break;

            case 3 : iRet = Peep(First);
                     printf("Peeped Element is : %d\n",iRet);
                     break;

            case 4 : Display(First);
                     break;

            case 5 : iRet = Count(First);
                     printf("Number of stack frames are : %d\n",iRet);
                     break;

            case 0 : break;

            default : printf("Error : Invalid choice\n");
        }
    }
}