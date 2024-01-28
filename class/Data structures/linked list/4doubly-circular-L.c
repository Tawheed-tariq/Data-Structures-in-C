#include<stdio.h>
#include<stdlib.h>
struct node {
    struct node *prev;
    int data;
    struct node *next;
};
//insert at beginning
struct node *insertAtHead(struct node *head, int data){
    struct node *new;
    new =  (struct node *)malloc(sizeof(struct node));
    new->data = data;
    if(head == NULL){
        head = new;
        new->next = head;
        new->prev = head;
        return head;
    }
    new->prev = head->prev;
    new->next = head;
    head->prev->next = new;
    head->prev = new;
    head = new;
    return head;
}

//insert at end
void insertAtEnd(struct node **head, int info){
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    new->data = info;
    if((*head ) == NULL){
        new->next = new;
        new->prev = new;
        (*head) = new;
    }else{
        struct node *ptr = (*head);
        while(ptr->next != (*head)){
            ptr = ptr->next;
        }
        new->prev = ptr;
        new->next = ptr->next;
        ptr->next = new;
        (*head)->prev = ptr;
    }
}

//insert after a node (assuming x is present in list)
struct node *insertAfter(struct node *head,int data, int x){
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    new -> data = data;
    if(head == NULL){
        head = new;
        new->prev = new;
        new->next = new;
        return head;
    }
    struct node *ptr = head;
    while(ptr->data != x){
        ptr = ptr->next;
    }
    new->prev = ptr;
    new->next = ptr->next;
    ptr->next->prev = new;
    ptr->next = new;
    return head;
}

//delete at beginning 
struct node *deleteAtBeg(struct node *head){
    if(head == NULL){
        printf("inked list is empty");
        return head;
    }
    if(head->next == head){
        struct node *temp = head;
        head = NULL;
        free(temp);
        return head;
    }
    struct node *temp = head;
    head ->prev->next = head->next;
    head->next -> prev = head->prev;
    head = head ->next;
    free(temp);
    return head;
}

//delete at end
void deleteAtEnd(struct node **head){
    if((*head ) == NULL){
        printf("list is empty");
        return;
    }
    if((*head) ->next == (*head)){
        struct node *ptr = (*head);
        (*head) = NULL;
        free(ptr);
        return;
    }
    struct node *ptr = (*head), *prev = NULL;
    while(ptr->next != (*head)){
        prev = ptr;
        ptr = ptr->next;
    }
    prev->next = ptr->next;
    (*head)->prev = prev;
    free(ptr);
}


//delete after given node (assuming node is preset in list)
struct node *deleteAfter(struct node *head, int data){
    if(head == NULL){
        printf("list is empty");
        return head;
    }
    struct node *ptr = head, *after = NULL;
    while(ptr->data != data){
        ptr = ptr->next;
    }
    after = ptr->next;
    ptr->next = after->next;
    after->next->prev = ptr;
    free(after);
    return head;
}



//printing all elements
void traverse(struct node *head){
    if(head  == NULL){
        return;
    }
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
    //data for nodes
    a -> data = 10;
    b -> data = 20;
    c-> data = 30;
    // previous pointers for nodes
    a->prev = c;
    b->prev = a;
    c->prev = b;
    //next pointers for nodes
    a->next = b;
    b->next = c;
    c->next = a;
    struct node *head = a;
    traverse(head);
    insertAtEnd(&head, 5);
    deleteAtEnd(&head);
    head = insertAtHead(head, 25);
    head = insertAfter(head, 34, 10);
    traverse(head);
    head  =deleteAfter(head, 34);
    traverse(head);
}