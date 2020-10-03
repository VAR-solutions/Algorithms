#include<stdio.h>
#include<stdlib.h>

// Define the node and declare head, temp variables.

struct node{
	int data;
	struct node* link;
}*head, *temp;

//Function to insert at beginning
void begins(int x){
	struct node* new = (struct node*)malloc(sizeof(struct node));
	new -> data = x;
	if (head == NULL){
		head = new;
		head -> link = NULL;
		return;
	}
	new -> link = head;
	head = new;
}

//Function to insert at end
void endins(int x){
	struct node *new, *ptr;
	new = (struct node*)malloc(sizeof(struct node));
	new -> data = x;
	if (head == NULL){
		head = new;
		head -> link = NULL;
		return;
	}
	ptr = head;
	while(ptr -> link != NULL){
		ptr = ptr -> link;
	}
	ptr -> link = new;
	new -> link = NULL;
}

//Function to insert at a position
void posins(int x, int pos){
	struct node *new, *ptr;
	new = (struct node*)malloc(sizeof(struct node));
	new -> data = x;
	if (head == NULL){
		head = new;
		head -> link = NULL;
		return;
	}
	ptr = head;
	int count = 0;
	while(count != pos && ptr -> link != NULL){
		ptr = ptr -> link;
		count++;
	}
	new -> link = ptr -> link;
	ptr -> link = new;
}

//Function to insert before a specific data node
void datains(int x, int data){
	struct node *new, *ptr, *ptr1;
	new = (struct node*)malloc(sizeof(struct node));
	new -> data = x;
	if (head == NULL){
		head = new;
		head -> link = NULL;
		return;
	}
	ptr = head;
	while(ptr -> data != data && ptr -> link != NULL){
		ptr1 = ptr;
		ptr = ptr -> link;
	}
	new -> link = ptr;
	ptr1 -> link = new;
}

//Function to delete at beginning
void begdel(){
	if (head == NULL){
		printf("LIST ALREADY EMPTY\n");
		return ;
	}
	temp = head;
	head = head -> link;
	free(temp);
}

//Function to delete at end
void enddel(){
	if (head == NULL){
		printf("LIST ALREADY EMPTY\n");
		return ;
	}
	struct node* ptr = head;
	while(ptr -> link -> link != NULL){
		ptr = ptr -> link;
	}
	temp = ptr -> link;
	ptr -> link = NULL;
	free(temp);
}

//Function to delete at a position
void posdel(int pos){
	if (head == NULL){
		printf("LIST ALREADY EMPTY\n");
		return ;
	}
	int count = 0;
	struct node* ptr = head, *ptr1;
	while(count != pos && ptr -> link != NULL){
		ptr1 = ptr;
		ptr = ptr -> link;
		count++;
	}
	temp = ptr;
	ptr1 -> link = ptr -> link;
	free(temp);
}

//Function to delete before a specific data node
void datadel(int data){
	if (head == NULL){
		printf("LIST ALREADY EMPTY\n");
		return ;
	}
	struct node* ptr = head, *ptr1;
	while(ptr -> link -> data != data && ptr -> link != NULL){
		ptr1 = ptr;
		ptr = ptr -> link;
	}
	temp = ptr;
	ptr1 -> link = ptr -> link;
	free(temp);
}

//Function to neatly display the list
void disp(){
	printf("\n======================================================\n");
	struct node* ptr = head;
	while (ptr != NULL){
		printf("%d ", ptr -> data);
		ptr = ptr -> link;
	}
	printf("\n======================================================\n");
}

int main(){
	int c, x, pos;
	while(1){
		printf("1. Beg Ins\n2. End Ins\n3. Beg Del\n4. End Del\n5. Pos Ins\n6. Data Ins\n7. Pos Del\n8. Data Del\nEnter your choice: ");
		scanf("%d", &c);
		switch(c){
			case 1: printf("Enter the data to be inserted: ");
					scanf("%d", &x);
					begins(x);
					break;
			case 2: printf("Enter the data to be inserted: ");
					scanf("%d", &x);
					endins(x);
					break;
			case 3:	begdel();
					break;
			case 4:	enddel();
					break;
			case 5: printf("Enter the Position and Data: ");
					scanf("%d%d", &pos, &x);
					if(pos == 0){
						begins(x);
						break;
					}
					posins(x, pos-1);
					break;
			case 6: printf("Enter the insert-before-data data and data: ");
					scanf("%d%d", &pos, &x);
					datains(x, pos);
					break;
			case 8: printf("Enter the delete-before-data data: ");
					scanf("%d", &pos);
					datadel(pos);
					break;
			case 7: printf("Enter the Position: ");
					scanf("%d", &pos);
					if(pos == 0){
						begdel();
						break;
					}
					posdel(pos-1);
					break;
			default:printf("INVALID CHOICE\n");
		}
		disp();
	}
	return 0;
}
