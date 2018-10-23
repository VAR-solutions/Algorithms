//Take a look at the below mentioned lik to know about the algorithm
//https://www.geeksforgeeks.org/bellman-ford-algorithm-dp-23/

#include<stdio.h>
#define MAX 999999
#define MIN -999999

struct node
{
   int u,v,w;
}a[1000];

int d[1000],pi[1000];

void main()
{
    int k,i,j,e,n,u,v,w,src;
    printf("Enter no. of nodes & edges\n");
    scanf("%d %d",&n,&e);
    for(i=0;i<e;i++)
    {
         printf("Enter edge from & to & weight\n");
         scanf("%d %d %d",&a[i].u,&a[i].v,&a[i].w);
    }

    for(i=0;i<n;i++)
    {
         d[i]=MAX;
         pi[i]=-1;
    }

    printf("Enter source vertex\n");
    scanf("%d",&src);

    d[src]=0;
    pi[src]=-1;

    for(i=0;i<(n-1);i++)
    {
         for(j=0;j<e;j++)
         {
              if(d[a[j].u]!=MAX && (d[a[j].u]+a[j].w)<d[a[j].v])
              {
                  d[a[j].v]=d[a[j].u]+a[j].w;
                  pi[a[j].v]=pi[a[j].u];
              }
         }
         /*for(k=0;k<n;k++)
         {
               printf("%d->%d\n",k,d[k]);
         }*/
    }


    int c=1;

         for(i=0;i<e;i++)
         {
              if(d[a[i].u]!=MAX && (d[a[i].u]+a[i].w)<d[a[i].v])
              {
                  c=0;
                  goto z;
              }
         }

    z:
    if(c==0)
    {
         printf("Bellman ford can't be applied\n");
    }
    else
    {
         for(i=0;i<n;i++)
         {
               printf("%d->%d\n",i,d[i]);
         }
    }
}