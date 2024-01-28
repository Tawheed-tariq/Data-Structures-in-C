#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};

//insert at head
struct node *insertAtHead(struct node *head, int data){
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new ->data = data;
    if(head == NULL){
        head = new;
        new->next = head;
        return head;
    }
    struct node *ptr = head;
    while (ptr->next != head)
    {
        ptr= ptr->next;
    }
    new->next = ptr->next;
    ptr->next = new;
    head  =new;
    return head;
}

//insert at end
void insertAtEnd(struct node **head,int info){
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = info;
    if((*head) == NULL){
        new->next = new;
        (*head) = new;
    }else{
        struct node *ptr = (*head);
        while(ptr->next != (*head)){
            ptr = ptr->next;
        }
        ptr->next = new;
        new->next = (*head);
    }
}
//insert after a node
struct node *insertAfter(struct node *head, int data, int x){
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->data = data;
    //assuming x is present in list , hence head != NULL
    struct node *ptr = head;
    while(ptr->data != x){
        ptr = ptr->next;
    }
    new->next = ptr->next;
    ptr->next = new;
    return head;
}

//delete at beginning
struct node *deleteAtHead(struct node *head){
    if(head == NULL){
        printf("Linked list is empty");
        return head;
    }
    if(head->next == head){
        struct node *temp = head;
        head = NULL;
        free(temp);
        return head;
    }
    struct node *temp  = head, *ptr = head;
    while(ptr->next != head){
        ptr = ptr->next;
    }
    ptr->next = head->next;
    head = head->next;
    free(temp);
    return head;
}

//delete at end 
struct node *deleteAtEnd(struct node *head){
    if(head == NULL){
        printf("linked list is empty");
        return head;
    }
    if(head->next == head){
        struct node *temp = head;
        head = NULL;
        free(temp);
        return head;
    }
    struct node *ptr = head, *prev = NULL;
    while(ptr ->next != head){
        prev = ptr;
        ptr= ptr->next;
    }
    prev->next = head;
    free(ptr);
    return head;
}

//delete after a node (assuming element after data is present in list)
struct node *deleteAfter(struct node *head, int data){
    if(head == NULL){
        printf("linked list is empty");
        return head;
    }
    struct node *ptr = head, *after = NULL;
    while(ptr->data != data){
        ptr = ptr->next;
    }
    after = ptr->next;
    ptr->next = after->next;
    free(after);
    return head;
}

// printing all elements
void traverse(struct node *head){
    struct node *ptr = head;
    do{
        printf("%d\t", ptr->data);
        ptr= ptr->next;
    }while(ptr != head);
    printf("\n\n");
}

int main(){
    struct node *a, *b, *c;
    a = (struct node *)malloc(sizeof(struct node));
    b = (struct node *)malloc(sizeof(struct node));
    c = (struct node *)malloc(sizeof(struct node));
    a -> data = 10;
    b -> data = 20;
    c-> data = 30;
    a->next = b;
    b->next = c;
    c->next = a;
    struct node *head = a;
    traverse(head);
    insertAtEnd(&head, 5);
    head = insertAtHead(head, 15);
    insertAtEnd(&head , 12);
    traverse(head);
    head = insertAfter(head ,  45, 15);
    head = deleteAtEnd(head);
    traverse(head);
    head = deleteAfter(head,20);
    traverse(head);
}