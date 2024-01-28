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
//insertion at any position
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
}

//deletion of a node
void deleteNode(struct node **head, int pos){
    if(pos == 1){
        struct node *temp = (*head);
        (*head) = (*head) -> next;
        free(temp);
    }
    else{
        struct node *curr, *prev;
        curr = (*head);
        int cnt = 1;
        while(cnt < pos){
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next  = curr -> next;
        free(curr);
    }
}

int main(){
    struct node e = {10,NULL};
    struct node d = {20, &e};
    struct node c = {30, &d};
    struct node *head = &c;
    insert_beg(&head,4);
    insert_end(&head,8);
    insert_any(&head,20,40);
    traverse(head);
    deleteNode(&head, 3);
    printf("\n");
    traverse(head);
}