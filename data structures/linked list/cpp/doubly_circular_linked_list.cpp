#include <bits/stdc++.h>

using namespace std;

struct node
{
	int val;
	node *next; 
	node *prev;
};

node * getNode()
{
	node *new_node =  new node;
	return new_node;
}

void freeNode(node *& n)
{
	delete n;
}

void createLinkedList(node* &head)
{
	cout<<"Creating Linked List: \n";
	int n;
	cout<<"Enter the Number of Elements in Linked List: ";
	cin>>n;
	if (n==0) return;
	node * start = head;
	cout<<"Enter the elements of Linked List separated by spaces: ";
	for (int i=0; i<n; ++i)
	{
		int element;
		cin>>element;
		node * next_node = getNode();
		start->next = next_node;
		next_node->val = element;
		next_node->next = head;
		next_node->prev = start;
		start = start->next;
		head->prev = next_node;
	}
}

void displayLinkedList(node * &head)
{
	cout<<"\nDisplaying Linked List: ";
	node * start = head->next;
	while(start!=head)
	{
		cout<<(start->val)<<" ";
		start = start->next;
	}
	cout<<"\n\n";
}

void insertFront(node * &head)
{
	cout<<"\nEnter Element to insert at front: ";
	int element;
	cin>>element;

	node * new_node = getNode();
	new_node->val = element;
	new_node->next = head->next;
	new_node->prev = head;
	head->next->prev = new_node;
	head->next = new_node;
	displayLinkedList(head);	
}

void insertEnd(node * &head)
{
	cout<<"\nEnter element to insert at end: ";
	int element;
	cin>>element;

	node * new_node = getNode();
	new_node->val = element;
	head->prev->next = new_node;
	new_node->prev = head->prev;
	new_node->next = head;
	head->prev = new_node;
	displayLinkedList(head);
}

void insertBeforeKey(node * &head)
{	
	cout<<"\nEnter key before which element is to be inserted: ";
	int key;
	cin>>key;
	cout<<"Enter element to insert: ";
	int element;
	cin>>element;

	node * start = head;

	while (start->next!=head)
	{
		if (start->next->val == key)
			break;
		start = start->next;
	}
	if (start->next == head)
	{
		cout<<"Key not found!\n";
		return;
	}
	node * new_node = getNode();
	new_node->val = element;
	new_node->next = start->next;
	new_node->prev = start;
	start->next->prev = new_node;
	start->next = new_node;
	displayLinkedList(head);
}

void insertAfterKey(node* &head)
{
	cout<<"\nEnter key after which element is to be inserted: ";
	int key;
	cin>>key;
	cout<<"Enter element to insert: ";
	int element;
	cin>>element;
	node * start = head->next;

	while(start!=head)
	{
		if (start->val == key)
			break;
		start = start->next;
	}
	if (start==head)
	{
		cout<<"Key not found!\n";
		return;
	}
	node *new_node = getNode();
	new_node->val = element;
	new_node->next = start->next;
	new_node->prev = start;
	start->next->prev = new_node;
	start->next = new_node;
	displayLinkedList(head);
}

void deleteFront(node * &head)
{
	cout<<"Deleting from front: \n";
	node *start = head;
	if (start->next==head)
	{
		cout<<"Empty Linked List!\n";
		return ;
	}
	node * front = start->next;
	start->next = front->next;
	front->next->prev = start;
	freeNode(front);
	displayLinkedList(head);
}

void deleteEnd(node * &head)
{
	cout<<"Deleting from End: \n";
	node *start = head;
	if (start->next==NULL)
	{
		cout<<"Empty Linked List!\n";
		return ;
	}
	node *delete_node = head->prev;
	delete_node->prev->next = head;
	head->prev = delete_node->prev;
	freeNode(delete_node);
	displayLinkedList(head);
}

void deleteKeyNode(node * &head)
{
	cout<<"\nDeleting key Node: \n";
	cout<<"Enter key: ";
	int key;
	cin>>key;
	node *start = head;

	while (start->next!=head)
	{
		if (start->next->val == key)
			break;
		start = start->next;
	}
	if (start->next == head)
	{
		cout<<"Key not found!\n";
		return;
	}
	node * key_node = start->next;
	start->next = key_node->next;
	key_node->next->prev = start;
	freeNode(key_node);
	displayLinkedList(head);
}

int main()
{
	node *head = getNode();
	head->val = 0;
	head->next = head;
	head->prev = head;

	cout<<"---Create Circular Double Linked List---\n";
	createLinkedList(head);

	cout<<"---Display Circular Double Linked List---\n";
	displayLinkedList(head);

	cout<<"---Insert Front in Circular Double Linked List---\n";
	insertFront(head);

	cout<<"---Insert End in Circular Double Linked List---\n";
	insertEnd(head);

	cout<<"---Insert Before Key in Circular Double Linked List---\n";
	insertBeforeKey(head);

	cout<<"---Insert After Key in Circular Double Linked List---\n";	
	insertAfterKey(head);

	cout<<"---Delete Front in Circular Double Linked List---\n";
	deleteFront(head);

	cout<<"---Delete End in Circular Double Linked List---\n";
	deleteEnd(head);

	cout<<"---Delete Key Node in Circular Double Linked List---\n";
	deleteKeyNode(head);

	return 0;
}
