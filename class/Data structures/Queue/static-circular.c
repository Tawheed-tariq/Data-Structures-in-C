#include<stdio.h>
#include<stdlib.h>

#define size 10
int front = -1;
int rear = -1;
int queue[size];

void enqueue(int val){
    if((rear+1)%size == front){
        printf("Queue overflow");
        return;
    }else if(front == -1){
        front = 0;
        rear = 0;
        queue[rear] = val;
    }else{
        rear = (rear+1)%size;
        queue[rear] = val;
    }
}

void dequeue(){
    if(front == -1){
        printf("queue is empty");
        return;
    }else if(rear == front){
        rear = -1;
        front = -1;
    }else{
        front = (front + 1)%size;
    }
}

void display(){
    if(front == -1){
        printf("queue is empty");
        return;
    }

    int i = front;
    while(i != rear){
        printf("%d\t", queue[i]);
        i = (i+1)%size;
    }
    printf("%d", queue[i]);
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