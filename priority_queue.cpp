#include<iostream.h>
	#include<conio.h>

	const int MAX=5;

	class pqueue
	{
		  int front,rear;
		public:
		  struct data
		  {
		   int val,p,o;
		  }d[MAX];

		 pqueue()
		 {
			front=rear=-1;
		 }
		 void insert(data d1);
		 data deletion();
		 void display();
	};
	void pqueue :: insert(data d1)
	{
		if(rear==MAX-1)
		   cout<<"Priority Queue is Full
";
		else
		{
		   rear++;
		   d[rear]=d1;
		   if(front==-1)
			  front=0;
		   data temp;
		   for(int i=front;i<=rear;i++)
			 for(int j=i+1;j<=rear;j++)
			 {
				 if(d[i].p > d[j].p)
				 {
					temp=d[i];
					d[i]=d[j];
					d[j]=temp;
				 }
				 else
				 {
					 if(d[i].p==d[j].p)
					 {
						 if(d[i].o > d[j].o)
						 {
							  temp=d[i];
							  d[i]=d[j];
							  d[j]=temp;
						 }
					 }
				 }
			 }
		}
	}
	data pqueue :: deletion()
	{
		data d1;
		if(front==-1)
		   cout<<"Priority Queue is Empty
";
		else
		{
		   d1=d[front];
		   if(front==rear)
			  front=rear=-1;
		   else
			  front++;
		}
		return d1;
	}
	void pqueue :: display()
	{
		 if(front==-1)
			 cout<<"Priority Queue is Empty
";
		 else
		 {
			for(int i=front;i<=rear;i++)
			{
				cout<<"Object  :"<<i+1<<endl;
				cout<<"Value ="<<d[i].val<<endl;
				cout<<"Priority="<<d[i].p<<endl;
				cout<<"Order =  "<<d[i].o<<endl;
			}
		 }
	}
	void main()
	{
	  pqueue p1;

	  data d1;
	  char op;
	  do
	  {
		int ch;

		clrscr();
		cout<<"----------Menu-------------
";
		cout<<"1.Insertion
2.Deletion
3.Display
4.Exit
";
		cout<<"Enter your Choice<1..4> ?";
		cin>>ch;
		switch(ch)
		{
		   case 1 :  cout<<"Enter Value ?";
					 cin>>d1.val;
					 cout<<"Enter Priority?";
					 cin>>d1.p;
					 cout<<"Enter Order ?";
					 cin>>d1.o;
					 p1.insert(d1);
					 break;
		   case 2 :  d1=p1.deletion();
					 cout<<"Value = "<<d1.val<<endl;
					 cout<<"Priority = "<<d1.p<<endl;
					 cout<<"Order ="<<d1.o<<endl;
					 break;
		   case 3 :  p1.display();
					 break;
		  }
		  cout<<"Do You Want to Continue <Y/N> ?";
		  cin>>op;
		}while(op=='Y' || op=='y');
		getch();
	  }
