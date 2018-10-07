#include <bits/stdc++.h>
using namespace std;

double harmonic(int a, int b) {
    return (double)(2*a*b)/(a + b);
}

int main() {
    int a, b; cin >> a >> b;
    cout << harmonic(a, b);
    return 0;
}
