#include<stdio.h>
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
//recursive approach
void bubbleSort(int *arr, int n){
    if(n == 0 || n == 1)
        return;
    int swapped = 0;
    for(int i = 0; i < n; i++){
        if(*(arr+i) > *(arr+i+1)){
            swap(arr + i, arr + i +1);
            swapped++;
        }
    }
    if(swapped != 0)
        bubbleSort(arr, n-1);
}
