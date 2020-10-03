/*
Given a Linked List of length n and block length k rotate in circular manner towards right/left each block by a number d.
If d is positive rotate towards right else rotate towards left.

Examples:

Input: 1->2->3->4->5->6->7->8->9->NULL, 
        k = 3 
        d = 1
Output: 3->1->2->6->4->5->9->7->8->NULL
Explanation: Here blocks of size 3 are
rotated towards right(as d is positive) 
by 1.
 
Input: 1->2->3->4->5->6->7->8->9->10->
               11->12->13->14->15->NULL, 
        k = 4 
        d = -1
Output: 2->3->4->1->6->7->8->5->10->11
             ->12->9->14->15->13->NULL
Explanation: Here, at the end of linked 
list, remaining nodes are less than k, i.e.
only three nodes are left while k is 4. 
Rotate those 3 nodes also by d.

Approach:
The idea is if the absolute value of d is greater than the value of k, then rotate the link list by d % k times. 
If d is 0, no need to rotate the linked list at all.
*/
// C++ program to rotate a linked list block wise 
#include<bits/stdc++.h> 
using namespace std; 

/* Link list node */
class Node 
{ 
	public: 
	int data; 
	Node* next; 
}; 

// Recursive function to rotate one block 
Node* rotateHelper(Node* blockHead, 
						Node* blockTail, 
						int d, Node** tail, 
						int k) 
{ 
	if (d == 0) 
		return blockHead; 

	// Rotate Clockwise 
	if (d > 0) 
	{ 
		Node* temp = blockHead; 
		for (int i = 1; temp->next->next && 
						i < k - 1; i++) 
			temp = temp->next; 
		blockTail->next = blockHead; 
		*tail = temp; 
		return rotateHelper(blockTail, temp, 
							d - 1, tail, k); 
	} 

	// Rotate anti-Clockwise 
	if (d < 0) 
	{ 
		blockTail->next = blockHead; 
		*tail = blockHead; 
		return rotateHelper(blockHead->next, 
				blockHead, d + 1, tail, k); 
	} 
} 

// Function to rotate the linked list block wise 
Node* rotateByBlocks(Node* head, 
								int k, int d) 
{ 
	// If length is 0 or 1 return head 
	if (!head || !head->next) 
		return head; 

	// if degree of rotation is 0, return head 
	if (d == 0) 
		return head; 

	Node* temp = head, *tail = NULL; 

	// Traverse upto last element of this block 
	int i; 
	for (i = 1; temp->next && i < k; i++) 
		temp = temp->next; 

	// storing the first node of next block 
	Node* nextBlock = temp->next; 

	// If nodes of this block are less than k. 
	// Rotate this block also 
	if (i < k) 
		head = rotateHelper(head, temp, d % k, 
									&tail, i); 
	else
		head = rotateHelper(head, temp, d % k, 
									&tail, k); 

	// Append the new head of next block to 
	// the tail of this block 
	tail->next = rotateByBlocks(nextBlock, k, 
									d % k); 

	// return head of updated Linked List 
	return head; 
} 

/* UTILITY FUNCTIONS */
/* Function to push a node */
void push(Node** head_ref, int new_data) 
{ 
	Node* new_node = new Node; 
	new_node->data = new_data; 
	new_node->next = (*head_ref); 
	(*head_ref) = new_node; 
} 

/* Function to print linked list */
void printList(Node* node) 
{ 
	while (node != NULL) 
	{ 
		cout << node->data << " "; 
		node = node->next; 
	} 
} 

/* Driver code*/
int main() 
{ 
	/* Start with the empty list */
	Node* head = NULL; 

	// create a list 1->2->3->4->5-> 
	// 6->7->8->9->NULL 
	for (int i = 9; i > 0; i -= 1) 
		push(&head, i); 

	cout<<"Given linked list \n"; 
	printList(head); 

	// k is block size and d is number of 
	// rotations in every block. 
	int k = 3, d = 2; 
	head = rotateByBlocks(head, k, d); 

	cout << "\nRotated by blocks Linked list \n"; 
	printList(head); 

	return (0); 
} 
