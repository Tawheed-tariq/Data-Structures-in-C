#include<stdio.h>
// void swap(int *a, int *b){
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }
// //recursive approach
// void bubbleSort(int *arr, int n){
//     if(n == 0 || n == 1)
//         return;
//     int swapped = 0;
//     for(int i = 0; i < n; i++){
//         if(*(arr+i) > *(arr+i+1)){
//             swap(arr + i, arr + i +1);
//             swapped++;
//         }
//     }
//     if(swapped != 0)
//         bubbleSort(arr, n-1);
// }
int second_largest(int *arr,int n){
    int secondLargest = *(arr+ (n-1));
    for(int i = n-2; i>=0;i++){
        if(*(arr+i) < secondLargest){
            secondLargest = *(arr+i);
            return secondLargest;
        }
    }
    return -1;
}

int main(){
    int n = 6,  arr[6] = {4,2,1,6,2,7};
    // bubbleSort(arr, n);
    printf("Second largest = %d", second_largest(arr,n));
}



// #include <bits/stdc++.h>
// using namespace std;
// int findSecondLargest(int n, vector<int> &arr)
// {
//     int max = INT_MIN;
//     for(int i =0; i < n; i++){
//         if(arr[i] > max)
//             max = arr[i];
//     }
//     for(int i = 0; i < n; i++){
//         if(arr[i] == max)
//             arr[i] = INT_MIN;
//     }
//     max = INT_MIN;
//     for(int i =0; i <n; i++){
//         if(arr[i] > max)
//             max = arr[i];
//     }
//     if(max != INT_MIN)
//         return max;
//     return -1;
// }