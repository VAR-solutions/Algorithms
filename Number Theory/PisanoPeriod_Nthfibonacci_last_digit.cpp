#include <iostream>

#define ll long long

// Program To Calculate Last Digit of Nth Fibonacci Number( N <= 10^18 )

ll get_fibonacci_last_digit(ll n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (ll i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current)%10;
    }

    return current % 10;
}

int main() {
    ll n;
    std::cin >> n;
    int c = get_fibonacci_last_digit(n);
    std::cout << c << '\n';
    }
