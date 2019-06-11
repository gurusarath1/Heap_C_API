/*
API Written by: Guru Sarath
Date: 19 May 2019
*/

#include "Heap_API.h"

/*
    Function Name: CreateHeap
    Inputs: Maximum size of heap; Type of heap (MIN or MAX)
    Output: Pointer to a heap structure
    Description: This function creates a heap structure
*/
// YOU CANNOT MODIFY THIS FUNCTION
HEAP* CreateHeap(int MaxCapacity, HEAPIFY_TYPE type)
{
    HEAP* H = (HEAP*)malloc(sizeof(HEAP));
    DataType* D = (DataType*)malloc(sizeof(DataType)*MaxCapacity + 1);

    H->Heap = D;
    H->MaxCapacity = MaxCapacity;
    H->sizeOfHeap = 0;
    H->currentLocationToInsert = 1;
    H->HeapType = type;

    return H;
}

/*
    Function Name: Compare
    Inputs: Two data values to compare (pointers)
    Output: int ( return 1 if First value greater than or equal to second value else return 0)
    Description: Rule to compare the two objects of type DataType
*/
int Compare(DataType* A, DataType* B)
{
    // MODIFY THE CODE BELOW ACCORDING TO YOUR REQUIREMENTS
    if(*A >= *B)
        return 1;
    else
        return 0;
}

/*
    Function Name: Swap
    Inputs: Pointers to two data values
    Output: none
    Description: Swap
*/
// YOU CANNOT MODIFY THIS FUNCTION
void Swap(DataType* A, DataType* B)
{
    DataType temp;
    temp = *A;
    *A = *B;
    *B = temp;
}

/*
    Function Name: LeftChildIndex
    Inputs: Index of parent
    Output: Index of left child
    Description: Returns left child index
*/
// YOU CANNOT MODIFY THIS FUNCTION
int LeftChildIndex(int index)
{
    return 2 * index;
}

/*
    Function Name: RightChildIndex
    Inputs: Index of parent
    Output: Index of right child
    Description: Returns right child index
*/
// YOU CANNOT MODIFY THIS FUNCTION
int RightChildIndex(int index)
{
    return 2 * index + 1;
}

/*
    Function Name: ParentIndex
    Inputs: Index of left or right child
    Output: Index of parent
    Description: Returns the index of parent
*/
// YOU CANNOT MODIFY THIS FUNCTION
int ParentIndex(int index)
{
    return index / 2;
}

/*
    Function Name: NodeIsValid
    Inputs: index of node; Size of Heap (in which the node is present)
    Output: 1 - Valid; 0-Invalid
    Description: Checks if index of a node is valid
*/
// YOU CANNOT MODIFY THIS FUNCTION
int NodeIsValid(int index, int sizeOfHeap)
{
    if(index <= sizeOfHeap && index >= 1)
    {
        return 1;
    } else {
        return 0;
    }
}

/*
    Function Name: Heapify
    Inputs: DataType arrayX; size of array; Type of heap to create (MIN/MAX)
    Output: None
    Description: Modifies arrayX to a MIN Heap or MAX Heap
*/
// YOU CANNOT MODIFY THIS FUNCTION
void Heapify(DataType* arrayX, int sizeOfHeap, HEAPIFY_TYPE MaxHeap)
{
    for(int i=sizeOfHeap; i>=1; i--)
    {
        Heap_Down(arrayX, sizeOfHeap, MaxHeap, i);
    }

}

/*
    Function Name: Heap_Down
    Inputs: DataType arrayX; size of array; Type of heap to create (MIN/MAX); Node from which heap property to check
    Output: None
    Description: This function is used after deletion operation
*/
// YOU CANNOT MODIFY THIS FUNCTION
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


/*
    Function Name: Heap_Down
    Inputs: DataType arrayX; size of array; Type of heap to create (MIN/MAX); Node from which heap property to check
    Output: None
    Description: This function is used after insertion operation
*/
// YOU CANNOT MODIFY THIS FUNCTION
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

/*
    Function Name: InsertInHeap
    Inputs: Heap structure pointer; Data to insert in heap
    Output: 0 - Success; 1 - Failed to insert
    Description: This function is used to insert an element in the heap
*/
// YOU CANNOT MODIFY THIS FUNCTION
int InsertInHeap(HEAP* HeapX, DataType dataToInsert)
{
    if(HeapX->currentLocationToInsert <= HeapX->MaxCapacity)
    {
        HeapX->Heap[HeapX->currentLocationToInsert] = dataToInsert;
        HeapX->sizeOfHeap++;
        Heap_Up(HeapX->Heap, HeapX->sizeOfHeap, HeapX->HeapType, HeapX->currentLocationToInsert);
        HeapX->currentLocationToInsert++;

        return 0; //SUCCESS
    } else {
        return 1; //FAILED
    }

}

/*
    Function Name: RemoveFromHeap
    Inputs: Heap structure pointer
    Output: Returns the root element of the heap
    Description: This function is used to delete the root element from the heap
*/
// YOU CANNOT MODIFY THIS FUNCTION
DataType RemoveFromHeap(HEAP* HeapX)
{
    DataType RootElement;

    if(HeapX->sizeOfHeap > 0 && HeapX->MaxCapacity > 0)
    {
        RootElement = HeapX->Heap[1];
        HeapX->Heap[1] = HeapX->Heap[HeapX->sizeOfHeap];
        HeapX->sizeOfHeap--;
        Heap_Down(HeapX->Heap, HeapX->sizeOfHeap, HeapX->HeapType, 1);

        return RootElement;

    } else {
        return RootElement; //FAILED
    }
}

/*
    Function Name: HeapSort
    Inputs: DataType arrayX, size of the array, MIN/MAX = Ascending or Descending
    Output: Pointer to sorted DataType array
    Description: This function performs heap sort
*/
// YOU CANNOT MODIFY THIS FUNCTION
DataType* HeapSort(DataType* aryX, int sizeOfArray, HEAPIFY_TYPE maxHeap)
{
    HEAP* H = CreateHeap(sizeOfArray, maxHeap);
    DataType* SortedArray = (DataType*) malloc(sizeof(DataType) * sizeOfArray);
    int index = 0;

    for(int i=1; i<=sizeOfArray; i++)
    {
        InsertInHeap(H, aryX[i-1]);
    }

    while(H->sizeOfHeap > 0)
    {
        SortedArray[index] = RemoveFromHeap(H);
        index++;
    }

    return SortedArray;

}