#include <stdio.h>

int reverse(int x){
	int reverse = 0;
	while (x) {
		reverse =  reverse * 10 + (x % 10);
		x /= 10;
	}
	return reverse;
}

int main(){
	int x;
	scanf("%d", &x);
	printf("%d\n", reverse(x));
	return 0;
}
