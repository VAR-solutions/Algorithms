#include <iostream>

#define ll long long

//Program to find the last digit of a sum of the first n Fibonacci numbers

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

int fibonacci_sum(ll n) {
    ll p = pisano_period();
    n = n % p;
    ll a = 0;
    ll b = 1;
    if(n <= 1)
        return n;
    ll sum = 1;
    for(ll i = 2; i < n + 1; i++){
        ll temp = b;
        b = (a + b) % 10;
        a = temp;
        sum += b;
    }
    return sum % 10;
}

int main() {
    ll n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum(n);
}
