/*
     hare krishna hare krishna krishna krishna hare hare
     hare rama hare rama rama rama hare
*/
#include<bits/stdc++.h>
using namespace std;
int num,val,x,y;
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
ll *swapnodes(ll *s,int a,int b)
{
	if(x==y)
	return s;
	
	ll *prea=NULL,*curra=s;
	while(curra&&curra->data!=a)
	{
		prea=curra;
		curra=curra->next;
	}
	
	ll *preb=NULL, *currb=s;
	while(currb&&currb->data!=b)
	{
		preb= currb;
		currb= currb->next;
	}
	
	if(curra==NULL||currb==NULL)
	return s;
	
	if(prea)    // if a is not start
	prea->next = currb;
	else         
	s= currb;
	
	if(preb)   /// if b is not start
	preb->next= curra;
	else
	s= curra;
	
	ll *t= currb->next;
	currb->next = curra->next;
	curra->next= t;
	
    return s;
}
int main()
{
   ll *start= NULL;
   start=createll(start);
   display(start);
   cout<<"enter nodes needs to be swapped\n";
   cin>>x>>y;
   start=swapnodes(start,x,y);
   display(start);
   
   return 0;
}
