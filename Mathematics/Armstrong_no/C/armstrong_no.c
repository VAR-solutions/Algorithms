/**
 * C program to check Armstrong number
 */
#include <stdio.h>
#include <math.h>

int main()
{
    int originalNum, num, lastDigit, digits, sum;

    /* Input number from user */
    printf("Enter any number to check Armstrong number: ");
    scanf("%d", &num);

    sum = 0;

    /* Copy the value of num for processing */
    originalNum = num;

    /* Find total digits in num */
    digits = (int) log10(num) + 1;

    /* Calculate sum of power of digits */
    while(num > 0)
    {
        /* Extract the last digit */
        lastDigit = num % 10;

        /* Compute sum of power of last digit */
        sum = sum + round(pow(lastDigit, digits));

        /* Remove the last digit */
        num = num / 10;
    }

    /* Check for Armstrong number */
    if(originalNum == sum)
    {
        printf("%d is ARMSTRONG NUMBER", originalNum);
    }
    else
    {
        printf("%d is NOT ARMSTRONG NUMBER", originalNum);
    }

    return 0;
}
