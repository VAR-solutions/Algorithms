#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data, height;
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

int height(struct node* root)
{
    if (root == NULL)
        return 0;
    return root->height;
}

int max(int a, int b)
{
    if (a>= b)
        return a;
    return b;
}

struct node* newnode(int data)
{
    struct node* root = (struct node*)malloc(sizeof(struct node));
    root->data = data;
    root->lc = NULL;
    root->rc = NULL;
    root->height = 1;
    return root;
}


struct node* rightrightZigZig(struct node* z)
{
    struct node* y = z->rc;
    struct node* ylc = y->lc;

    // pointer changes. make z = rc of y and rc of y = lc of z
    y->lc = z;
    z->rc = ylc;

    // Updating the heights:-

    z->height = max(height(z->lc), height(z->rc)) + 1;
    y->height = max(height(y->lc), height(y->rc)) + 1;
    
    
    return y;
}
struct node* leftleftZigZig(struct node* z)
{
    struct node* y = z->lc;
    struct node* yrc = y->rc;

    // pointer changes. make z = rc of y and rc of y = lc of z
    y->rc = z;
    z->lc = yrc;

    // Updating the heights:-

    z->height = max(height(z->lc), height(z->rc)) + 1;
    y->height = max(height(y->lc), height(y->rc)) + 1;
    
    
    return y;
}

struct node* leftrightZigZag(struct node* z)
{
    // struct node* y = z->lc;
    // struct node* x = y->rc;
    // struct node* xlc = x->lc;
    // struct node* xrc = x->rc;

    // // Pointer Changes. Right rotation on y, and left rotation on z.
    // x->lc = y;
    // y->rc = xlc;
    // x->rc = z;
    // z->lc = xrc;

    // //updating heights

    // x->height = max(height(x->lc), height(x->rc)) + 1;
    // y->height = max(height(y->lc), height(y->rc)) + 1;
    // z->height = max(height(z->lc), height(z->rc)) + 1;

    z->lc = rightrightZigZig(z->lc);
    return leftleftZigZig(z);

}

struct node* rightleftZigZag(struct node* z)
{
    // struct node* y = z->rc;
    // struct node* x = y->lc;
    // struct node* xlc = x->lc;
    // struct node* xrc = x->rc;

    // // Pointer Changes. Right rotation on y, and left rotation on z.
    // x->rc = y;
    // y->lc = xrc;
    // x->lc = z;
    // z->rc = xlc;

    // //updating heights

    // x->height = max(height(x->lc), height(x->rc)) + 1;
    // y->height = max(height(y->lc), height(y->rc)) + 1;
    // z->height = max(height(z->lc), height(z->rc)) + 1;

    z->rc = leftleftZigZig(z->rc);
    return rightrightZigZig(z);

}

// int mod(int a)
// {
//     if (a >= 0)
//         return a;

//     else
//         return -a;
// }
int getBalance(struct node *root)
{
    if (root == NULL)
        return 0;
    return height(root->lc) - height(root->rc);
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
        root->rc = insertNode(root->rc, key);
    else    //Impossible case as equal keys are not allowed
        return root;

    // Steps in algo:-
    // 1) Update the height of the current node
    // 2) get the balance factor.
    // 3) perform rotations if balance factor > 1

    // 1)
    root->height = max(height(root->lc), height(root->rc)) + 1; 

    // 2)
    int balance = getBalance(root);

    // 3
    //left left case
    if(balance > 1 && key <root->lc->data)
        return leftleftZigZig(root);
    if(balance < -1 && key > root->rc->data)
        return rightrightZigZig(root);
    if(balance > 1 && key > root->lc->data)
        return leftrightZigZag(root);
    if (balance < -1 && key < root->rc->data)
        return rightleftZigZag(root);

    return root;
    
}

// The recursive code itself travels up and visits all the ancestors of the deleted node.
// 1) Perform the normal BST deletion.
// 2) The current node must be one of the ancestors of the deleted node. 
//    Update the height of the current node.
// 3) Get the balance factor (left subtree height – right subtree height) of the current node.
// 4) If balance factor is greater than 1, then the current node is unbalanced and we are either in Left Left case or Left Right case. 
//    To check whether it is Left Left case or Left Right case, get the balance factor of left subtree.
//    If balance factor of the left subtree is greater than or equal to 0, then it is Left Left case, else Left Right case.
// 5) If balance factor is less than -1, then the current node is unbalanced and we are either in Right Right case or Right Left case. 
//    To check whether it is Right Right case or Right Left case, get the balance factor of right subtree. 
//    If the balance factor of the right subtree is smaller than or equal to 0, then it is Right Right case, else Right Left case.



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
        // If temp is null, then make root null
        // if temp is non null (one child) copy contents to root, and free temp.
        if(root->lc == NULL)
        {
            struct node* temp = root->rc;
            if(temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;
            free(temp);
        }
        else if(root->rc == NULL)
        {
            struct node* temp = root->lc;
            *root = *temp;
            free(temp);
        }

        // Two child case!!
        else
        {
            struct node* temp = root->rc;
            temp = least(temp);
            root->data = temp->data;
            root->rc = deleteNode(root->rc, temp->data);
        }
        
    }
    //In case the entire tree gets deleted.
    if (root == NULL)
        return root;

    root->height = max(height(root->lc), height(root->rc)) + 1;

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->lc) >= 0)
        root = leftleftZigZig(root);
    if (balance > 1 && getBalance(root->lc)<0)
        root = leftrightZigZag(root);
    if (balance < -1 && getBalance(root->rc) <= 0)
        root = rightrightZigZig(root);
    if (balance < -1 && getBalance(root->rc) >0)
        root = rightleftZigZag(root);
    
    return root;
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

void preorder(struct node* root)
{
    if (root != NULL)
    {
        printf("%d  ", root->data);
        preorder(root->lc);
        preorder(root->rc);
    }
}

int main()
{
    struct node* root = NULL;
    root = insertNode(root,9);
    //     preorder(root);
    // printf("Success\n");
    root = insertNode(root,5);
    //     preorder(root);
    // printf("Success\n");
    root = insertNode(root, 10);
    //     preorder(root);
    // printf("Success\n");
    root = insertNode(root, 0);
    //     preorder(root);
    // printf("Success\n");
    root = insertNode(root, 6);
    //     preorder(root);
    // printf("Success\n");
    root = insertNode(root, 11);
    //     preorder(root);
    // printf("Success\n");
    root = insertNode(root, -1);
    //     preorder(root);
    // printf("Success\n");
    root = insertNode(root, 1);
    root = insertNode(root, 2);
    printf("preorder:-\n");
    preorder(root);
    root = deleteNode(root, 10);
    printf("\npreorder after deleting 10 is\n");
    preorder(root);
    // searchTree(root, 82);
    // printf("Node found. value = \n");
    // deleteNode(root, 50);
    // printf("done first delete\n");
    // deleteNode(root, 65);
    // printf("done second delete\n");
    // deleteNode(root, 76);
    // printf("done third delete\n");
    // printInorder(root);

    // struct node* root = NULL;
    // root=insertNode(root,10);
    // root=insertNode(root,20);
    // root=insertNode(root,15);
    // preorder(root);
    return 0;
}
