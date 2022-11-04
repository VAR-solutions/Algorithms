// Circular Queue

// a[] - circular queue
// front - first element
// rear - last element

#include<stdio.h>
#include<stdlib.h>
#define size 20

int a[size], front=0, rear=0;

// Function to display the circular queue
void display()
{
	printf("\nThe queue is:\n");

	if(rear==0)
	{
		printf("empty\n");
		return;
	}

	for(int i=front+1; i<=rear; i++)
		printf("%d ", a[i]);
	printf("\n");
}

// Function to insert element to the circular queue
void insert(int n)
{
	rear=(rear+1)%n;
	if(front==rear)
		printf("Queue overflow\n");
	else
	{
		printf("\nEnter the element to be inserted\n");
		scanf("%d", &a[rear]);
		display();
	}
}

// Function to delete element from the circular queue
void delete(int n)
{
	if(front==rear)
		printf("Queue underflow\n");
	else
	{
		printf("\nDeleted element %d from queue\n", a[front+1]);
		if(rear==1)
			front=rear=0;
		else
			front=(front+1)%n;
		display();
	}
}

void main()
{
	int n, choice;
	char ch;
	printf("Enter the size of circular queue\n");
	scanf("%d", &n);
	do
	{
		printf("\nCircular Queue Menu\n___________________\n");
		printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
		printf("\nEnter your choice\n");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:	insert(n);
					break;
			case 2:	delete(n);
					break;
			case 3: display();
					break;
			case 4:	exit(0);
			default:printf("Invalid choice\n");
					
		}
		printf("\nDo you want to continue? [y/n]\n");
		scanf(" %c", &ch);
	}
	while(ch=='Y'||ch=='y');
}