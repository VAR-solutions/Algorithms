#include<stdio.h>
#include<stdlib.h>

struct btree{
    int data;
    struct btree *left;
    struct btree *right;
};

struct btree *minValueNode(struct btree* node){ 
    struct btree* current = node; 
  
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL) 
        current = current->left; 
  
    return current; 
} 

void insert(struct btree **root, int newData){
    struct btree *node = (*root);
    if(node  == NULL){
        struct btree *newNode  = (struct btree *)malloc(sizeof(struct btree));
        newNode->left = NULL;
        newNode->data = newData;
        newNode->right = NULL;
        *root = newNode;
    }
    else{
        if(newData > node->data)
            insert(&(node->right), newData);
        else
            insert(&(node->left), newData);
    }
}

struct btree *delete(struct btree *root, int item){
    if(root == NULL)
        return root;

    if(item > root->data)
        root->right = delete(root->right, item);

    else if(item < root->data)
        root->left = delete(root->left, item);
    
    else{
        if(root->left == NULL){
            struct btree *temp = root->right;
            free(root);
            return temp;
        }
        if(root->right == NULL){
            struct btree *temp = root->left;
            free(root);
            return temp;
        }
        struct btree *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    return root;
}

void inorder(struct btree *root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
    else{
        return;
    }
}

void preorder(struct btree *root){
    if(root != NULL){
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
    else{
        return;
    }
}

void postorder(struct btree *root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
    else{
        return;
    }
}

int main(){
    struct btree *root = NULL;
    insert(&root, 20);
    insert(&root, 40);
    insert(&root, 17);
    insert(&root, 6);
    insert(&root, 8);
    insert(&root, 10);
    insert(&root, 7);
    inorder(root);
    printf("\n");
    delete(root, 20);
    inorder(root);
    printf("\n");
    postorder(root);
    return 0;
}