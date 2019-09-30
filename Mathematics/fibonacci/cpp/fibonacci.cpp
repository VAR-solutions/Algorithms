#include<iostream>
using namespace std;

int main()
{
	const int n = 10; /// fibonacci sequence size
	int fib[105];
	fib[1] = fib[2] = 1;
	for(int i=3;i<=n;i++)
		fib[i] = fib[i-1] + fib[i-2];
	for(int i=1;i<=n;i++)
		cout <<fib[i] << " ";
	cout << endl;
	
return 0;
}
