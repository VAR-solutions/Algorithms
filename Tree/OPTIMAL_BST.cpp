#include<iostream>

using namespace std;

#define SIZE 10
class OBST
{
int p[SIZE]; // Probabilities with which we search for an element
int q[SIZE];//Probabilities that an element is not found
int a[SIZE];//Elements from which OBST is to be built
int w[SIZE][SIZE];//Weight ‘w[i][j]’ of a tree having root
//’r[i][j]’
int c[SIZE][SIZE];//Cost ‘c[i][j] of a tree having root ‘r[i][j]
int r[SIZE][SIZE];//represents root
int n;  // number of nodes
public:
OBST()
{ int i,j;
for(i=0;i<=n;i++)
for(j=0;j<=n;j++)
c[i][j]=0;
}
/* This function accepts the input data */
void get_data()
{
	int i;
	cout<<"\n Optimal Binary Search Tree \n";
	cout<<"\n Enter the number of nodes";
	cin>>n;
	cout<<"\n Enter the data as…\n";
	for(i=1;i<=n;i++)
	{
		cout<<"\n a["<<i<<"]";
		cin>>a[i];
	}
	for(i=1;i<=n;i++)
	{
		cout<<"\n p["<<i<<"]";
		cin>>p[i];
	}
	for(i=0;i<=n;i++)
	{	
		cout<<"\n q["<<i<<"]";
		cin>>q[i];
	}
}
/* This function returns a value in the range ‘r[i][j-1]’ to ‘r[i+1][j]’so that the cost ‘c[i][k-1]+c[k][j]’is minimum */

int Min_Value(int i,int j)
{
int m,k,val;
int minimum=32000;
for(m=i;m<=j;m++)
{ val=(c[i][m-1]+c[m+1][j]);
	if(val<minimum)
	{
	  minimum=val;
	  k=m;
	}
}
return k;
}

/* This function builds the table from all the given probabilities It basically computes C,r,W values */
void  build_OBST()
{
  int i,j,k,l,m;
  for(i=1;i<=n;i++)
  {
	//initialize
	w[i][i]=q[i-1]+q[i]+p[i];
      c[i][i]=w[i][i];  
	r[i][i]=i;

cout<<"\ni="<<i<<"j="<<i<<"w[i][i]="<<w[i][i]<<"\t"<<c[i][i]<<"\t"<<r[i][i];
	//Optimal trees with one node
	/*w[i][i+1]=q[i]+q[i+1]+p[i+1];
	r[i][i+1]=i+1;
	c[i][i+1]=q[i]+q[i+1]+p[i+1];*/
  }
for(i=0;i<=4;i++)
c[i+1][i]=0;
  //Find optimal trees with ‘m’ nodes
  for(m=2;m<=n;m++)
  {
	for(i=1;i<=n-m+1;i++)
	{
	  j=i+m-1;
          w[i][j]=w[i][j-1]+p[j]+q[j];
          k=Min_Value(i,j);
          c[i][j]=w[i][j]+c[i][k-1]+c[k+1][j];
          r[i][j]=k;
cout<<"\ni="<<i<<"j="<<j<<"w[i][j]="<<w[i][j]<<"\t"<<c[i][j]<<"\t"<<r[i][j];
	}
  }
}
/* This function builds the tree from the tables made by the OBST function */
void build_tree()
{
   int i,j,k;
   int queue[20],front=-1,rear=-1;
   cout<<"The Optimal Binary Search Tree For the Given Node Is…\n";
   cout<<"\n The Root of this OBST is ::"<<r[1][n];
   cout<<"\nThe Cost of this OBST is::"<<c[1][n];
   cout<<"\n\n\t NODE \t LEFT CHILD \t RIGHT CHILD ";
   cout<<"\n";
   queue[++rear]=1;
   queue[++rear]=n;
for(i=0;i<=4;i++)
r[i+1][i]=0;
   while(front!=rear)
   {
	 i=queue[++front];
	 j=queue[++front];
         k=r[i][j];
         cout<<"\n\t"<<k;
	if(r[i][k-1]!=0)
	{
		cout<<"\t\t"<<r[i][k-1];
		queue[++rear]=i;
		queue[++rear]=k-1;
	}
	else
		cout<<"\t\t";
	if(r[k+1][j]!=0)
	{
		cout<<"\t"<<r[k+1][j];
		queue[++rear]=k+1;
		queue[++rear]=j;
	}
	else
		cout<"\t";
	
  }//end of while
  cout<<"\n";
}
};//end of the class
/*This is the main function */

int main()
{
OBST obj;
obj.get_data();
obj.build_OBST();
obj.build_tree();
return 0;
}

