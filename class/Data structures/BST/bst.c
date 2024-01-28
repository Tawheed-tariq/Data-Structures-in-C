#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node *left, *right;
};

struct Node* newNode(int item) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void inOrder(struct Node *root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    printf("%d\t", root->key);
    inOrder(root->right);
}

struct Node* insert(struct Node* node, int key) {
    if (node == NULL)
        return newNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    return node;
}

struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current != NULL && current->left != NULL)
        current = current->left;
    return current;
}

struct Node* deleteNode(struct Node* root, int key) {
    if(root == NULL){
        return NULL;
    }
    if(root->key == key){
        //0 child
        if(root->left == NULL &&  root->right == NULL){
            free(root);
            return NULL;
        }
        //1 child
        if(root->left != NULL && root->right == NULL){
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        if(root->right != NULL && root->left == NULL){
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        // 2 childs
        struct Node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }else if(root->key > key){
        root->left = deleteNode(root->left , key);
    }else{
        root->right = deleteNode(root->right, key);
    }
    return root;
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Binary Search Tree before deletion: ");
    inOrder(root);
    
    int key_to_delete = 50;
    root = deleteNode(root, key_to_delete);
    
    printf("\nBinary Search Tree after deleting node with key %d: ", key_to_delete);
    inOrder(root);

    return 0;
}
