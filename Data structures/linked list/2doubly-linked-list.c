#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
}node;

//printing all elements 
void traverse(node *head){
    if(head == NULL){
        printf("linked list is empty");
        return;
    }
    node *ptr = head;
    while(ptr != NULL){
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

//insert at beginning
node *insertAtBeg(node *head, int info){
    node *new = (node *)malloc(sizeof(node));
    new->data = info;
    if(head == NULL){
        new->next = NULL;
        new->prev = NULL;
        head = new;
        return head;
    }
    new->prev = head->prev;
    new->next = head;
    head->prev = new;
    head = new;
    return head;
}
//insert at end
node *insertAtEnd(node *head, int info){
    node *new = (node *)malloc(sizeof(node));
    new->data = info;
    if(head == NULL){
        new->next = NULL;
        new->prev = NULL;
        head = new;
        return head;
    }
    node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    new ->prev = ptr;
    new ->next = ptr->next;
    ptr->next = new;
    return head;
}

//insert after a node (assuming given data is present in linked list)
node *insertAtAny(node *head, int data, int info){
    node *new = (node *)malloc(sizeof(node));
    new->data = info;
    if(head == NULL){
        printf("element not present in list, list is empty!!!\n");
        return head;
    }
    node *ptr = head;
    while (ptr->data != data)
    {
        ptr = ptr->next;
    }
    new ->prev = ptr;
    new ->next = ptr->next;
    if(ptr->next != NULL)
        ptr->next->prev = new;
    ptr->next = new;
    return head;
}

//delete at beginning
node *deleteAtBeg(node *head){
    if(head == NULL){
        printf("linked list is empty\n");
        return head;
    }
    node *temp = head;
    head = head->next;
    if(head != NULL)
        head->prev = NULL
    free(temp);
    return head;
}

//delete at end
node *deleteAtEnd(node *head){
    if(head == NULL){
        printf("linked list is empty\n");
        return head;
    }
    node *ptr = head, *prev = NULL;
    while (ptr->next != NULL)
    {
        prev = ptr;
        ptr= ptr->next;
    }
    prev->next = ptr->next;
    free(ptr);
    return head;
    
}

//delete after a node 
node *deleteAfter(node *head,int data){
    if(head == NULL){
        printf("Data not present , linked list empty\n");
        return head;
    }
    node *ptr = head , *after = NULL;
    while(ptr->data != data){
        ptr = ptr->next;
    }
    after = ptr->next;
    if(after != NULL)
        ptr->next = after->next;
    if(after->next != NULL){//after can be last node also so we have to be carefull
        after->next ->prev = ptr;
    }
    free(after);
    return head;
}

int main(){
    node *head  = NULL;
    head = insertAtBeg(head , 20);
    head = insertAtEnd(head, 30);
    head = insertAtAny(head, 20, 25);
    head = insertAtBeg(head, 10);
    traverse(head);
    head = deleteAtEnd(head);
    traverse(head);
    head  = deleteAfter(head,10);
    head = insertAtAny(head, 10, 15);
    traverse(head);
}