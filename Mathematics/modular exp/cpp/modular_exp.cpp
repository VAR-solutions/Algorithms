#include <bits/stdc++.h>
using namespace std;

/// modn is the chosen prime
const long long modn = 1000000007;
inline long long mod(long long x) { return x % modn; }

long long expo(long long num, long long exp){
	long long ans = 1;
	while(exp){
		if(exp&1)
			ans = mod(ans*num);
		num = mod(num*num);
		exp >>= 1;
	}
	return ans;
}

// computes x's modular inverse
long long mod_inv(long long x){
	return expo(x, modn-2);
}

int main (){
	long long x, exp;
	scanf("%lld %lld", &x, &exp);
	printf("%lld\n", expo(x, exp));
}
