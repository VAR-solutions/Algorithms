#include<stdio.h>
#include<stdlib.h>

//description of a node of the list
typedef struct node{
	int data;
	struct node *link;
}Node;

//inserting a node at the beginning of the list
Node *addAtBeginning(Node *head, int item){
	Node *new = (Node *)malloc(sizeof(Node));
	new->data = item;
	new->link = head;
	head = new;
	return head;
}

//inserting a node at the end of the list
Node *addAtEnd(Node *head, int item){
	Node *new = (Node *)malloc(sizeof(Node));
	new->data = item;
	if(head == NULL){
		head = addAtBeginning(head, item);
		return head;
	}
	Node *t = head;
	while(t->link)
		t = t->link;
	new->link = NULL;
	t->link = new;
	return head;
}

//creating the single linked list
Node *createList(Node *head){
	int n, item;
	printf("Enter the total no of nodes: ");
	scanf("%d", &n);
	if(n == 0)
		return head;
	printf("Enter the element to be inserted in the list: ");
	scanf("%d", &item);
	head = addAtBeginning(head, item);
	for(int i = 2; i <= n; i++){
		printf("Enter the element to be inserted in the list: ");
		scanf("%d", &item);
		head = addAtEnd(head, item);
	}
	return head;
}

//displaying the elements of the list
void display(Node *head){
	if(head == NULL){
		printf("List is empty.\n");
		return;
	}
	printf("\nThe list elements are:\n");
	Node *t = head;
	while(t){
		printf("%d ", t->data);
		t = t->link;
	}
	printf("\n");
	return;
}

//iterative reversal algorithm
Node *reverseList(Node *head){
	Node *prev, *cur, *next;
	prev = NULL;
	next = NULL;
	cur = head;
	while(cur){
		next = cur->link;
		cur->link = prev;
		prev = cur;
		cur = next;
	}
	return prev;
}

int main(){
	Node *head = NULL;
	head = createList(head);
	printf("\nBefore reversal:\n");
	display(head);
	head = reverseList(head);
	printf("\nAfter reversal:\n");
	display(head);
	return 0;
}

/*

One possible outcome:

If the elements of the single linked list are: 2 -> 3 -> 4 -> 6
then after reversing, the list elements will be: 6 -> 4 -> 3 -> 2

*/