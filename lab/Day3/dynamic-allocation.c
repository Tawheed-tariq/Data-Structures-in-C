#include<stdio.h>
#include<stdlib.h>
int main(){
    int *ptr, n = 5, choice, new_n;
    ptr = (int *) malloc(n*sizeof(int));
    printf("Enter elements : ");
    for(int i = 0; i < n; i++){
        scanf("%d", ptr+i);
        printf("%d \t", *(ptr+i));
    }
    printf("\n");
    printf("Enter 0 to increase size and 1 to exit program: ");
    scanf("%d", &choice);
    if(choice == 0){
        printf("Enter new size: ");
        scanf("%d", &new_n);
        ptr = (int *)realloc(ptr, new_n*sizeof(int));
        printf("enter more elements : ");
        for(int i = 0; i < new_n; i++){
            scanf(" %d", ptr+i);
        }
        printf("\n");
        for(int i = 0; i < new_n; i++){
            printf("%d\t", *(ptr+i));
        }
        printf("\n");
    }
    else
        exit(0);
}