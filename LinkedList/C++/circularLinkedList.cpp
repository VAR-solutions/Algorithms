#include<bits/stdc++.h> 
using namespace std; 

struct Node 
{ 
	int data; 
	struct Node *next; 
}; 

struct Node *addToEmpty(struct Node *node, int data) 
{ 
	
	if (node != NULL) 
	return node; 

	
	struct Node *temp = 
		(struct Node*)malloc(sizeof(struct Node)); 

	
	temp -> data = data; 
	node = temp; 


	node -> next = node; 

	return node; 
} 

struct Node *addBegin(struct Node *node, int data) 
{ 
	if (node == NULL) 
		return addToEmpty(node, data); 

	struct Node *temp = 
			(struct Node *)malloc(sizeof(struct Node)); 

	temp -> data = data; 
	temp -> next = node -> next; 
	node -> next = temp; 

	return node; 
} 

struct Node *addEnd(struct Node *node, int data) 
{ 
	if (node == NULL) 
		return addToEmpty(node, data); 
	
	struct Node *temp = 
		(struct Node *)malloc(sizeof(struct Node)); 

	temp -> data = data; 
	temp -> next = node -> next; 
	node -> next = temp; 
	node = temp; 

	return node; 
} 

struct Node *addAfterPosition(struct Node *node, int data, int item) 
{ 
	if (node == NULL) 
		return NULL; 

	struct Node *temp, *p; 
	p = node -> next; 
	do
	{ 
		if (p ->data == item) 
		{ 
			temp = (struct Node *)malloc(sizeof(struct Node)); 
			temp -> data = data; 
			temp -> next = p -> next; 
			p -> next = temp; 

			if (p == node) 
				node = temp; 
			return node; 
		} 
		p = p -> next; 
	} while(p != node -> next); 

	cout << item << " is not present in the list." << endl; 
	return node; 

} 

void traverse(struct Node *node) 
{ 
	struct Node *p; 

	
	if (node == NULL) 
	{ 
		cout << "List is empty." << endl; 
		return; 
	} 

	
	p = node -> next; 

	do
	{ 
		cout << p -> data << " "; 
		p = p -> next; 

	} 
	while(p != node->next); 

} 


int main() 
{ 
	struct Node *node = NULL; 

	node = addToEmpty(node, 6); 
	node = addBegin(node, 4); 
	node = addBegin(node, 2); 
	node = addEnd(node, 8); 
	node = addEnd(node, 12); 
	node = addAfterPosition(node, 10, 8); 

	traverse(node); 

	return 0; 
} 
