/*
    This is an implementation of Matrix Exponentiation made in C++.
    In this case, the base cases are f(0) = 0, f(1) = 1, f(2) = 1.
    The reccurence relation is f(n) = f(n-1) + f(n-2) + f(n-3).
    This code calculates f(n) % 1000000007.
    
    Example cases:
    f(3) = 2 
    f(6) = 13
    f(13) = 927
    f(927) = 925180093
    f(925180093) = 563997300
*/

#include <bits/stdc++.h>
#define LL long long
#define MOD 1000000007

using namespace std;

const LL sz = 3; // size of matrix

// A utility function to multiply two matrices, result of multiplication stored in a.
void multiply(LL a[sz][sz], LL b[sz][sz]) {
    LL mul[sz][sz];
    for (LL i = 0; i < sz; i++) {
        for (LL j = 0; j < sz; j++) {
            mul[i][j] = 0;
            for (LL k = 0; k < sz; k++) {
                mul[i][j] += (a[i][k]%MOD)*(b[k][j]%MOD);
                mul[i][j] %= MOD;
            }
        }
    }
    for (LL i=0; i<sz; i++) {
        for (LL j=0; j<sz; j++) {
            a[i][j] = mul[i][j];
        }
    }
}

// Function to compute F raise to power of n.
LL power(LL F[sz][sz], LL n) {
    LL M[sz][sz] = {{1,1,1}, {1,0,0}, {0,1,0}}; // modify this matrix according to what you need
    if (n==1) return (F[0][0] + F[0][1]) % MOD; // base case

    power(F, n/2);
    multiply(F, F);
    if (n%2 != 0) multiply(F, M);

    return (F[0][0] + F[0][1])%MOD;
}

// Solver function
LL findNthTerm(LL n) {
    if (n == 0) return 0;
    else if (n == 1) return 1;
    else if (n == 2) return 1;
    LL F[sz][sz] = {{1,1,1}, {1,0,0}, {0,1,0}}; // modify this too
    return power(F, n-2);
}

// Driver code
int main() {
    LL n;
    cin >> n;
    cout << findNthTerm(n) << endl;
    return 0;
}