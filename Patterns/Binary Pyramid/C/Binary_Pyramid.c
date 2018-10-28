#include<stdio.h>

void main()
{
	int line, line_max, column, i = 1;
	printf("Enter Line limit:");
	scanf_s("%d", &line_max);
	for (line = 1; line <= line_max; line++)
	{

		for (column = 1, i = line; column <= line; column++)
		{
			if (i % 2 == 0)
			{
				printf("1");
			}
			else
			{
				printf("0");
			}
			i++;
		}

		printf("\n");
	}
}