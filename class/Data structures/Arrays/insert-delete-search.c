// Insert, delete, search elements in array at specific position
#include<stdio.h>
int enter_elements();
int insert(int , int , int *, int );
int delete(int , int *, int);
int search(int , int *, int);
int main(){
    int data, pos, n = 10, arr[n];
    int srch = -1;
    char command;
    for(int i = 0 ; i<n ; i++){
        arr[i] = i;
    }
    for(;;){
            printf("\npress 'I' to insert element\npress 'D' to delete element\npress 'S' to search element\nfor exit press 'E'\n");
            scanf(" %c", &command);
        if(command == 'I'){
            printf("\nEnter data to be entered: ");
            scanf("%d", &data);
            printf("\nEnter the postion where data is entered: ");
            scanf("%d", &pos);
            insert(data,pos,arr,n); //insertion
            printf("The elements after insertion are: \n");
            for(int i = 0; i < n; i++){
            printf("%d\t", *(arr+i));
            }
        }
        else if(command == 'D'){
            printf("\nEnter the postion where data is deleted: ");
            scanf("%d", &pos);
            delete(pos,arr,n); //deletion
            printf("The elements after deletion are: \n");
            for(int i = 0; i < n; i++){
            printf("%d\t", *(arr+i));
            }
        }
        else if(command == 'S'){
            printf("\nEnter data to search: ");
            scanf("%d", &data);
            srch = search(data, arr, n);
            if(srch == -1)
            printf("Not found!!!!");
            else
            printf("Element present at index %d\n\n\n", srch);
        }
        else if(command == 'E'){
        break;}
        else{
        printf("\nEnter a valid command!!!!!!!");}
    }
}

int insert(int data , int pos, int *ptr, int n){
    if(pos == n)
        printf("Array overflow");
    else {
        for(int i=n-1; i>= pos -1; i--){
            *(ptr + (i)) = *(ptr + (i-1));
        }
        *(ptr + (pos - 1)) = data;
    }
}

int delete(int pos, int *ptr, int n){
    for(int i = pos-1; i < n; i++){
        *(ptr + i) = *(ptr +(i+1));
    }
}

int search(int data, int *ptr, int n){
    for(int i = 0 ; i < n; i++){
        if(data == *(ptr+i))
        return i;
    }
}