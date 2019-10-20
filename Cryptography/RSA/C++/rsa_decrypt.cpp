// Implementation of RSA Decryption for small numbers (n, e, c up to 10^9)
#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

LL modinv(LL u, LL v)
{
    LL inv, u1, u3, v1, v3, t1, t3, q;
    LL iter;
    u1 = 1;
    u3 = u;
    v1 = 0;
    v3 = v;
    iter = 1;
    while (v3 != 0)
    {
        q = u3 / v3;
        t3 = u3 % v3;
        t1 = u1 + q * v1;
        u1 = v1; v1 = t1; u3 = v3; v3 = t3;
        iter = -iter;
    }
    if (u3 != 1)
        return 0;   
    if (iter < 0)
        inv = v - u1;
    else
        inv = u1;
    return inv;
}

LL poww(LL a, LL b, LL mod) {
    if (b==0) return 1;
    if (b==1) return a;
    if (b%2==0) return ((poww(a,b/2,mod)%mod)*(poww(a,b/2,mod)%mod))%mod;
    else return ((((poww(a,b/2,mod)%mod)*(poww(a,b/2,mod)%mod))%mod)*(a%mod));
}

int main() {
    /*
    tc = number of testcases
    n = modulus
    e = public exponent
    c = ciphertext
    p,q = prime factorization of n
    phi = totient of n
    d = private exponent
    m = plaintext message
    */
    int tc;
    cin >> tc;
    while (tc--) {
        LL e,c;
        LL n;
        cin >> c >> e >> n;
        LL p=-1,q=-1;
        for (int i=2;i*i<=n;i++) {
            if (n%i==0) {
                p=i;
                q=n/i;
                break;
            }
        }
        LL phi= (p-1)*(q-1);
        LL d=modinv(e,phi);
        //cout << d << endl;
        LL m = poww(c,d,n);
        m=m%n;
        cout << m << endl;
    }
   return 0;
} 