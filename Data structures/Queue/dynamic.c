#include<stdio.h>
#include<stdlib.h>

struct queue{
    struct queue *prev;
    int data;
    struct queue *next;
};


void enqueue(struct queue **front, struct queue **rear, int data){
    struct queue *n = (struct queue *)malloc(sizeof(struct queue));
    n->data = data;
    if((*front) == NULL){
        (*front) = n;
        (*rear) = n;
        n->next = NULL;
        n->prev = NULL;
        return; 
    }
    (*rear)->next = n;
    n->prev = (*rear);
    n->next = NULL;
    (*rear) = n;
}

struct queue *dequeue(struct queue *front){
    if(front == NULL){
        printf("QUeue is empty");
        return front;
    }
    struct queue *temp = front;
    front = front->next;
    front->prev= NULL;
    printf("Deleted %d\n", temp->data);
    free(temp);
    return front;
}
void traverse(struct queue *front){
    struct queue *temp = front;
    if(front == NULL){
        printf("queue is empty");
        return;
    }
    while(temp != NULL){
        printf("%d\t", temp->data);
        temp =temp->next;
    }
    printf("\n");
}
int main(){
    struct queue *front = NULL, *rear = NULL;
    enqueue(&front, &rear, 10);
    enqueue(&front,&rear,20);
    enqueue(&front, &rear, 30);
    traverse(front);
    front = dequeue(front);
    traverse(front);
}