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
    for(int i = 0; i < n-1; i++){
        if(*(arr+i) > *(arr+i+1)){
            swap(arr + i, arr + i +1);
            swapped++;
        }
    }
    if(swapped != 0)
        bubbleSort(arr, n-1);
}


//iterative approach
void sort(int *arr, int n){
    for(int i = 0; i < n -1; i++){
        int swapped = 0;
        for(int j = i+1; j< n-1-i; j++){
            if(arr[j] > arr[j+1]){
                swap(arr+j, arr+j+1);
                swapped = 1;
            }
        }
        if(swapped == 0)
            break;
    }
}

int main(){
    int n = 5 , arr[5] = {1, 5,2,6,3};
    bubbleSort(arr,n);
    for(int i = 0; i< n; i++){
        printf("%d\t", arr[i]);
    }
}