//t2 test skeleton

#include "t1.h"
#include "t2.h"
#include <stdio.h>



int main()
{
    int arraySize = 100;
    int arr[arraySize];
    
    printf("List of random integers: \n");
    fill_without_duplicates(arr, arraySize);
    for (int i = 0; i < arraySize; i++)
    {
        printf("%i ", arr[i]);
    }
    printf("\n");
    
    //now to sort using insertion sort

    insertionSort(arr, arraySize);
    for (int i = 0; i < arraySize; i++)
    {
        printf("%i ", arr[i]);
    }
    printf("\n");
    
    
    int arr2[arraySize];
    printf("List of random integers: \n");
    fill_without_duplicates(arr2, arraySize);
    for (int i = 0; i < arraySize; i++)
    {
        printf("%i ", arr2[i]);
    }
    printf("\n");
    
    selectionSort(arr2, arraySize);
    for (int i = 0; i < arraySize; i++)
    {
        printf("%i ", arr2[i]);
    }
    printf("\n");
    
    int arr3[arraySize];
    printf("List of random integers: \n");
    fill_without_duplicates(arr3, arraySize);
    for (int i = 0; i < arraySize; i++)
    {
        printf("%i ", arr3[i]);
    }
    printf("\n");
    
    quickSort(arr3, arraySize);
    for (int i = 0; i < arraySize; i++)
    {
        printf("%i ", arr3[i]);
    }
    printf("\n");
}
