/*
     hare krishna hare krishna krishna krishna hare hare
     hare rama hare rama rama rama hare
*/
#include<bits/stdc++.h>
using namespace std;
int n,c,num,val;
class node{
	public:
		int num,coeff;
		node *next;
		node(int n,int c)
		{
			num=n;
			coeff=c;
			next=NULL;
		}
		node()
		{
			num=0,coeff=0;
			next=NULL;
		}
};

node *start1 = NULL,*start2=NULL,*start3=NULL,*start4=NULL;


node* createll(node *start)
{
	node* n,*p;
	cout<<"\nenter -1 to end\n";
	cin>>num>>c;
	while(num!=-1)
	{
		n=new node(num,c);
		if(start==NULL)
		{	
		    start=n;
		}
		else
		{
			p=start;
			while(p->next!=NULL)
				p=p->next;
			p->next=n;
		}
		cin>>num;
		if(num==-1)
		break;
		cin>>c;
	}
	return start;
}
node *display(node* start)
{
	node *t=start;
	while(t!=NULL)
	{
		cout<<t->num<<" x ^ "<<t->coeff<<" -> ";
		t=t->next;
	}
	cout<<"NULL\n";
	return start;
}
node *addnode(node *start,int num,int c)
{
	node *p,*n;
	n=new node(num,c);
	if(start==NULL)
	{
		start=n;
	}
	else
	{
		p=start;
		while(p->next!=NULL)
		p=p->next;
		p->next=n;
	}
	return start;
}
node *addpoly(node *start3,node* a,node *b)
{
	node *p1=a,*p2=b;
	int sum;
	while(p1!=NULL&&p2!=NULL)
	{
		if(p1->coeff==p2->coeff)
		{
			sum= p1->num+p2->num;
			start3 = addnode(start3,sum,p1->coeff);
			p1=p1->next;
			p2=p2->next;
		}
		else if(p1->coeff>p2->coeff)
		{
			start3= addnode(start3,p1->num,p1->coeff);
			p1=p1->next;
		}
		else if(p2->coeff>p1->coeff)
		{
			start3= addnode(start3,p2->num,p2->coeff);
			p2=p2->next;
		}		
	}
	if(p1==NULL)
	{
		while(p2!=NULL)
		{
			start3= addnode(start3,p2->num,p2->coeff);
			p2=p2->next;
		}
	}
	if(p2==NULL)
	{
		while(p1!=NULL)
		{
			start3= addnode(start3,p1->num,p1->coeff);
			p1=p1->next;
		}
	}
	return start3;
}
node *subpoly(node *s4,node *a,node *b)
{
    int diff;
	node *p1=a, *p2=b;
	while(p1!=NULL&&p2!=NULL)
	{
		if(p1->coeff==p2->coeff)
		{
			diff= p1->num - p2->num;
			s4= addnode(s4,diff,p1->coeff);
			p1=p1->next;
			p2=p2->next;
		}
		else if(p1->coeff>p2->coeff)
		{
			s4= addnode(s4,p1->num,p1->coeff);
			p1=p1->next;
		}
		else if(p2->coeff>p1->coeff)
		{
			s4= addnode(s4,p2->num,p2->coeff);
			p2=p2->next;
		}
	}
	if(p1==NULL)
	{
		while(p2!=NULL)
		{
				s4= addnode(s4,p2->num,p2->coeff);
			p2=p2->next;
			
		}
	}
	if(p2==NULL)
	{
		while(p1!=NULL)
		{
				s4= addnode(s4,p1->num,p1->coeff);
			p1=p1->next;
		}
	}
	
	return s4;
}
int main()
{
	int option;
	do{
		cout<<"\n\n *******MAIN MENU*******";
		cout<<"\n 1:  Enter First Polynomial ";
		cout<<"\n 2:  Display First Polynomial ";
		cout<<"\n 3:  Enter Second Polynomial";
		cout<<"\n 4:  Display Second Polynomial";
		cout<<"\n 5:  Add the Polynomials";
		cout<<"\n 6:  Display the add result Polynomial";
		cout<<"\n 7:  Subtract the polynomials";
		cout<<"\n 8:  Display the subtract result polynomial";
		cout<<"\n 9:  exit\n";
		cin>>option;
		switch(option)
		{
			case 1:
				start1= createll(start1);
				break;
			case 2:
				display(start1);
				break;
			case 3:
				start2= createll(start2);
				break;
			case 4:
				display(start2);
				break;
			case 5:
				start3= addpoly(start3,start1,start2);
				break;
			case 6:
				display(start3);
				break;
			case 7:
				start4= subpoly(start4,start1,start2);
				break;
			case 8:
				display(start4);
				break;

    	}
	}while(option!=9);
	
	return 0;
}

