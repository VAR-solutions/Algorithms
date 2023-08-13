// Stack

// a[] - stack
// top - top(or the newest) element of the stack

#include <stdio.h>
#include <stdlib.h>
#define size 20

int a[size], top=-1;

// Function to display the stack
void display()
{
	printf("\nThe stack is:\n");

	if(top==-1)
	{
		printf("empty\n");
		return;
	}
	
	for(int i=0;i<=top;i++)
		printf("%d ",a[i]);
	printf("\n");
}

// Function to push element to the stack
void push(int n)
{
	if(top==n-1)
		printf("Stack overflow\n");
	else
	{
		top++;
		printf("\nEnter the element to push\n");
		scanf("%d", &a[top]);
		display();
	}
}

// Function to pop element from the stack
void pop()
{
	if(top==-1)
		printf("Stack underflow\n");
	else
	{
		printf("\nPopped element %d from stack\n", a[top]);
		top--;
		display();
	}
}

void main()
{
	int n, choice;
	char ch;
	printf("Enter the stack size\n");
	scanf("%d", &n);
	do
	{
		printf("\nStack Menu\n__________\n");
		printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
		printf("\nEnter your choice\n");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:	push(n);
					break;
			case 2:	pop();
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