#include <bits/stdc++.h>
using namespace std;

long long reverse_number(long long n) {
    long long res = 0;
    while(n > 0) {
        res = res*10 + n % 10;
        n /= 10;
    }
    return res;
}

int main() {
    long long n; cin >> n;
    cout << reverse_number(n);
}
