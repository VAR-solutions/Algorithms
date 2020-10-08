#include<iostream>

using namespace::std;

int quickpass(int a[], int n) { 
	int x = a[0];
	int st=1,end=n-1;
	int temp;
	while(st<=end) {
		while(a[st]<=a[0] && st<=end)st++;
		while(a[end]>=a[0] && end>=st) end--;
		if(st>=end)break;
		temp=a[st];a[st]=a[end];a[end]=temp;
	}
	temp=a[end];a[end]=a[0];a[0]=temp;
	return end;
}

/*
 * returns value of (k+1)th largest element
 */
int kth(int a[],int n, int k)
{
	if(k<0 || k>=n)return -1;
	int x = quickpass(a,n);
	if(x==k) return a[x];
	if(x>k) return kth(a,x,k);
	return kth(a+x+1,n-x-1,k-x-1);
}

int main()
{
	int a[5] = {2,4,3,1,5};
	cout<<kth(a,5,3)<<endl; // test case; 
	return 0;
	
}