//static array implementation
#include<stdio.h>
#define MAX 10
void push();
void pop();
void display();
int top = -1;
int stack[MAX];

int main(){
    char command;
    for(;;){
        printf("'I' to insert\n'D' to delete\n'E' to display\n>>");
        scanf(" %c", &command);
        if(command == 'I')
            push();
        else if(command == 'D')
            pop();
        else if(command == 'E')
            break;
        else
            printf("Enter a valid command\n\n\n");
    }
    display();
    return 0;
}
//inserting element at top
void push(){
    int element;
    if(top == MAX-1)
        printf("stack overflow");
    else{
        printf("Enter the value to be entered: ");
        scanf("%d", &element);
        stack[++top] = element;
    }
}
//removing element from top
void pop(){
    if(top == -1)
        printf("stack underflow");
    else{
        printf("The deleted element is %d\n\n", stack[top--]);
    }
}
//printing all elements of stack
void display(){
    printf("Elements in stack are: ");
    for(int i = top; i>= 0; i--){
        printf("%d\t", stack[i]);
    }
}