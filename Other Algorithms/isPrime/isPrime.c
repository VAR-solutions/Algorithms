#include <stdio.h>

int isPrime(int x) {
	if (x == 0 || x == 1) {
		return 0;
	}

	for (int i = 2; i < x / 2; ++i) {
		if (x % i == 0) {
			return 0;
		}
	}

	return 1;
}

int main() {
	int x;

	scanf("%d", &x);
	printf("%d\n", isPrime(x));
	return 0;
}