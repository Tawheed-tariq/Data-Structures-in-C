#include<stdio.h>
int search(int *, int ,int);
int main(){
    int n = 6,  arr[6] = {1,2,4,6,8,9}, key = 8;
    printf("%d\n", search(arr,n, key));
}

//iterative approach
int search(int *arr, int n , int key){
    int start = 0;
    int end = n-1;
    int mid = start + (end - start)/2;
    while(start <= end){
        if(arr[mid] == key)
            return mid;
        else if(key > arr[mid])
            start = mid +1;
        else if(key < arr[mid])
            end = mid -1;
        mid = start + (end - start)/2;
    }
    return -1;
}
