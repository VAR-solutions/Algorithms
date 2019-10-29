#include<iostream>
using namespace std;

void nextvalue(int g[20][20],int x[20],int n,int k)
{
	int j=0;
	do{
		x[k]=(x[k]+1)%(n+1);
		if(x[k]==0)
		 return;
		 
		if(g[x[k-1]][x[k]]==1)
		{
			for(j=1;j<=k-1;j++)
			 if(x[j]==x[k])
			  break;
		
		  
			if(j==k)
		 		if((k<n)||((k==n)&&(g[x[n]][x[1]]==1)))
		  			return;
		}
	}while(1);
}

void hamiltonian(int g[20][20],int x[20],int n,int k)
{
	static int c;
	do{
		nextvalue(g,x,n,k);
		if(x[k]==0)
		{
			//cout<<endl<<"Solution could not be find out";
			return;
		}
		if(k==n)
		{
			cout<<"\nSolution "<<++c<<" is: \n";
			for(int i=1;i<=n;i++)
				cout<<"\t"<<x[i];
			cout<<"\t1"<<endl;          
		}
		else
		 hamiltonian(g,x,n,k+1);
	}while(1);
}

void create(int g[20][20],int i)
{
	int u,v;
	cout<<endl<<"Enter the 2 vertices of edge "<<i<<" u want to join:";
	cin>>u>>v;
	g[u][v]=g[v][u]=1;
	cout<<"Edge created successfully."<<endl;
}

int main()
{
	int g[20][20],n,x[20],e,m;
	
	cout<<endl<<"Enter no of vertices:";
	cin>>n;
	cout<<endl<<"Enter no of edges(paths):";
	cin>>e;
	
	for(int i=1;i<=n;i++)
	 for(int j=1;j<=n;j++)
	 	g[i][j]=0;
	 
	for(int i=1;i<=e;i++)
	  create(g,i);
	/*for(int i=1;i<=n;i++)
	{
		cout<<"\n";
		for(int j=1;j<=n;j++)
			cout<<"adjacency matrix"<<"\t"<<g[i][j];
	}
	*/
	x[1]=1;	
	for(int i=2;i<=n;i++)
	 x[i]=0;
	
	int k=2;
	hamiltonian(g,x,n,k);
}
