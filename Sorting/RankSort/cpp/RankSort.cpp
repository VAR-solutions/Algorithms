#include <iostream>
using namespace std;
void rankSort(int A[], int n)
{
	int U[n],R[n];
	for(int i=0;i<n;i++)
	{
		R[i]=0;
	}
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(A[j]<=A[i])
			R[i]=R[i]+1;
			else
			R[j]=R[j]+1;
		}
	}
	for(int j=0;j<n;j++)
	{
		U[R[j]]=A[j];
	}
	for(int j=0;j<n;j++)
	{
		A[j]=U[j];
	}
}

int main()
{
	int n;
	cout<<"Enter the number of element to sorted\n";
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	rankSort(a,n);
	cout<<"Sorted Array is :- ";
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}