
#include <bits/stdc++.h> 
using namespace std; 
  
bool isPrime(int n) 
{  
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
  
    for (int i = 5; i * i <= n; i = i + 6) { 
        if (n % i == 0 || n % (i + 2) == 0) { 
            return false; 
        } 
    } 
  
    return true; 
} 
bool isPowerOfTwo(int n) 
{ 
    return (n && !(n & (n - 1))); 
} 
int main() 
{ 
    int n = 43; 
    if (isPrime(n) && (isPowerOfTwo(n * 3 - 1))) { 
        cout << "YES\n"; 
    } 
    else { 
        cout << "NO\n"; 
    } 
  
    return 0; 
} 
