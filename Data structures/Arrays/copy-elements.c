// with the help of pointer copy elements from one array to other
#include<stdio.h>
int main(){
    int arr1[10], arr2[10],i;
    int *ptr;
    printf("Enter elements of array 1: ");
    for(i = 0; i<10; i++){
        scanf("%d", (arr1+i));
    }
    ptr = arr1;
    for(i = 0 ; i<10; i++){
        arr2[i] = *(ptr+i);
        printf("%d\t", *(arr2+i));
    }
    return 0;
}
