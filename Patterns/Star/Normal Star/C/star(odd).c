#include<stdio.h>

void main()
{
	int line, line_max, column;
	printf("Enter Line limit:");
	scanf_s("%d", &line_max);
	for (line = 1; line <= line_max; line++)
	{
		for (column = 1; column <= 2 * line - 1; column++)
		{
			printf("*");
		}
		printf("\n");
	}
}