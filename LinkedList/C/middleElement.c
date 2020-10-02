#include <stdio.h> 
#include <stdlib.h> 

/* Link list node */
struct node { 
	int data; 
	struct node* next; 
}; 

/* Function to get the middle of the linked list*/
void printMiddle(struct node* head) 
{ 
	int count = 0; 
	struct node* mid = head; 

	while (head != NULL) { 
		/* update mid, when 'count' is odd number */
		if (count & 1) 
			mid = mid->next; 

		++count; 
		head = head->next; 
	} 

	/* if empty list is provided */
	if (mid != NULL) 
		printf("The middle element is [%d]\n\n", mid->data); 
} 

void push(struct node** head_ref, int new_data) 
{ 
	/* allocate node */
	struct node* new_node 
		= (struct node*)malloc(sizeof(struct node)); 

	/* put in the data */
	new_node->data = new_data; 

	/* link the old list off the new node */
	new_node->next = (*head_ref); 

	/* move the head to point to the new node */
	(*head_ref) = new_node; 
} 

// A utility function to print a given linked list 
void printList(struct node* ptr) 
{ 
	while (ptr != NULL) { 
		printf("%d->", ptr->data); 
		ptr = ptr->next; 
	} 
	printf("NULL\n"); 
} 

/* Driver program to test above function*/
int main() 
{ 
	/* Start with the empty list */
	struct node* head = NULL; 
	int i; 

	for (i = 5; i > 0; i--) { 
		push(&head, i); 
		printList(head); 
		printMiddle(head); 
	} 

	return 0; 
}
