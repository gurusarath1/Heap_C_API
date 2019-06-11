/*
API Written by: Guru Sarath
Date: 19 May 2019
*/

// MODIFY THE CODE BELOW ACCORDING TO YOUR REQUIREMENTS
typedef float DataType;

// YOU CANNOT MODIFY THIS ENUM
typedef enum TypeOfHeapify
{
    MIN, MAX
}HEAPIFY_TYPE;

// YOU CANNOT MODIFY THIS STRUCT
typedef struct HEAP
{
    DataType* Heap;
    int sizeOfHeap;
    int MaxCapacity;
    int currentLocationToInsert;
    HEAPIFY_TYPE HeapType;

}HEAP;

// YOU CANNOT MODIFY THESE FUNCTION PROTOTYPES
int Compare(DataType* A, DataType* B);
void Swap(DataType* A, DataType* B);
int LeftChildIndex(int index);
int RightChildIndex(int index);
int ParentIndex(int index);
int NodeIsValid(int index, int sizeOfHeap);
void Heapify(DataType* arrayX, int sizeOfHeap, HEAPIFY_TYPE MaxHeap);
void Heap_Down(DataType* arrayX, int sizeOfHeap, HEAPIFY_TYPE MaxHeap, int from_Node_Index);
HEAP* CreateHeap(int MaxCapacity, HEAPIFY_TYPE type);
int InsertInHeap(HEAP* HeapX, DataType dataToInsert);
DataType RemoveFromHeap(HEAP* HeapX);
DataType* HeapSort(DataType* aryX, int sizeOfArray, HEAPIFY_TYPE maxHeap);


