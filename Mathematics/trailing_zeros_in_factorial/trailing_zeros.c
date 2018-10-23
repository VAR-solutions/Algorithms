#include <stdio.h>

int main() {
	int x, zeros = 0;

	scanf("%d", &x);
	for (int i = 1; i <= x; ++i) {
		int aux = i;

		while (aux % 5 == 0) {
			aux = aux / 5;
			zeros++;
		}
	}

	printf("%d\n", zeros);

	return 0;
}