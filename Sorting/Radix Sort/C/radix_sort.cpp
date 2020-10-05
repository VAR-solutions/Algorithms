#include "stdafx.h"
#include <stdio.h> 
#include <stdlib.h> 

void radixSort(int[]);

int main(void) {
	int data[10] = { 73, 22, 93, 43, 55, 14, 28, 65, 39, 81 };

	printf("\nBefore Sorting: ");
	int i;
	for (i = 0; i < 10; i++)
		printf("%d ", data[i]);

	putchar('\n');

	radixSort(data);

	printf("\nAfter Sorting: ");
	for (i = 0; i < 10; i++)
		printf("%d ", data[i]);
	
	putchar('\n');
	system("pause");
	return 0;
}

void radixSort(int data[]) {
	int temp[10][10] = { 0 };
	int order[10] = { 0 };

	int n = 1;
	while (n <= 10) {

		int i;
		for (i = 0; i < 10; i++) {
			int lsd = ((data[i] / n) % 10);
			temp[lsd][order[lsd]] = data[i];
			order[lsd]++;
		}

		// re-sorting
		int k = 0;
		for (i = 0; i < 10; i++) {
			if (order[i] != 0) {
				int j;
				for (j = 0; j < order[i]; j++, k++) {
					data[k] = temp[i][j];
				}
			}
			order[i] = 0;
		}

		n *= 10;
	}
}