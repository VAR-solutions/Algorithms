#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	 Node*next;
	 
};
Node*head,*p,*q;
void Insert_at_beginning(int data)                  //driver function to insert at the beginning of the list//
{
	Node*p=new Node();
	p->data=data;
	p->next=head->next;
	head->next=p;
}
void Insert_at_givenposition(int data,int pos)      //driver function to insert at a given position in the list//
{
	Node*p=new Node();
	p->data=data;
	p->next=NULL;
	if(pos==1)
	{
		p->next=head->next;
		head->next=p;
		return;
		
	}
	q=head;
	for (int i =0;i<pos-2;i++)
	{
		q=q->next;
	}
	p->next=q->next;
	q->next=p;
}
void Insert_at_end(int data)                           // driver function to insert at the end of the list//
{
	p=head;
	
	while(p->next!=NULL)
	{
		
		p=p->next;
	}
	q=new Node();
	q->data=data;
	
	q->next=NULL;
	p->next=q;
	
	
}
void Delete_from_beginning()                                   // driver function to delete the node at the beginning of the list//
{
	p=head;
	head=head->next;
	free(p);
}
void Delete_from_givenposition(int pos)                        // driver function to delete the node at a given position of the list//
{
	
	p=head;
	for(int i=1;i<pos-1;i++)
	{
		q=p;
		p=p->next;
	}

	q=p->next;
	p->next=q->next;
	free(q);
	
}
void Delete_from_end()                                           // driver function to delete the node at the end of the list//
{
	p=head;
	while(p->next!=NULL)
	{
		q=p;
		p=p->next;
	}
	q->next=NULL;
	free(p);
}
void display()
{
	p=head;
	while(p!=NULL)
	{
		cout<<p->data<<endl;
		p=p->next;
	}
}
int main()
{
	int x;
	head=new Node();
	cout<<"Enter the value of head node"<<endl;
	cin>>x;
	head->data=x;
	head->next=NULL;
	
	p=head;
	Insert_at_beginning(12);
	display();
	Insert_at_end(5);
	display();
	Insert_at_givenposition(22,1);
	display();
	Insert_at_beginning(3);
	display();
	Insert_at_end(78);
	display();
	Delete_from_beginning();
	display();
	Delete_from_end();
	display();
	Delete_from_givenposition(2);
	display();
	return 0;
}
