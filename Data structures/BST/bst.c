#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *left, *right;
}Node;

Node* newNode(int item) {
    Node* temp = (Node *)malloc(sizeof(Node));
    temp->key = item;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

//traversals
void inOrder(Node *root){ //LNR
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    printf("%d\t", root->key);
    inOrder(root->right);
}
void preOrder(Node *root){ //NLR
    if(root == NULL){
        return;
    }
    printf("%d\t", root->key);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node *root){ //LRN
    if(root == NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%d\t", root->key);
}

//insertion
Node* insert(Node* root, int key) {
    if (root == NULL)
        return newNode(key);
    if (key < root->key) //go to left subtree
        root->left = insert(root->left, key);
    else if (key > root->key) //go to right subtree
        root->right = insert(root->right, key);
    return root;
}


//inorder successor
Node* minValueNode(Node* root) {  //inorder successor (min of right subtree)
    Node* current = root->right;
    while (current != NULL && current->left != NULL)
        current = current->left;
    return current;
} 

//inorder predecessor
Node *maxValueNode(Node * root){ //inorder predecessor (max of left subtee)
    Node * current = root->left;
    while (current != NULL && current->right != NULL)
    {
        current = current->right;
    }
    return current; 
}

//deletion
Node* deleteNode(Node* root, int key) {
    if(root == NULL){
        return NULL;
    }
    if(root->key == key){
        //0 child
        if(root->left == NULL &&  root->right == NULL){
            free(root);
            return NULL;
        }
        //left child
        if(root->left != NULL && root->right == NULL){
            Node* temp = root->left;
            free(root);
            return temp;
        }
        //right child
        if(root->right != NULL && root->left == NULL){
            Node* temp = root->right;
            free(root);
            return temp;
        }
        // 2 childs
        Node* temp = minValueNode(root); //inorder successor
        root->key = temp->key; //replace data of root with data of inorder successor or predecessor
        root->right = deleteNode(root->right, temp->key); //now delete the node of inorder predecessor or inorder successor
    }
    else if(root->key > key){
        root->left = deleteNode(root->left , key);
    }
    else{
        root->right = deleteNode(root->right, key);
    }
    return root;
}

int main() {
    Node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Binary Search Tree before deletion: ");
    inOrder(root); //prints in sorted order
    
    int key_to_delete = 50;
    root = deleteNode(root, key_to_delete);
    
    printf("\nBinary Search Tree after deleting node with key %d: ", key_to_delete);
    inOrder(root); //prints in sorted order

    return 0;
}
