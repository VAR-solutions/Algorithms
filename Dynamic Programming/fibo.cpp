#include <bits/stdc++.h>
using namespace std;

int Fib[10000];

int main() {
	int n;
	cin >> n;

	//0th and 1st number of the series are 0 and 1
	Fib[0] = 0;
	Fib[1] = 1;

	//Fibonacci using DP
	for(int i = 2; i <= n; i++) {
		Fib[i] = Fib[i - 1] + Fib[i - 2];
	}

	cout << Fib[n] << endl;

	return 0;
}