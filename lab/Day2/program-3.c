//to implement all the dynamic memory alocations
//malloc, calloc, realloc, free

#include<stdio.h>
#include<stdlib.h>
int main(){
    int *ptr, *ptr1;
    ptr = (int *)malloc(3*sizeof(int));
    printf("Enter elements of array: ");
    for(int i =0; i< 3; i++){
        scanf("%d", ptr+i);
    }
    for(int i =0; i< 3; i++){
        printf("%d\t", *(ptr+i));
    }
     printf("\n");

    ptr1 = (int *)calloc(3,sizeof(int));
    printf("Enter elements of array: ");
    for(int i =0; i< 3; i++){
        scanf("%d", ptr+i);
    }
    for(int i =0; i< 3; i++){
        printf("%d\t", *(ptr+i));
    }
    printf("\n");
    ptr = (int *)realloc(ptr,6*sizeof(int));
    printf("Enter elements of reallocated array: ");
    for(int i =0; i< 6; i++){
        scanf("%d", ptr+i);
    }
    for(int i =0; i< 6; i++){
        printf("%d\t", *(ptr+i));
    }
    free(ptr);
    free(ptr1);

}