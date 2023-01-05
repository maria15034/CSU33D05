//  t1_skeleton.c
//NEED TO CREATE AN EXECTUBLE FILE WITH UBUNTU TO USE THIS
//VM?
// for now put main that will be deleted before submitting
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "t1.h"


//Fills the array with ascending, consecutive numbers, starting from 0.
void fill_ascending(int *array, int size){
    for( int i = 0; i < size; i++){
        array[i] = i+1;
    }
}

//Fills the array with descending numbers, starting from size-1
void fill_descending(int *array, int size)
{
    for( int i = 0; i < size; i++){
        array[i] = size-i;
    }
}

//Fills the array with uniform numbers.
//void fill_uniform(int *array, int size, int value)
void fill_uniform(int *array, int size)
{
    
    for( int i = 0; i < size; i++){
        //array[i] = value;
        array[i] = 3;
    }

}

//Fills the array with random numbers within 0 and size-1. Duplicates are allowed.
void fill_with_duplicates(int *array, int size)
{
    
    //first filling the array with values
    for( int i = 0; i < size; i++){
        array[i] = i+1;
    }
    
    //now swapping them
    for( int i = 0; i < size-1; i++){
        //size-1 so there's a reasonable amount of duplicates
    
        int swap_index = rand() % size; //for each element in the array, generating a number between 0 and size-1;
        //int temp = array[i]; //this holds the value at i; not needed for this fn tho
        
        // swapping whatever's at index i with the randomly generated index:
        array[i] = array[swap_index];
        //array[swap_index] = temp;
        //^removing the above line forces there to be at least one duplicate pair, as the elements are no longer being swapped, but instead a random one is being duplicated elsewhere in the array
    }
    
}


//Fills the array with unique numbers between 0 and size-1 in a shuffled order. Duplicates are not allowed.
void fill_without_duplicates(int *array, int size)
{
    srand( time(NULL)); //calling this initializes the random num generator each time
    //the program runs at the current time, meaning there will be no duplicates as the
    //time varies each time the program runs.

    
    //first filling the array with values
    for( int i = 0; i < size; i++){
        array[i] = i+1;
    }
    
    //now swapping them
    for( int i = 0; i < size; i++){
    
        int swap_index = rand() % size; //for each element in the array, generating a number between 0 and size-1;
        int temp = array[i]; //this holds the value at i
        
        // swapping whatever's at index i with the randomly generated index:
        array[i] = array[swap_index];
        array[swap_index] = temp;
    }
    
}

void printArray(int* arr, int size){
  int i;
  for(i=0; i<size;i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
}

