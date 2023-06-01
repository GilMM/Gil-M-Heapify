#include "heapify.h"

/* Maman 13 , Gil Meshulami */

int main()
{
    q1();
}

void q1()
{
    int arr[SIZE];
    int i;
    FILE*file = fopen("test.data", "r");
    if(file == NULL)
    {
        printf("Could not open the file\n");
        return;
    }
    for(i = 1; i < SIZE && !feof(file); i++)
    {
        fscanf(file, "%d", &arr[i]);
    }
    fclose(file);
    int size = i - 2;
    printHeap(arr, size); 
    buildHeap(arr, size);
    int option = -1;
    while(option != 0)
    {
        printf("\nplease choose one of the options:\n 0. to stop the program\n 1. to insert number to the heap\n 2. to extract the max number and delete it\n 3. to extract the min number and delete it\n 4. index to delete\n 5. to sort the heap\n ");
        scanf("%d", &option);
        switch (option)
        {
        case 0:
            break;
        case 1:
            heapInsert(arr, &size);
            break;
        case 2:
        	extractMax(arr, &size);
        	break;  
        case 3:
        	extractMin(arr, &size);
        	break;	 
        case 4:
        	prepareHeapDelete(arr, &size);
        	break;
        case 5:
        	heapSort(arr, size);
        	break;	 
        default:
            printf("invalid option\n");
            break;
        }
    } 
}

/* this function checks the root of the with the values of its left and right child nodes,
 if the value of the root node is reater than the values of his children, then it keeps the max heap property.
 and if one of the children has a greater value than the father(root node), its swap it with the maximun value.
 and repeat it recursively. */ 
void maxHeapify(int arr[], int size, int rootIndex) /* log n */
{
    int left = rootIndex * 2;
    int right = left + 1;
    int max = arr[rootIndex];
    int maxIndex = rootIndex;
    if(left > size)
    {
        return;
    }
    if(arr[left] > max)
    {
        max = arr[left];
        maxIndex = left;
    }
    if(right <= size && arr[right] > max)
    {
        max = arr[right];
        maxIndex = right;
    }
    if(maxIndex != rootIndex)
    {
        int temp = arr[rootIndex];
        arr[rootIndex] = arr[maxIndex];
        arr[maxIndex] = temp;
        maxHeapify(arr, size, maxIndex);
    }
}

/* This function builds the heap, its goes through the nodes in the the tree and runs max heapify on each of them. */
void buildHeap(int arr[], int size)  /* n log n */
{
	int i;    
    for(i = size - 1; i > 0; i--)
    {
        maxHeapify(arr, size, i);
    }
    printHeap(arr, size);
}  

/* This function prints the heap and arrange it like a tree */
void printHeap(int arr[], int size)
{
    int i, lineSize, j, power, numLines;
    for (numLines = 0, power = 1; power <= size; power *= 2, numLines++)
    { }
    int widthOfItem = 4 * power, numSpaces;
    printf("size = %d\n", size);
    for (lineSize = 1, i = 1; i <= size; lineSize *= 2)
    {
        widthOfItem /= 2;
        numSpaces = (widthOfItem - 4) / 2;
        for (j = 0; j < lineSize && i <= size; j++, i++)
        {
            printSpaces(numSpaces);
            printf("%3d ", arr[i]);
            printSpaces(numSpaces);
        }
        printf("\n");
    }
    printf("\n");
}

void printSpaces(int numSpaces)
{
    int i;
    for (i = 0; i < numSpaces; ++i)
    {
        printf(" ");
    }
}

/* This function get a value from the user and insert it to the heap and arrange it */
void heapInsert(int arr[], int *pSize) /* log n */
{
    int value, size = *pSize + 1;
    printf("enter a value: \n");
    scanf("%d", &value);
    arr[size] = value;
    int index = size;
    int father = index/2;
    int temp;
    while(index > 1 && arr[index] > arr[father])
    {
        temp = arr[father];
        arr[father] = arr[index];
        arr[index] = temp;
        index = father;
        father = index/2;
    }
    printHeap(arr, size);
	*pSize = size;
}

/* This function takes the maximum in the heap and delete it */
void extractMax(int arr[], int *pSize)  /* log n */
{
	printf("max was %d\n", arr[1]);
	heapDelete(arr, pSize, 1);
}	

/* This function takes the minimum in the heap and delete it */
void extractMin(int arr[], int *pSize) /* log n */
{
	int size = *pSize;
	int minIndex = findIndexOfMin(arr, size, 1);
	printf("min = %d at index %d\n", arr[minIndex], minIndex);	
	heapDelete(arr, pSize, minIndex);
}

/* This function help us to find the minumum */
int findIndexOfMin(int arr[], int size, int rootIndex) /* log n */
{
    int left = rootIndex * 2;
    int right = left + 1;
    int min = arr[rootIndex];
    int minIndex = rootIndex;
    int temp;
    if(left <= size)
    {
        minIndex = findIndexOfMin(arr, size, left);
        min = arr[minIndex];
    }
    if(right <= size)
    {
    	temp = findIndexOfMin(arr, size, right);
    	if(arr[temp] < min)
    	{
    		minIndex = temp;
    		min = arr[minIndex];
    	}
    }
    return minIndex;
}

/* this function delete the index in the array and after this doing the max heapify */
void heapDelete(int arr[], int *pSize, int index) /* log n */
{
	int size = *pSize;
	arr[index] = arr[size];
	size--;
	*pSize = size;
	maxHeapify(arr, size, index);
	printHeap(arr, size);

}

void prepareHeapDelete(int arr[], int *pSize)
{
	printf("please enter the index to be deleted\n");
	int index;
	scanf("%d", &index);
	heapDelete(arr, pSize, index);
}

/*  -bonus-
    this function sort the array in another array to not destroy the original array,
    and every time move the largest number to the end and do the max heapify by recursion */
void heapSort(int arr[], int size) /* n log n */
{
	int sortedArr[SIZE];
	int i, temp;
	memcpy(sortedArr, arr, (size + 1) * sizeof(int));
	for(i = size; i > 1; i--)
	{
		temp = sortedArr[i];
		sortedArr[i] = sortedArr[1];
		sortedArr[1] = temp;
		maxHeapify(sortedArr, i - 1, 1);
	}	
	for(i = 1; i <= size; i++)
	{
		printf("%d ", sortedArr[i]);
	}
    printf("\n");
}