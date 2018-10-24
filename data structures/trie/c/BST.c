#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *lc, *rc;
};

struct node* least(struct node* root)
{
    struct node* current = root;
    if(current != NULL)
        while(current->lc != NULL)
            current = current->lc;

    return current;
}

struct node* newnode(int data)
{
    struct node* root = (struct node*)malloc(sizeof(struct node));
    root->data = data;
    root->lc = NULL;
    root->rc = NULL;
    return root;
}

struct node* searchTree(struct node* root, int key)
{
    if (key == root->data)
        return root;
    else if(key > root->data)
        return searchTree(root->rc, key);
    else
        return searchTree(root->lc, key);
    return NULL;
}

struct node* insertNode(struct node* root, int key)
{
    if (root == NULL)
        return newnode(key);
    if (key < root->data)
        root->lc = insertNode(root->lc, key);
    else if(key > root->data)
        root->rc = insertNode(root->rc, key); //Impossible case
    return root;
}

struct node* deleteNode(struct node* root, int key)
{
    if(root == NULL)
        return root;
    if (key < root->data)
        root->lc = deleteNode(root->lc, key);
    else if (key > root->data)
        root->rc = deleteNode(root->rc, key);
    else
    {
        if(root->lc == NULL)
        {
            struct node* temp = root->rc;
            free(root);
            return temp;
        }
        else if(root->rc == NULL)
        {
            struct node* temp = root->lc;
            free(root);
            return temp;
        }
        else
        {
            struct node* temp = root->rc;
            temp = least(temp);
            root->data = temp->data;
            root->rc = deleteNode(root->rc, temp->data);
        }
    }
}

void printInorder(struct node* node)
{
  if (node == NULL)
     return;
 
  /* first recur on left child */
  printInorder(node->lc);
 
  /* then print the data of node */
  printf("%d ", node->data);
 
  /* now recur on right child */
  printInorder(node->rc);
}

int main()
{
    struct node* root = newnode(44);
    insertNode(root, 17);
    insertNode(root, 50);
    insertNode(root, 32);
    insertNode(root, 88);
    insertNode(root, 28);
    insertNode(root, 65);
    insertNode(root, 97);
    insertNode(root, 54);
    insertNode(root, 82);
    insertNode(root, 76);
    struct node* val = searchTree(root, 82);
    printf("Node found. value = %d\n", val->data);
    deleteNode(root, 50);
    printf("done first delete\n");
    deleteNode(root, 65);
    printf("done second delete\n");
    deleteNode(root, 76);
    printf("done third delete\n");
    printInorder(root);
    return 0;
}