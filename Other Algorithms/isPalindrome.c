#include <stdio.h>

int reverse_number(int x) {
	int rev_x = 0;

	while (x != 0) {
		rev_x = rev_x * 10 + x % 10;
		x = x / 10;
	}

	return rev_x;
}

int isPalindrome(int x) {
	return reverse_number(x) == x;
}

int main() {
	int x;

	scanf("%d", &x);
	printf("%d\n", isPalindrome(x));

	return 0;
}
