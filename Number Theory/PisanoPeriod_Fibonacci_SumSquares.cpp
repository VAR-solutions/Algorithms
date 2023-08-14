#include <iostream>

#define ll long long

//Program to find the last digit of a sum of the squares of first n Fibonacci numbers

ll pisano_period(ll m = 10){
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

ll fibonacci_square(ll n) {
    ll p = pisano_period();
    ll q = n / p;
    n = n % p;
    ll a = 0;
    ll b = 1;
    ll sum1 = 1, sum2 = 1;
    if(n==0)
        sum1 = 0;
    for(ll i = 2; i < p; i++){
        ll temp = b;
        b = (a + b) % 10;
        a = temp;
        sum2 += (b * b) % 10;
        if(i <= n)
            sum1 += (b * b) % 10;
    }
    return (sum1 + q * sum2) % 10;
}

int main() {
    ll n = 0;
    std::cin >> n;
    std::cout << fibonacci_square(n);
}
