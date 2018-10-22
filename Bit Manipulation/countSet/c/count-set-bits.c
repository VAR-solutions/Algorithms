#include <stdio.h>

int countSimple(int n) {
	int count = 0;
	int iterations = 0;

	// Execute loop while there is any bit set
	while (n) {
		// If the last bit is set, add one to the counter
		count += n & 0x1;
		// Shift one place to the right
		n >>= 1;

		iterations++;
	}

	printf("Simple algorithm iterations: %d\n", iterations);

	return count;
}

// Faster method, iterates exactly s times, where s is the number of bits set
int countBrianKenighan(int n) {
	int count = 0;

	while (n) {
		n &= n - 1;
		count++;
	}

	printf("Brian Kenighan's algorithm iterations: %d\n", count);

	return count;
}

int main(void) {
	int n1, n2;
	int n = 0b101010101010;

	n1 = countSimple(n);
	n2 = countBrianKenighan(n);
	
	printf("%d %d\n", n1, n2);
}
