#include<stdio.h>
#include<stdlib.h>

int linearSearch(int *arr , int n, int key){
    for (int i = 0; i < n; i++)
    {
        if(arr[i] == key){
            return i;
        }
    }
    return -1;
}

int main() {
    int n = 8,  arr[8] = {1,2,4,3,2,6,8,9}, key = 8;
    printf("%d\n", linearSearch(arr,n, key));
}