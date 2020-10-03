#include <stdio.h>

int is_power_of_2(int x) {
	return (x & (x - 1)) == 0;
}

int main() {
	int x;

	scanf("%d", &x);
	printf("%d\n", is_power_of_2(x));

	return 0;
}
