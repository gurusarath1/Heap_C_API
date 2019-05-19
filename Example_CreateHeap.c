/*
Written by: Guru Sarath
Date: 19 May 2019
*/

#include "Heap_API.h"

int main()
{
    HEAP* H = CreateHeap(5, MIN);

    InsertInHeap(H, 7.8);
    InsertInHeap(H, 1.2);
    InsertInHeap(H, 3.4);
    InsertInHeap(H, 4.1);


    if (InsertInHeap(H, 9.3) == 0)
    {
        printf("\nInsert Success :)");
    } else {
        printf("\nInsert Failed :)");
    }

    if (InsertInHeap(H, 5.3) == 0)
    {
        printf("Insert Success :)");
    } else {
        printf("Insert Failed :)");
    }

    printf("\nRemoved element : %f ", RemoveFromHeap(H));

}
