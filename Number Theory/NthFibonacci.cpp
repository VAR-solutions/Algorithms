#include <iostream>

#define ll long long

// Calculation of Nth Fibonacci Number(<=10^18)

ll fibonacci(ll n) {
    ll a = 0,b = 1;
    if ( n <= 1 )
        return n;
    for (ll i = 2; i < n + 1; i++){
        ll temp = b;
        b = a + b;
        a = temp;
    }
    return b;
}

int main() {
    ll n = 0;
    std::cin >> n;
    std::cout << fibonacci(n) << '\n';
    return 0;
}