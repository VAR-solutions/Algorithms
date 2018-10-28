#include<stdio.h>

void main()
{
	int line, line_max, space, column;
	printf("Enter Line limit:");
	scanf_s("%d", &line_max);
	for (line = 1; line <= line_max; line++)
	{
		for (space = 1; space <= line_max - line; space++)
		{
			printf(" ");
		}
		for (column = 1; column <= line; column++)
		{
			printf("* ");
		}
		printf("\n");
	}
}