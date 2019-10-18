#include <stdio.h>
#include <stdlib.h>

//defining each node of a linked list
typedef struct Node
{
    int data;
    struct Node *next;
}node;

//inserting a new node at the beginning and updating head of the list
void insertNode(node **head,int data)
{
    node *temp=(node*)malloc(sizeof(node*));
    temp->data=data;
    temp->next=*head;
    *head=temp;
}

//displays the whole linked list from head to end
void printList(node *head)
{
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
    return;
}

//reverses the linked list by reversing the next pointer of each node
//three pointers are maintained pointing to the current node and nodes previous and next to the current node
void reverse(node **head)
{
    if(*head==NULL || (*head)->next==NULL)
        return;
    node *curr=*head;
    node *prev=NULL;
    node *next=NULL;
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    *head=prev;
}

//driver program to test the above functions
int main()
{
    node *head=NULL;
    insertNode(&head,1);
    insertNode(&head,2);
    insertNode(&head,3);
    insertNode(&head,4);
    insertNode(&head,5);
    printf("The original list is:\n");
    printList(head);
    reverse(&head);
    printf("The reversed List is:\n");
    printList(head);
    return 0;
}
