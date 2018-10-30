#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int isSorted(int *v, int size)
{
    int i;
    for (i = 0; i < size - 1; i++)
        if (v[i] > v[i+1])
            return 0;
    return 1;
}

void bogoSort(int *v, int size)
{
    int i, aux, r;
    while (!isSorted(v, size))
    {
        for (i = 0; i < size; i++)
        {
            r = rand() % size;
            aux = v[i];
            v[i] = v[r];
            v[r] = aux;
        }
    }
}

int main()
{
    srand(time(NULL));
    int v[8] = {5, 8, 2, 1, 6, 4, 3, 7};

    bogoSort(v, 8);
    int i;
    for (i = 0; i < 8; i++)
        printf("%d ", v[i]);
    printf("\n");
    return 0;
}
