#include "stdio.h"
#include "math.h"
#include "limits.h"

int min(int a,int b){
	return (a<b)? a: b;
}

void update(int a[],int st[],int i,int j,int idx,int val,int pos){
	if (i==j)
	{
		a[idx]=val;
		st[pos]=val;
	}
	else{
		int mid=(i+j)/2;
		if (i<=idx && idx<=mid)
		{
			update(a,st,i,mid,idx,val,2*pos+1);
		}
		else{
			update(a,st,mid+1,j,idx,val,2*pos+2);
		}
		st[pos]=min(st[2*pos+1],st[2*pos+2]);
	}
}

void build_ST(int a[],int st[],int i,int j, int pos){
	if (i==j)
	{
		st[pos]=a[i];
		return;
	}
	int mid=i + (j -i)/2;
	build_ST(a,st,i,mid,2*pos+1);
	build_ST(a,st,mid+1,j,2*pos+2);
	st[pos]=min(st[2*pos+1],st[2*pos+2]);
}

int range_min_query(int st[],int n,int i,int j,int qi,int qj,int pos){
	if (qi<0 || qj > n || qi>qj)
	{
		printf("Invalid Input");
		return -1;
	}
	else{
		if (qi<=i && qj>=j)
		{
			return st[pos];
		}
		if (j<qi || i>qj)
		{
			return INT_MAX;
		}
		int mid=i + (j -i)/2;
		return min(range_min_query(st,n,i,mid,qi,qj,2*pos+1),range_min_query(st,n,mid+1,j,qi,qj,2*pos+2));
	}
}

int main(int argc, char const *argv[])
{
	int n;
	printf("Enter the number of elements you want in an array: ");
	scanf("%d",&n);
	int a[n];
	printf("Enter elements of array: ");
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&a[i]);
	}
	int h=ceil(log2(n));
	int max_size=2*pow(2,h)-1;
	int st[max_size];
	build_ST(a,st,0,n-1,0);
	
	int bcd;
	printf("Press 1 for Range Min query and 2 for update: ");
	scanf("%d",&bcd);
	if(bcd == 1){
		puts("\n");
		int qi,qj;
		printf("Enter Range for which minimum has to be calculated: ");
		scanf("%d %d",&qi,&qj);
		int rmq=range_min_query(st,n,0,n-1,qi-1,qj-1,0);
		printf("Minimum for this range: %d\n",rmq );
		puts("");
	}
	
	if(bcd==2){
		printf("Enter index to be updated");
		int idx;
		scanf("%d",&idx);
		printf("Enter value to be updated");
		int val;
		scanf("%d",&val);
		update(a,st,0,n-1,idx,val,0);
	}
	
	
	return 0;
}
