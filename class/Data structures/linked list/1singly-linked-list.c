//In singly linked list each node is contains a refrence node to next node in the sequence
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};


//insertion at beginninng
void insert_beg(struct node **head, int info){
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    new -> data = info;
    new -> next = (*head);
    (*head) = new;
}


//insertion at end
void insert_end(struct node **head, int info){
    struct node *new, *ptr;
    new = (struct node *)malloc(sizeof(struct node));
    new -> data = info;
    new -> next = NULL;
    ptr = (*head);
    if(ptr != NULL){
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = new;
    }
    else{
        (*head) = new;
    }
}


//insertion after a data value
void insert_any(struct node **head, int data, int info){
    struct node *new, *ptr;
    new = (struct node *)malloc(sizeof(struct node));
    new->data = info;
    ptr = (*head);
    if(ptr != NULL){
        while(ptr->data != data){
        ptr = ptr->next;
        }
        new->next = ptr->next;
        ptr->next = new;
    }
    else{
        (*head) = new;
        new->next = NULL;
    }
    
}


//delete at beginning
struct node *deleteAtBeg(struct node *head){
    if(head == NULL){
        printf("linked list is empty");
        return head;
    }
    struct node *ptr = head;
    head  =head ->next;
    free(ptr);
    return head;
}

//delete at end
struct node *deleteAtEnd(struct node *head){
    if(head == NULL){
        printf("linked list is empty");
        return head;
    }
    struct node *ptr = head, *prev = NULL;
    while(ptr->next != NULL){
        prev = ptr;
        ptr = ptr-> next;
    }
    prev ->next = ptr->next;
    free(ptr);
    return head;
}

//delete after a node
void deleteAtAny(struct node **head, int data){
    if(*head == NULL){
        printf("linked list is empty");
        return;
    }
    struct node *ptr = *head, *after = NULL;
    while(ptr->data != data){
        ptr = ptr->next;
    }
    after = ptr->next;
    ptr->next = after->next;
    free(after); //here free function has some problem, somtimes it runs and sometimes not
    after = NULL;
}

void traverse(struct node *head){
    if(head == NULL){
        printf("Empty list");
    }
    else{
        while(head != NULL){
            printf("%d\t", head->data);
            head = head->next;
        }
    }
    printf("\n");
}

int main(){
    struct node e = {10,NULL};
    struct node c = {20, &e};
    struct node *head = &c;
    insert_beg(&head,10);
    insert_beg(&head, 20);
    traverse(head);
}