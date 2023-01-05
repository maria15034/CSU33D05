//t2_skeleton.c

#include <stdio.h>
#include "t2.h"

int number_comparisons = 0;
int number_swaps = 0;

//remember to change some variable names bc from video
void selectionSort(int arr[], int size)
{
    
    for(int i = 0 ; i< size-1; i++){//looking at every element; maybe we don't needa look
        //at the last one tho? size-1?
        
        int min_pos = i; //letting first element be the minimum
        for(int j = i+1; j<size; j++){
            if (arr[j] < arr[min_pos])
                min_pos = j;
        }
        if(min_pos!= i){
                int temp = arr[i];
                arr[i] = arr[min_pos];
                arr[min_pos] = temp; //temp variable to store
        }
        //inner loop that finds the minimum in the unsorted portion of the array
        
    }
}

void insertionSort(int arr[], int size)
{
    for(int i =1; i <size; i++){ //looking thru each element of my array
        int element = arr[i];
        int j = i-1; //element on the left of i
        
        //shifting part
        while(j>= 0 && arr[j] > element){
            arr[j+1] = arr[j];
            j = j-1; //goes leftwards
        }
        
        arr[j+1] = element; //insertion part
    }
    
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void quickSort(int arr[], int size) //more of a wrapper function
{
 
    //initally we want to sort the entire array so our bounds are first index to last index
    //AKA 0 to size-1
    quickSort_Recursion(arr, 0, size-1);
    
}

void quickSort_Recursion(int arr[], int l, int h){ //where L and H are low and high
//L = lower bound of the portion of the array we wanna sort
//and H = the higher bound of the portion of the array we wanna sort
    
//here is where we apply the DIVIDE-CONQUER process
    if(l<h){
    int pivot_i = partition(arr, l, h);
    quickSort_Recursion(arr, l, pivot_i-1); //left portion of the array
    quickSort_Recursion(arr, pivot_i+1, h);
}
}

int partition(int arr[], int l, int h){
    //step 1 is to get pivot; in this case we'll just set it to our HIGH bound
    int pivot_val = arr[h];
    
    int i = l;
    
    for(int j = l; j<h ; j++){
        if(arr[j] <= pivot_val){
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[h]); //after all this is done
    
    return i;
}

