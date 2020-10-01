#include<bits/stdc++.h>
using namespace std;

void merge(int a[],int low,int mid,int high)
{
    int n1=mid-low+1;
    int n2=high-mid;
    int L1[n1];
    int R1[n2];
    for(int i=0;i<n1;i++)
    {
        L1[i]=a[low+i];
    }
    for(int j=0;j<n2;j++)
    {
        R1[j]=a[mid+j+1];
    }
    int i=0,j=0,k=low;
    while(i<n1&&j<n2)
    {
        if(L1[i]>=R1[j])
        {
            a[k]=R1[j];
            j++;
            k++;
        }
        else
        {
            a[k]=L1[i];
            i++;
            k++;
        }
    }
    	while (i < n1) {
		a[k] = L1[i];
		i++;
		k++;
	}


	while (j < n2) {
		a[k] = R1[j];
		j++;
		k++;
	}

}

void mergesort(int a[],int l,int h)
{
    if(l<h)
    {
        int mid=(l+h)/2;
        mergesort(a,l,mid);
        mergesort(a,mid+1,h);
        merge(a,l,mid,h);
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    mergesort(a,0,n-1);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}
