
#include <stdio.h>
#define SPACE printf("\n\n\n")
#define ACTIVATED 1
#define DEACTIVATED 0
#define __DebugMode__ if(DebugModeState)


typedef int DataType;
typedef enum TypeOfHeapify
{
    MIN, MAX
}HEAPIFY_TYPE;

int Compare(DataType* A, DataType* B);
void Swap(DataType* A, DataType* B);
int LeftChildIndex(int index);
int RightChildIndex(int index);
int ParentIndex(int index);
int NodeIsValid(int index, int sizeOfHeap);
void Heapify(DataType* arrayX, int sizeOfHeap, HEAPIFY_TYPE MaxHeap);
void Heap_Down(DataType* arrayX, int sizeOfHeap, HEAPIFY_TYPE MaxHeap, int from_Node_Index);

static int DebugModeState = ACTIVATED;

int main()
{
    DataType a[] = {0,10,23,6,17,9,4,12,8,9,1};
    DataType b[] = {0,17,26,26,7,19,14,2,8,19,13,15,6,6,6,6,7};

    DataType* MyHeap = b;
    int HeapSize = sizeof(b) / sizeof(DataType);

    Heapify(MyHeap, HeapSize-1, MIN);

    for(int i=0; i<HeapSize; i++)
    {
        printf("%d  ", MyHeap[i]);
    }

    return 0;
}

int Compare(DataType* A, DataType* B)
{
    if(*A >= *B)
        return 1;
    else
        return 0;
}

void Swap(DataType* A, DataType* B)
{
    DataType temp;
    temp = *A;
    *A = *B;
    *B = temp;
}

int LeftChildIndex(int index)
{
    return 2 * index;
}

int RightChildIndex(int index)
{
    return 2 * index + 1;
}

int ParentIndex(int index)
{
    return index / 2;
}

int NodeIsValid(int index, int sizeOfHeap)
{
    if(index <= sizeOfHeap && index >= 1)
    {
        return 1;
    } else {
        return 0;
    }
}

void Heapify(DataType* arrayX, int sizeOfHeap, HEAPIFY_TYPE MaxHeap)
{
    for(int i=sizeOfHeap; i>=1; i--)
    {
        __DebugMode__
        {
            for(int k=0; k<sizeOfHeap+1; k++)
                printf("%d  ", arrayX[k]);

            SPACE;
        }

        Heap_Down(arrayX, sizeOfHeap, MaxHeap, i);
    }

}

void Heap_Down(DataType* arrayX, int sizeOfHeap, HEAPIFY_TYPE MaxHeap, int from_Node_Index)
{
    int Left_Child, Right_Child;

    Left_Child = LeftChildIndex(from_Node_Index);
    Right_Child = RightChildIndex(from_Node_Index);

    if(NodeIsValid(Left_Child, sizeOfHeap) && NodeIsValid(Right_Child, sizeOfHeap))
    {
        // IF NODE HAS BOTH CHILDREN -------------------------

        if(Compare(&arrayX[Left_Child], &arrayX[Right_Child]))
        {
            // Left Child Greater than Right
            //Right Child lesser than Left
            if(Compare(&arrayX[Left_Child], &arrayX[from_Node_Index]))
            {
                //Left Child greater than parent
                if(MaxHeap)
                {
                    Swap(&arrayX[Left_Child], &arrayX[from_Node_Index]);
                    Heap_Down(arrayX, sizeOfHeap, MaxHeap, Left_Child);
                }
            }

            if(Compare(&arrayX[from_Node_Index], &arrayX[Right_Child]))
            {
                if(!MaxHeap)
                {
                    Swap(&arrayX[from_Node_Index], &arrayX[Right_Child]);
                    Heap_Down(arrayX, sizeOfHeap, MaxHeap, Right_Child);
                }
            }

        } else {

            // Right Child Greater than Left
            // Left Child lesser than right
            if(Compare(&arrayX[Right_Child], &arrayX[from_Node_Index]))
            {
                //Right Child Greater than parent
                if(MaxHeap)
                {
                    Swap(&arrayX[Right_Child], &arrayX[from_Node_Index]);
                    Heap_Down(arrayX, sizeOfHeap, MaxHeap, Right_Child);
                }
            }

            if(Compare(&arrayX[from_Node_Index], &arrayX[Left_Child]))
            {
                if(!MaxHeap)
                {
                    Swap(&arrayX[from_Node_Index], &arrayX[Left_Child]);
                    Heap_Down(arrayX, sizeOfHeap, MaxHeap, Left_Child);
                }
            }

        }
    } else if (NodeIsValid(Left_Child, sizeOfHeap))
    {

        // IF NODE HAS ONLY LEFT CHILD -------------------------

        if(Compare(&arrayX[Left_Child], &arrayX[from_Node_Index]))
        {
            if(MaxHeap)
            {
                Swap(&arrayX[Left_Child], &arrayX[from_Node_Index]);
                Heap_Down(arrayX, sizeOfHeap, MaxHeap, Left_Child);
            }
        } else {

            if(!MaxHeap)
            {
                Swap(&arrayX[Left_Child], &arrayX[from_Node_Index]);
                Heap_Down(arrayX, sizeOfHeap, MaxHeap, Left_Child);
            }

        }
    } else if (NodeIsValid(Right_Child, sizeOfHeap))
    {

        // IF NODE HAS ONLY RIGHT CHILD -------------------------

        if(Compare(&arrayX[Right_Child], &arrayX[from_Node_Index]))
        {
            if(MaxHeap)
            {
                Swap(&arrayX[Right_Child], &arrayX[from_Node_Index]);
                Heap_Down(arrayX, sizeOfHeap, MaxHeap, Right_Child);
            }
        } else {

            if(!MaxHeap)
            {
                Swap(&arrayX[Right_Child], &arrayX[from_Node_Index]);
                Heap_Down(arrayX, sizeOfHeap, MaxHeap, Right_Child);
            }

        }
    }
}

void Heap_Up(DataType* arrayX, int sizeOfHeap, HEAPIFY_TYPE MaxHeap, int from_Node_Index)
{
    int parent_index = ParentIndex(from_Node_Index);

    if(NodeIsValid(parent_index, sizeOfHeap))
    {
        if(Compare(&arrayX[parent_index],&arrayX[from_Node_Index]))
        {
            // If parent greater than child
            if(!MaxHeap)
            {
                Swap(&arrayX[parent_index], &arrayX[from_Node_Index]);
                Heap_Up(arrayX, sizeOfHeap, MaxHeap, parent_index);
            }
        } else {

            if(MaxHeap)
            {
                Swap(&arrayX[parent_index], &arrayX[from_Node_Index]);
                Heap_Up(arrayX, sizeOfHeap, MaxHeap, parent_index);
            }

        }
    }

}
