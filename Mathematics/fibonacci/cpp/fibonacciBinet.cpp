#include<iostream>
#include<math.h>
using namespace std;

int fibonacci(int n)
{
	int temp;
	temp = (pow((1 + sqrt(5)),n) - pow((1 - sqrt(5)),n))/(pow(2,n)*sqrt(5));
	return temp;
}

int main()
{
	int num;
	cout<<"\nEnter the element no.: ";
	cin>>num;
	cout<<"\nElement at position "<<num<<" in Fibonacci Series= "<<fibonacci(num);
	return 0;
}

