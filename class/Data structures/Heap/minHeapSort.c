#include<stdio.h>
#include<stdlib.h>
//this algo sorts min heap into decreasing order

void swap(int *a, int *b){
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}


void heapifyMin(int arr[], int size , int i){
    int smallest = i, left = 2*i +1 , right = 2*i+2 ;
    if(left < size && arr[left] < arr[smallest]){
        smallest = left;
    }
    if(right < size && arr[right] < arr[smallest]){
        smallest = right;
    }
    if(smallest != i){
        swap(arr+smallest, arr+i);
        heapifyMin(arr, size, smallest);
    }
}


void heapSort(int arr[], int n){
    int size = n-1;
    while(size > 0){
        swap(arr, arr+size);
        size--;
        heapifyMin(arr, size , 0);
    }
}

int main(){
    int n = 7 , arr[7] = {12, 13,42,15, 124, 121, 54};
    heapSort(arr,n);
    for(int i = 0; i< n; i++){
        printf("%d\t", arr[i]);
    }
}