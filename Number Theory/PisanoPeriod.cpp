#include <iostream>

#define ll long long

/*
In number theory, the nth Pisano period, written π(n), is the period with
which the sequence of Fibonacci numbers taken modulo n repeats. Pisano
periods are named after Leonardo Pisano, better known as Fibonacci. 
The existence of periodic functions in Fibonacci numbers was noted by Joseph Louis Lagrange in 1774.
*/

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
int main() {
    ll n;
    std::cin >> n;
    std::cout << "Pisano Period for n(" << n << ") in F mod n is " << pisano_period(n) << '\n';
}