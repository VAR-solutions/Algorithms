// Minimum coins needed for a value
#include <bits/stdc++.h>

using namespace std;

int get_change(int m, vector <int> c) {
	vector <int> s(m + 1, m);
	int n = c.size();
	s[0] = 0;
	for (int i = 1; i < m + 1; ++i) {
		for (int j = 0; j < n; ++j) {
			if(i >= c[j] && s[i - c[j]] + 1 < s[i]) {
				s[i] = s[i - c[j]] + 1;
			}
		}
	}
	return s[m];
}

int main() {
	int m, n; cin >> m >> n; // m is the value needed, n is the size of coins array
	vector <int> c(n);
	for (int i = 0; i < n; ++i) {
		cin >> c[i];
	}
	cout << get_change(m, c);
}
