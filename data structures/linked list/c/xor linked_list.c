#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int data;
    struct node* npx;
};

struct node* XOR(struct node *a, struct node *b)
{
    return (struct node*) ((unsigned int) (a) ^ (unsigned int) (b));
}
void insert(struct node **head_ref, int data) 
{
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->npx = XOR(*head_ref, NULL);
    if (*head_ref != NULL)
    {
        struct node* next = XOR((*head_ref)->npx, NULL);
        (*head_ref)->npx = XOR(new_node, next);
    }

    // Change head
    *head_ref = new_node;
}

void printList(struct node *head)
{
    struct node *curr = head;
    struct node *prev = NULL;
    struct node *next;

    printf("The elements of linked list are: \n");

    while (curr != NULL)
    {
        // print current node
        printf("%d ", curr->data);
        next = XOR(prev, curr->npx);
        prev = curr;
        curr = next;
    }
}

int main()
{
    int n,value;
    struct node *head = NULL;
    printf("Enter the number of elements you want to enter: ");
    scanf("%d",&n);
    printf("Enter %d elements: ",n);
    while(n--)
    {
        scanf("%d",&value);
        insert(&head,value);
    }
    printList(head);

    return (0);
}