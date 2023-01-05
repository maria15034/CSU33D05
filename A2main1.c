//t1_test_skeleton.c

#include "t1.h"
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>



int main()
{
    int arraySize = 10;
    int arr[arraySize];
    
    printf("Ascending list of integers: \n");
    fill_ascending(arr, arraySize); //first we fill it with descending integers
    for (int i = 0; i < arraySize; i++)
    {
        printf("%i ", arr[i]);
    }
    printf("\n");
    printf("Descending list of integers: \n");
    fill_descending(arr, arraySize); //first we fill it with descending integers
    for (int i = 0; i < arraySize; i++)
    {
        printf("%i ", arr[i]);
    }
    printf("\n");
    
    /*printf("Enter the value you want this array to be filled with: \n");
    int reoccuringValue;
    scanf("%i", &reoccuringValue);*/
    
    //fill_uniform(arr, arraySize, reoccuringValue);
    printf("List of uniform integers: \n");
    fill_uniform(arr, arraySize);
    for (int i = 0; i < arraySize; i++)
    {
        printf("%i ", arr[i]);
    }
    printf("\n");
    
    printf("List of randomly shuffled integers without duplicates: \n");
    fill_without_duplicates(arr, arraySize);
    for (int i = 0; i < arraySize; i++)
    {
        printf("%i ", arr[i]);
    }
    printf("\n");
    
    //printf("List 2 of randomly shuffled integers without duplicates: \n");
    fill_without_duplicates(arr, arraySize);
    for (int i = 0; i < arraySize; i++)
    {
        //printf("%i ", arr[i]);
    }
    //printf("\n");

    printf("List of randomly shuffled integers with duplicates: \n");
    fill_with_duplicates(arr, arraySize);
    for (int i = 0; i < arraySize; i++)
    {
        printf("%i ", arr[i]);
    }
    printf("\n");
    
    // 1. random shuffle non duplicates; first fill array,
    //2. randomly swap the elements in the array. using the 'rand' function which will
    //generate a random number.
    //
    
}
