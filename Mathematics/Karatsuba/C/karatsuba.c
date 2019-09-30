#include <stdio.h>
#include <math.h>

int size(int a)
{
    int size = 0;
    while (a != 0)
    {
        a /= 10;
        size++;
    }
    return size;
}

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int karatsuba(int a, int b)
{
    if (a < 10 && b < 10)
        return a * b;

    int m = max(size(a), size(b));
    int m2 = m/2;

    int high1 = a / ((int) pow(10, m2));
    int low1 = a % ((int) pow(10, m2));
    int high2 = b / ((int) pow(10, m2));
    int low2 = b % ((int) pow(10, m2));

    int z0 = karatsuba(low1, low2);
    int z1 = karatsuba((low1 + high1), (low2 + high2));
    int z2 = karatsuba(high1, high2);
    
    return (z2 * ((int)pow(10, (m2 * 2)))) + ((z1 - z2 - z0) * ((int)pow(10, m2))) + z0;
}

int main()
{
    int a, b;
    scanf ("%d %d", &a, &b);
    printf("%d * %d = %d\n", a, b, karatsuba(a, b));
    return 0;
}
