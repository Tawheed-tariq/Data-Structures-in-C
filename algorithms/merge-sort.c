#include<stdio.h>
#include<stdlib.h>
void merge(int *, int ,int );
void mergeSort(int arr[], int s, int e){
    if(s>= e){
        return;
    }
    int mid = s + (e-s)/2;
    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1, e);
    merge(arr,s,e);
}
void merge(int arr[], int s, int e){
    int mid = s +(e-s)/2;
    int l1 = mid -s + 1, l2 = e-mid;
    int arr1[l1], arr2[l2];
    int mainArray_index = s;
    for(int i = 0; i < l1; i++){
        arr1[i] = arr[mainArray_index++];
    }
    for(int i =0; i < l2; i++){
        arr2[i] = arr[mainArray_index++];
    }
    //merge two sorted arrays
    int index1 = 0, index2 = 0;
    mainArray_index = s;
    while(index1 < l1 && index2 < l2){
        if(arr1[index1] < arr2[index2]){
            arr[mainArray_index++] = arr1[index1++];
        }else{
            arr[mainArray_index++] = arr2[index2++];
        }
    }
    while(index1 < l1){
        arr[mainArray_index++] = arr1[index1++];
    }
    while(index2 < l2){
        arr[mainArray_index++] = arr2[index2++];
    }
}
int main(){
    int arr[9] = {3,5,1,2,6,9,7,4,8};
    mergeSort(arr,0,8);
    for(int i = 0; i < 9; i++){
        printf("%d\t", arr[i]);
    }
}
