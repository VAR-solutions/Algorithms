#include <iostream>

#define ll long long

//Program to compute Fn modulo m, where n may be really huge: up to 10^18

ll pisano_period(ll m){
    ll a = 0, b = 1;
    for(ll i = 0; i < m * m; i++){
        ll temp = (a + b) % m;
        a = b;
        b = temp;
        if(a == 0 && b == 1)
            return i + 1;
    }
    return -1;
}

ll fibonacci_huge(ll n, ll m) {
    ll p = pisano_period(m);
    n = n % p;
    ll a = 0, b = 1;
    if(n <= 1)
        return n;
    for(ll i = 2; i < n + 1; i++){
        ll temp = b;
        b = (a + b) % m;
        a = temp;
    }
    return b % m;
}

int main() {
    ll n, m;
    std::cin >> n >> m;
    std::cout << fibonacci_huge(n, m) << '\n';
}
