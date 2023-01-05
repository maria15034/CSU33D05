#ifndef T2_H_
#define T2_H_

void selectionSort(int arr[], int size);
void insertionSort(int arr[], int size);
void quickSort(int arr[], int size);
void swap(int *x, int *y);
void quickSort_Recursion(int arr[], int l, int h); //where L and H are low and high
int partition(int arr[], int l, int h);

extern int number_comparisons;
extern int number_swaps;


#endif
