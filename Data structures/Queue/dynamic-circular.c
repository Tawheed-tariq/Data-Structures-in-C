#include<stdio.h>
#include<stdlib.h>

struct queue
{
    struct queue *prev;
    int data;
    struct queue *next;
};

struct queue *front = NULL;
struct queue *rear = NULL;


void enqueue(int val){
    struct queue *new;
    new = (struct queue *)malloc(sizeof(struct queue));
    new-> data = val;

    if(front == NULL){
        new->next = new;
        new->prev = new;
        front = new;
        rear = new;
    }else{
        new->next = rear->next;
        new->prev = rear;
        rear->next = new;
        front->prev = new;
        rear = new;
    }
}

void dequeue(){
    if(front == NULL){
        printf("queue is empty");
        return;
    }
    if(front == rear){
        struct queue *temp = front;
        front = NULL;
        rear = NULL;
        free(temp);
    }else{
        struct queue *temp = front;
        front = front->next;
        rear -> next = front;
        front->prev = rear;
        free(temp);
    }
}

void display(){
    struct queue *ptr = front;
    if(front == NULL){
        printf("queue is empty");
        return;
    }
    do{
        printf("%d\t", ptr->data);
        ptr= ptr->next;
    }while(ptr != front);
    printf("\n");
}

int main(){
    enqueue(12);
    enqueue(13);
    enqueue(43);
    enqueue(14);
    dequeue();  //12 removes
    display(); //13 43 14
    enqueue(121); 
    display(); //13 43 14 121
}