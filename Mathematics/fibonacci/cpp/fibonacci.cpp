#include<iostream>
using namespace std;

int main()
{
	int n{}, i{3};
	cin >> n;
	long a{1}, b{1}, c{};
	if(n <= 2)
		cout << (n == 2? "1 1": "1");
	else{
		cout << "1 1 ";
		while(i <= n){
			c = a + b;
			b = a;
			a = c;
			cout << a << " ";
			i++;
		}
	}   
}
