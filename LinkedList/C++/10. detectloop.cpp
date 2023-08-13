/*
     hare krishna hare krishna krishna krishna hare hare
     hare rama hare rama rama rama hare
*/
#include<bits/stdc++.h>
using namespace std;
int num,val;
class node{
	public:
		int data;
	    node *next;
		node(int n)
		{
			data=n;
			next=NULL;
		}	
};
void push(node **start,int num)
		{
			node *n= new node(num);
			n->next=*start;
			*start=n;
		}
		void display(node *start)
		{
			node *p=start;
			while(p!=NULL)
			{
				cout<<p->data<<" -> ";
			p=p->next;
		}
		cout<<"NULL\n";
		}
		bool detloop(node *start)
		{
		  unordered_set<node *>s;
		  while(start!=NULL)
		  {
		  	if(s.find(start)!=s.end())
		  	return true;
		  	
		  	s.insert(start);
		  	start=start->next;
		  }
		   return false; 
		}
	int len(node *p)
	{
		int l=1;
		node *q=p;
		while(q->next!=p)
		{
			l++;
			q=q->next;
		}
		return l;
	}
int detloop2(node *start)
{
	node *p1=start;
	node *p2=start;
	while(p1&&p2&&p2->next)
	{
		p1=p1->next;
		p2=p2->next->next;
		if(p1==p2)
		return len(p1);
	}
	return 0;
}
node *start=NULL;
int main()
{
   int n;
   cin>>n;
   for(int i=0;i<n;i++)
   {
   	cin>>num;
   	push(&start,num);
   }
   display(start);
   if(detloop(start))
   cout<<"loop is detected\n";
   else
   cout<<"loop not found\n";
    start->next->next->next->next->next=start->next;
   if(detloop2(start))
   cout<<"loop is detected of length "<<detloop2(start)<<endl;
   else
   cout<<"loop not found\n";
   return 0;
}

