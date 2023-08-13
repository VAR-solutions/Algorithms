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
void createll(ll **start)
{
	cout<<"create linked list ... enter -1 to end\n";
	cin>>val;
	while(val!=-1)
	{
		ll *n=new ll(val);
		if(*start==NULL)
		*start=n;
		else
		{
			ll *p=*start;
			while(p->next!=NULL)
			{
				p=p->next;
			}
			p->next=n;
			
		}
		cin>>val;
	}
	//return start;
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
ll* sumll(ll *s1, ll* s2)
{
   ll *s3=NULL;
   ll *t,*pre=NULL;
   int carry=0,sum;
   while(s1||s2)
   {
   	  sum= carry + (s1?s1->data: 0) + (s2? s2->data: 0);
   	  carry= (sum>=10)?1: 0;
   	  sum = sum %10;
   	  t=new ll(sum);
   	  
   	  if(s3==NULL)
   	  s3=t;
   	  else
   	  pre->next=t;
   	  
   	  pre=t;
   	  
   	  if(s1)
   	  s1=s1->next;
   	  if(s2)
   	  s2=s2->next;
   	  
   }
   if(carry>0)
   t->next =new ll(carry);
   
   return s3;
}
int main()
{
   ll *start1= NULL,*start2= NULL, *start3= NULL;
   createll(&start1);
   display(start1);
   createll(&start2);
   start3 = sumll(start1, start2);
   cout<<"summation of both linked list is ";
   display(start3);
   
   return 0;
}

