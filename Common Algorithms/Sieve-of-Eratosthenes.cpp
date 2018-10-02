#include <bits/stdc++.h> 
using namespace std; 

#define MAX 1000
  
void Sieve() { 
    bool prime[MAX+1]; 
    memset(prime, 1, sizeof(prime)); 
    for (int p = 2; p*p <= n; p++) 
    { 
        if (prime[p] == true) { 
            for (int i=p*2; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
    for (int p=2; p<=n; p++) 
       if (prime[p]) 
          cout << p << " "; 
} 
int main() 
{ 
    Sieve(); 
    return 0; 
} 
