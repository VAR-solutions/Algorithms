# include<iostream>
using namespace std;
int main()
{
	int a[100],n1,n2;
	cin>>n1;
	for(int i =0;i<n1;i++)
	{
		cin>>a[i]>>endl;
	}
	int f =0;
	int l =n1-1;
	int m = (f+l)/2;
	cout<<"enter a number which you want to find:";
	cin>>n2;
	while(f<=l)
	{
		if(n2==a[m])
		{
			cout<<"no. is at index :"<<m;
			break;
		}
		else if(n2<a[m])
		l =m-1;
		else
		f = m+1;
			}
	
	
}
