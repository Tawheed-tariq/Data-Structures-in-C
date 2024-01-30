#include<stdio.h>
#include<stdlib.h>


//1 based indexing
int arr[10000];
int size = 0;
int heapSize = sizeof(arr)/sizeof(arr[0]);

void swap(int *a, int *b){
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}


void insertNode(int data){
    if(size >= heapSize){
        printf("Heap overflow");
        return;
    }
    arr[++size] = data;
    int index = size;
    while(index > 1){
        int parent = index/2;
        if(arr[parent] > arr[index]){
            swap(arr+parent , arr+index);
            index = parent;
        }else{
            return;
        }
    }
}


void deleteNode(){
    if(size == 0){
        printf("heap underflow");
        return;
    }
    arr[1] = arr[size--]; //replace first node with last node and delete last node;

    //heapify first node
    int i = 1;
    while(i <= size){
        int left = 2*i, right = 2*i + 1;
        if(left <= size && arr[left] < arr[i]){
            swap(arr+ left, arr+i);
            i = left;
        }
        else if(right <= size && arr[right] < arr[i]){
            swap(arr+right, arr+i);
            i = right;
        }
        else{
            return;
        }
    }
}

void heapify(int i){
    int smallest = i, left = 2*i , right = 2*i +1;
    if(left <= size && arr[left] < arr[smallest]){
        smallest = left;
    }
    if(right <= size && arr[right] < arr[smallest]){
        smallest = right;
    }
    if(smallest != i){
        swap(arr+smallest, arr+i);
        heapify(smallest);
    }
}

int main(){
    insertNode(12);
    insertNode(13);
    insertNode(121);
    insertNode(15);
    insertNode(124);
    insertNode(42);
    insertNode(54);
    for(int i = 1 ; i <= size; i++){
        printf("%d\t", arr[i]);
    }

    printf("\n");

    deleteNode();
    for(int i = 1 ; i <= size; i++){
        printf("%d\t", arr[i]);
    }

}