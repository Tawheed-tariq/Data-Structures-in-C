#include<stdio.h>
void sort(int *, int);
void swap(int *, int *);


int  main(){
    int n = 5 , arr[5] = {1, 44,2,6,3};
    sort(arr, n);
    for(int i = 0; i< n; i++){
        printf("%d\t", arr[i]);
    }

}



void sort(int arr[], int n){
    for(int i = 0; i< n; i++){
        int min = i;
        for(int j= i +1; j<n ; j++){
            if(arr[min] > arr[j])
                min = j; 
        }
        if(min != i)
            swap((arr+i), (arr+min));
    }
}



void swap(int *a, int *b){
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}