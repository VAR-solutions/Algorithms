/* 
* Lets say we have a singly LinkeList of 5 nodes :
* 	1->2->3->4->5->NULL
* The middle element of the list is 3rd element. 
* The below implementation finds if using two pointers, also called Flloyd's Hare and Tortoise method in a single pass..
* Time Complexity : O(N)
* Space Complexity : O(1) 
*/

#include<bits/stdc++.h>
struct Node
{
    int data;
    struct Node* next;
};

void create(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    new_node->data = new_data;

    new_node->next = (*head_ref);

    (*head_ref) = new_node;
}

void printMiddle(struct Node *head)
{
    struct Node *slow_ptr = head;
    struct Node *fast_ptr = head;

    if (head!=NULL)
    {
        while (fast_ptr != NULL && fast_ptr->next != NULL)
        {
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }
        printf("The middle element is %d", slow_ptr->data);
    }
}
int main()
{
    struct Node* head = NULL;
    int i;

    for (i=10; i>0; i--) //Adjust the value of i for the number of nodes in LinkedList
    {
        create(&head, i);
    }

        printMiddle(head);
    return 0;
}
