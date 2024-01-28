#include<stdio.h>
#include<stdlib.h>
struct stack{
    int data;
    struct stack *next;
    struct stack *prev;
};
//inserting element at top
struct stack *push(struct stack *top, int info){
    struct stack *new;
    new = (struct stack *)malloc(sizeof(struct stack));
    new->data = info;
    if(new == NULL){
        printf("stack overflow");
        return top;
    }
    new->next = NULL;
    new->prev = top;
    if(top != NULL)
        top->next = new;
    top = new;
    return top;
}
//removing element from top
struct stack *pop(struct stack *top){
    if(top == NULL){
        printf("Stack underflow");
        return top;
    }
    struct stack *temp = top;
    top = top->prev;
    if(top != NULL)
        top->next = NULL;
    printf("deleted %d\n", temp->data);
    free(temp);
    return top;
}
//printing all elements
void display(struct stack *top){
    while (top != NULL)
    {
        printf("%d\t", top->data);
        top = top->prev;
    }
    printf("\n");
}

int main(){
    struct stack *top = NULL;
    top = push(top, 9);
    top = push(top , 12);
    top = push(top , 121);
    top = push(top, 43);
    display(top);
    top = pop(top);
    display(top);   
}