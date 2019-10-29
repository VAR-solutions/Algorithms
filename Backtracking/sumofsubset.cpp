#include<iostream>
using namespace std;

void sumofsub(int x[10],int w[10],int m,int n,int s,int k,int r)
{
	x[k]=1;
	static int c;
	if(s+w[k]==m)
	{
		cout<<"\nSolution "<<++c<<" is: \n";
		for(int i=1;i<=n;i++)
			cout<<"\t"<<x[i];
		cout<<endl;
	}
	else
	 if(s+w[k]+w[k+1]<=m)
	  sumofsub(x,w,m,n,s+w[k],k+1,r-w[k]);
	  
	if((s+r-w[k]>=m)&&(s+w[k+1]<=m))
	{
		x[k]=0;
		sumofsub(x,w,m,n,s,k+1,r-w[k]);
	}
}

int main()
{
	int n,m,w[10],x[10],sum=0;
	cout<<"\nEnter the no of weights:";
	cin>>n;
	cout<<"\nEnter the required total sum of weights:";
	cin>>m;
	cout<<"\nEnter the weights in increasing order:";
	for(int i=1;i<=n;i++)
	{
		cout<<"\nweight "<<i<<" :";
		cin>>w[i];
		sum+=w[i];
		x[i]=0;
	}
	 
	sumofsub(x,w,m,n,0,1,sum);
}
