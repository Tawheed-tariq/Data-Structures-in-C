#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int arr[], int s, int e){
    int pivot = arr[s], count= 0;
    for(int i = s+1; i <= e; i++){
        if(arr[i] <= pivot)
            count++;
    }
    //taking pivot to its right position
    int pivotIndex = count +s;
    swap(&arr[pivotIndex], &arr[s]);

    //making left side of pivot <= pivot and right side of pivot >= pivot
    int i = s, j = e;
    while(i < pivotIndex && j > pivotIndex){
        while(arr[i] < pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }
        if(i<pivotIndex && j > pivotIndex){
            swap(&arr[i++], &arr[j--]);
        }
    }
    return pivotIndex;
}


void Qsort(int arr[], int lb, int ub)
{
    if(lb >= ub)
        return;
    int result = partition(arr, lb, ub);
    Qsort(arr, lb, result - 1);
    Qsort(arr, result + 1, ub);
}

int main()
{
    int arr[] = {3, 4, 2, 10, 24, 15, 12, 6};
    Qsort(arr, 0, 7);
    printf("list all the array element in sorted order:");
    for (int i = 0; i < 8; i++)
    {
        printf("%d\t", arr[i]);
    }
}
