//Program to Implement DEQUE in C++
#include <iostream>
#include <cstdlib>
#define size 5
using namespace std;

//Declaring DEQUE Class
class deque
{
    public:
        int left, right, arrdeque[];
        void rightins();
        void leftins();
        void rightdel();
        void leftdel();
        void display();
        void irque();
        void orque();
        deque()
        {
            
            arrdeque[size];
			left = -1;
			right = -1;
        }
};

//Main function for selecting two types of DEQUE 
int main()
{	int choice;
	deque deque;
	cout<<"Select type of DEQUE:"<<endl;
	cout<<"1.Input Restricted DEQUE"<<endl;
	cout<<"2.Output Restricted DEQUE"<<endl;
	cout<<"Enter your choice : ";
	cin>>choice;
	switch(choice)
	{
	 case 1 :
		deque.irque();
		break;
	 case 2:
		deque.orque();
		break;
	 default:
		cout<<"Please enter correct number!\n";
	}
}

//Program for right insertion
//This program adds element to the right of the DEQUE
void deque::rightins()
{
	if((left == 0 && right == size-1) || (left == right+1))
	{	cout<<"Overflow-Queue is Full!\n";
		return;}
	if (left == -1)  /* if queue is initially empty */
	{	left = 0;
		right = 0;}
	else
	{
	if(right == size-1)  /*right is at last position of queue */
		right = 0;
	else
		right = right+1;
	}
	cout<<"Enter the element for adding to Deque: "<<endl;
	cin>>arrdeque[right];
}

//Program for left insertion
//This program adds element to the left of the DEQUE
void deque::leftins()
{	
	if((left == 0 && right == size-1) || (left == right+1))
	{	
		cout<<"Overflow-Queue is Full!\n";
		return;	 }
	if (left == -1)/*If queue is initially empty*/
	{	
		left = 0;
		right = 0;	 }
	else
	{
	if(left== 0)
		left=size-1;
	else
		left=left-1;
	}
	cout<<"Enter the element for adding to Deque: ";
	cin>>arrdeque[left];
 }

//Program for right deletion
//This program removes element from the right of the DEQUE
void deque::rightdel()
{if (left == -1)
	{
		cout<<"Underflow-Queue is Empty!\n";
		return ;	 }
	cout<<"Element deleted from queue is : "<<arrdeque[right];
	if(left == right) /*queue has only one element*/
	{	
		left = -1;
		right=-1;	 }
	else
		if(right == 0)
			right=size-1;
		else
			right=right-1;	}

//Program for left deletion
//This program removes element from the left of the DEQUE
void deque::leftdel()
{	if (left == -1)
	{	
		cout<<"Underflow-Queue is Empty!\n";
		return ;	}
	cout<<"Element deleted from queue is : "<<arrdeque[left];
	if(left == right) /*Queue has only one element */
	{	
		left = -1;
		right=-1;	 }
	else
	{
		if(left == size-1)
			left = 0;
		else
			left = left+1;
	}
}

//Program to display the DEQUE
//This program traverses the DEQUE and prints all elements
void deque::display()
{	int front_pos = left,rear_pos = right;
	if(left == -1)
	{	
		cout<<"Queue is empty\n";
		return;	 }
	cout<<"Queue elements :\n";
	if( front_pos <= rear_pos )
	{	while(front_pos <= rear_pos)
		{	
			cout<<" "<<arrdeque[front_pos];
			front_pos++;	}	}
	else
	{	while(front_pos <= size-1)
		{	
			cout<<" "<<arrdeque[front_pos];
			front_pos++;	}
		front_pos = 0;
		while(front_pos <= rear_pos)
		{	
			cout<<" "<<arrdeque[front_pos];
			front_pos++;
		}
	}
	cout<<endl;
}

//Program for Input-Restricted DEQUE
//This program is activated if user selects INPUT RESTRICTED DEQUE in Main Function
void deque::irque()
{	int choice;
	deque deque;
	do
	{	
		cout<<"\nOPERATIONS:"<<endl;
		cout<<"1.Insert element at right"<<endl;
		cout<<"2.Delete element from left"<<endl;
		cout<<"3.Delete element from right"<<endl;
		cout<<"4.Display the Deque"<<endl;
		cout<<"5.Quit"<<endl;
		cout<<"Enter your choice : ";
		cin>>choice;

		switch(choice)
		{	case 1:
			deque.rightins();
			break;
		 case 2:
			deque.leftdel();
			break;
		 case 3:
			deque.rightdel();
			break;
		 case 4:
			deque.display();
			break;
		 case 5:
            break;
		 default:
			cout<<"Please enter correct number!\n";
		}
	}while(choice!=5);
}

//Program for Output-Restricted DEQUE
//This program is activated if user selects OUTPUT RESTRICTED DEQUE in Main Function
void deque::orque()
{	int choice;
	deque deque;
	do
	{	
		cout<<"\nOPERATIONS:"<<endl;
		cout<<"\n1.Insert element at right"<<endl;
		cout<<"2.Insert element at left"<<endl;
		cout<<"3.Delete element from left"<<endl;
		cout<<"4.Display the Deque"<<endl;
		cout<<"5.Quit"<<endl;
		cout<<"Enter your choice : ";
		cin>>choice;
		switch(choice)
		{
		 case 1:
			deque.rightins();
			break;
		 case 2:
			deque.leftins();
			break;
		 case 3:
			deque.leftdel();
			break;
		 case 4:
			deque.display();
			break;
		 case 5:
			break;
		 default:
			cout<<"Please enter correct number!\n";
		}
	}while(choice!=5);
}

//There was only one bug, the second input into the array was always 4, no matter what user input was
//I was unable to resolve this issue
