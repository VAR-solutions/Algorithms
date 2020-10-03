#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	//0th and 1st number of the series are 0 and 1
	int a = 0;
	int b = 1;

	//Fibonacci using DP
	for(int i = 2; i <= n; i++) {
		int c = a + b;
		a = b;
		b = c;
	}

	cout << a << endl;

	return 0;
}
