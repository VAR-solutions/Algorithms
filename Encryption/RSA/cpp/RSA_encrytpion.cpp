#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string>

using std::string;

long long int inv(long long int a, long long int b);
int gcd(long long int a, long long int b);
string bin(long long int n);
long long int modpower(long long int base,long long int exp, long long int mod);

void main() {
	srand(time(NULL));

	long long int e = 23;
	long long int phi;
	int counter;
	long long int p, q;
	long long int n;
	long long int d;

	// random p and q (must be primary) 
	do {
		do {
			p = rand() % 100000 + 1000;
			counter = 0;
			for (int i = 2; i <= p / 2; i++) {
				if (p % i == 0) {
					counter = counter + 1;
					break;
				}
			}
		} while (counter >= 1);

		do {
			q = rand() % 10000 + 1000;
			counter = 0;
			for (int i = 2; i <= q / 2; i++) {
				if (q % i == 0) {
					counter = counter + 1;
					break;
				}
			}
		} while (counter >= 1 | q==p);
		// calculating n and phi while phi and e are coprime
		n = p*q;
		phi = (p - 1)*(q - 1);
		d = inv(e, phi);
	} while ((gcd(e, phi)!=1) | (d==0));

	// calculating d inverse mod phi 

	// public and private key
	printf("public key: n:%lld, e:%d\n",n,e);
	printf("private key: n:%lld, d:%lld\n",n,d);

	// text (to be improved for dynamic)
	char txt[] = "aba";

	// text as ASCII number
	long long int m[3];
	// encrypted msg
	long long int c[3];

	// changing msg to encrypted msg
	for (int i = 0; i < 3; i++) {
		m[i] = txt[i];
		c[i] = modpower(m[i], e, n);
	}

	// representation of an encrypted msg as binary string
	string code;
	for (int i = 0; i < 3; i++) {
		code = bin(c[i]) + code;
	}
	
	// reverse action 
	long long int w2[3];
	for (int i = 0; i < 3; i++) {
		w2[i] = modpower(c[i], d, n);
	}
	
	printf("number: %lld %lld %lld\n", m[0], m[1], m[2]);
	printf("number_c: %lld %lld %lld\n", c[0], c[1], c[2]);
	printf("number_after: %lld %lld %lld\n", w2[0], w2[1], w2[2]);

	system("PAUSE");
}

long long int inv(long long int a, long long int b){
	long long int temp = 1;
	for (int i = 1; i < b; i++){
		temp = temp * a;
		if ((temp % b) == 1) {
			return (temp/a)%b;
		}
	}
}

int gcd(long long int a, long long int b)
{
	int x = a;
	long long int y = b;
	if (x == 0)
		return y;
	return gcd(y % x, x);
}

string bin(long long int n)
{
	string r;
	while (n != 0) {
		r = (n % 2 == 0 ? "0" : "1") + r;
		n = n/2; 
	}
	return r;
}

long long int modpower(long long int base, long long int exp, long long int mod) {
	string e = bin(exp);
	int l = e.length();
	long long int d = 1;
	for (int i = l-1; i >= 0; i--) {
		d = d*d;
		d = d%mod;
		if (e.at(i) == '1') {
			d = d*base;
			d = d%mod;
		}
	}
	return d;
}
