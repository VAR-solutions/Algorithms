#include<stdio.h>

void countsort(int a[],int d[],int b[],int e[],int k1,int k2,int n)
{
	int c[k2-k1+1],i,j;
	for(i=k1;i<=k2;i++)
		c[i]=0;
	for(j=1;j<=n;j++)
		c[d[j]]=c[d[j]]+1;
	c[k1-1]=0;
	for(i=k1;i<=k2;i++)
		c[i]=c[i]+c[i-1];
	for(j=n;j>0;j--)
	{
		b[c[d[j]]]=d[j];
		c[d[j]]=c[d[j]]-1;
	}
}

int main()
{
	int a[100],b[100],e[100],i,j,n,d[100],t,k1=0,k2=0;
	
	printf("Enter size: ");
	scanf("%d",&n);
	printf("Enter elements:\n");
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	
	for(i=1;i<=n;i++)
	{
		d[i]=a[i]%10;
	}
	for(i=1;i<=n;i++)
	{
		if(d[i]>k2)
			k2=a[i];
		if(d[i]<k1)
			k1=a[i];
	}
	countsort(a,d,b,e,k1,k2,n);
	
	return 0;
}
