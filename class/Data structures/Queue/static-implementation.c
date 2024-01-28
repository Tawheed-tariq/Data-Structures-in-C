#include<stdio.h>
#define LIMIT 5
int front = -1;
int rear = -1;
int queue[LIMIT];

void enqueue(){
    if(rear == LIMIT-1){
        printf("queue overflow\n");
    }else{
        int ele;
        printf("enter >>");
        scanf("%d", &ele);
        rear++;
        queue[rear] = ele;
        if(front == -1){
            front++;
        }
    }
}

void dequeue(){
    if(front == -1 || front > rear){
        printf("queue underflow\n");
    }else{
        printf("deleted %d\n", queue[front]);
        front++;
    }
}

void traverse(){
    for(int i = front; i <= rear; i++){
        printf("%d", queue[i]);
    }
}
int main(){
    enqueue();
    dequeue();
    dequeue();
    traverse();
}