/*
    Problem Statement : Create a Queue and impliment the following functions.
                        1.Enqueue(Insert)
                        2.Dequeue(Delete)
                        3.Peek
                        4.Display
                        5.Count
*/

#include "Header.h"

int main()
{
    PNODE First = NULL;
    PNODE Last = NULL;

    int iRet = 0;
    int iChoice = 1;
    int iNo = 0;

    while(iChoice != 0)
    {
        printf("1.Enqueue(Insert)\n2.Dequeue(Delete)\n3.Peek\n4.Display\n5.Count\n0.Exit\n");
        printf("-------------------------------------------\n");
        printf("Enter your choice\n");
        scanf("%d",&iChoice);

        switch(iChoice)
        {
            case 1 : printf("Enter a number\n");
                     scanf("%d",&iNo);
                     Enqueue(&First,&Last,iNo);
                     break;

            case 2 : iRet = Dequeue(&First,&Last);
                     printf("Dequeued element is : %d\n",iRet);
                     break;

            case 3 : iRet = Peek(First);
                     printf("Peeked element is : %d\n",iRet);
                     break;

            case 4 : Display(First);
                     break;

            case 5 : iRet = Count(First);
                     printf("Number of elements in the queue are : %d\n",iRet);
                     break;

            case 0 : 
                     break;
                     
            default : printf("Error : Invalid Choice\n");
        }
    }
    return 0;
}