#include<stdio.h>

void main()
{
	int line, line_max, space, column;
	printf("Enter Line limit:");
	scanf_s("%d", &line_max);
	for (line = line_max; line >= 1; line--)
	{
		for (space = 1; space <= line_max - line; space++)
		{
			printf(" ");
		}
		for (column = 1; column <= 2 * line - 1; column++)
		{
			printf("*");
		}
		printf("\n");
	}
}