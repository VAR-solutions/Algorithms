//Double Ended Queue

// a[] - double ended queue
// front - first element
// rear - last element

#include<stdio.h>
#include<stdlib.h>

int a[20],front=-1,rear=-1;

// Function to display the double ended queue
void display(int n)
{
	int f=front, r=rear;
	printf ("\nThe queue is:\n");
	if(f!=-1)
	{
		if(f<=r)
		{
			for(int i=f;i<=r;i++)
				printf("%d ", a[i]);
		}
		else
		{
			for(int i=f;i<=n-1;i++)
				printf("%d ", a[i]);
			f=0;
			for(int i=f;i<=r;i++)
				printf("%d ", a[i]);
		}
		printf("\n");
	}
	else
		printf("empty\n");
}

// Function to insert element at the beginning of double ended queue
void insertFront(int n)
{
	if ((front==0 && rear==n-1) || front==rear+1)
		printf("Queue overflow\n");
	else
	{
		if(front==-1)
			front=rear=0;
		else if(front==0)
			front=n-1;
		else
			front--;
	
	printf("\nEnter the element to be inserted\n");
	scanf("%d",&a[front]);
	display(n);
	}
}

// Function to insert element at the end of double ended queue
void insertRear(int n)
{
	if ((front==0 && rear==n-1) || front==rear+1)
		printf ("Queue overflow\n");
	else
	{
		if(front==-1)
			front=rear=0;
		else if(rear==n-1)
			rear=0;
		else
			rear++;

		printf("\nEnter the element to be inserted\n");
		scanf("%d", &a[rear]);
		display(n);
	}
}

// Function to delete element from the beginning of double ended queue
void deleteFront(int n)
{
	if(front==-1)
		printf ("Queue underflow\n");
	else
	{
		printf("\nDeleted element %d from queue\n", a[front]);
		if (front==rear)
			front=rear=-1;
		else if(front==n-1)
			front=0;
		else
			front++;
	}
	display(n);
}

// Function to delete element from the end of double ended queue
void deleteRear(int n)
{
	if(front==-1)
		printf("Queue underflow\n");
	else
	{
		printf("\nDeleted element %d from queue\n", a[rear]);
		if(front==rear)
			front=rear=-1;
		else if(rear==0)
			rear=n-1;
		else
			rear--;
	}
	display(n);
}

void main()
{
	int n, choice;
	char ch;
	printf("Enter the size of double ended queue\n");
	scanf("%d", &n);
	do
	{
		printf("\nDouble Ended Queue Menu\n_______________________\n");
		printf("1. Insert at front end\n2. Insert at rear end\n3. Delete at front end\n4. Delete at rear end\n5. Display\n6. Exit\n");
		printf("\nEnter your choice\n");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:	insertFront(n);
					break;
			case 2:	insertRear(n);
					break;
			case 3: deleteFront(n);
					break;
			case 4:	deleteRear(n);
					break;
			case 5:	display(n);
					break;
			case 6:	exit(0);
					break;
			default:printf("Invalid choice\n");
					
		}
		printf("\nDo you want to continue? [y/n]\n");
		scanf(" %c", &ch);
	}
	while(ch=='Y'||ch=='y');
}





