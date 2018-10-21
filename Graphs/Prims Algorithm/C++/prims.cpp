//Take a look at the below mentioned link to know about the algorithm
//https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/

#include<bits/stdc++.h>
using namespace std;
#define MAX 999999
#define MIN -999999

int g[1000][1000],d[1000],pi[1000],visited[1000];

int getMin(int n)
{
   int i=0,j,min=MAX;
   for(i=0;i<n;i++)
   {
       if(visited[i]==0 && d[i]<min)
       {
            min=d[i];
            j=i;
       }
   }
   return j;
}

int main()
{
    int n,e,u,v,w;
    printf("Enter no. of node & edges\n");
    scanf("%d %d",&n,&e);

    int i,j,src;
    for(i=0;i<e;i++)
    {
         printf("Enter edge from & to & weight\n");
         scanf("%d %d %d",&u,&v,&w);
         g[u][v]=w;
         g[v][u]=w;
    }


    for(i=0;i<n;i++)
    {
        d[i]=MAX;
        pi[i]=-1;
    }

    printf("Enter source vertex for prim\n");
    scanf("%d",&src);
    d[src]=0;
    pi[src]=-1;

    for(i=0;i<n-1;i++)
    {

        u=getMin(n);
        visited[u]=1;

        for(j=0;j<n;j++)
        {
            if(g[u][j] && visited[j]==0 && g[u][j]<d[j])
            {
                  d[j]=g[u][j];
                  pi[j]=u;
            }
        }
    }
    printf("Mst is\n");
    for(i=1;i<n;i++)
    printf("%d->%d\n",pi[i],i);
  int sum=0;
    for(i=0;i<n;i++)
    {
       sum+=d[i];
    }
    printf("%d\n",sum);
}
