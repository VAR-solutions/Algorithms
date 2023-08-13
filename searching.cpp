# include<iostream>
using namespace std;
int main()
{
	int a[100];
	int n;
	cout<<"enter no of elements in the array";
	cin>>n;
	for(int i =0;i<n;i++)
	{
		cin>>a[i];
}
int p;
for(int i =0;i<n-1;i++)
{
int m =i; 	
 for(int i =0;i<n;i++)
   {
   	if(a[i]>a[i+1]){
	   m = i+1;
   	p =a[i+1];
   	a[i+1] = a[i];
   	a[i]=p;}
   } }
   for(int i =0;i<n;i++)
   {
   	cout<<a[i]<<" ";
   }
   
}
