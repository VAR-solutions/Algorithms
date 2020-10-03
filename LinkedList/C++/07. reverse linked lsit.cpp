/*
     hare krishna hare krishna krishna krishna hare hare
     hare rama hare rama rama rama hare
*/
#include<bits/stdc++.h>
using namespace std;
int num,val;
class ll{
	public:
		int data;
		ll *next;
		ll(int n)
		{
			data=n;
			next=NULL;
		}
};
ll *createll(ll *start)
{
	cout<<"create linked list ... enter -1 to end\n";
	cin>>val;
	while(val!=-1)
	{
		ll *n=new ll(val);
		if(start==NULL)
		start=n;
		else
		{
			ll *p=start;
			while(p->next!=NULL)
			{
				p=p->next;
			}
			p->next=n;
			
		}
		cin>>val;
	}
	return start;
}
void display(ll *start)
{
	cout<<"linked list is\n";
	ll *p=start;
	while(p!=NULL)
	{
		cout<<p->data<<" -> ";
		p=p->next;
	}
	cout<<"NULL\n";
}

ll *iterativereverse(ll *start)
{
    ll *curr=start;
    ll *prev=NULL,*next=NULL;
    while(curr!=NULL)
    {
    	next=curr->next;
    	curr->next=prev;
    	prev=curr;
    	curr=next;
	}
	start=prev;
	return start;
}
ll *recursivereverse(ll *start)
{
	if(start==NULL||start->next==NULL)
	return start;
	
	ll* r= recursivereverse(start->next);
	start->next->next=start;
	
	start->next=NULL;
	
	return r;
}

int main()
{
   ll *start= NULL;
   start=createll(start);
   display(start);
   start= iterativereverse(start);
   display(start);
   start = recursivereverse(start);
   display(start);

   return 0;
}

