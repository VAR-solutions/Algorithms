#include<iostream>
using namespace std;

#define ll long long

ll fib(int n)
{
	if(n == 0)
		return 0;
		
	if(n == 1)
		return 1;
		
	return fib(n-1)+fib(n-2);
}

int main()
{
	int n;
	cin>>n;
	
	ll result = fib(n);
	cout<<result<<endl;
}
