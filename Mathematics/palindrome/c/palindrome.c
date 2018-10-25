#include <stdio.h>

int reverse(int x){
	int reverse = 0;
	while (x){
		reverse = reverse * 10 + (x % 10);
		x /= 10;
	}
	return reverse;
}

void palindrome(int x){
	if (x == reverse(x)) 
		printf("This number is a palindrome !\n");
	else
		printf("This number is not a palindrome !\n");
}

int main() {
	int x;
	scanf("%d", &x);
	palindrome(x); 
	return 0;
}

