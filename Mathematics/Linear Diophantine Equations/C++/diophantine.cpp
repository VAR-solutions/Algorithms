// Algorithm to solve equations like: ax + by = c

// If g = gcd(a, b), a solution exists only if g divides c.

// Find x' and y' for ax' + by' = g

// k = c/g
// x = x' * k
// y = y' * k

// To find other solutions, change the value of z:

// a(x +- (b/g)*z) + b(y -+ (a/g)*z) = c

#include <bits/stdc++.h>

using namespace std;

#define ll long long

//Extended Euclides Algorithm
ll ext_gcd(ll a, ll b, ll &x, ll &y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }

    ll X, Y;

    ll g = ext_gcd(b, a%b, X, Y);

    x = Y;
    y = X - Y*(a/b);

    return g;
}

bool find_solution(ll a, ll b, ll c, ll &x, ll &y, ll &g){
    g = ext_gcd(abs(a), abs(b), x, y);

    if(c%g != 0) return false;

    ll k = c/g;

    x *= k;
    y *= k;

    if(a < 0) x = -x;
    if(b < 0) y = -y;

    return true;
}

int main(){
    ll x, y, g;

    //find one solution for 50x + 20y = 300
    find_solution(50, 20, 300, x, y, g);

    printf("50*%lld + 20*%lld = 300\n", x, y);
}