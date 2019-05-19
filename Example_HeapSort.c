/*
Written by: Guru Sarath
Date: 19 May 2019
*/

#include "Heap_API.h"

int main()
{
    float unsorted_ary[] = {1.3, 4.6, 7.8, 9.8, 7.8, 2.5};
    int size = sizeof(unsorted_ary) / sizeof(float);
    float* sorted_ary;

    sorted_ary = HeapSort(unsorted_ary, size, MAX);

    for(int i=0; i<size; i++)
    {
        printf("%f  ", sorted_ary[i]);
    }

}
