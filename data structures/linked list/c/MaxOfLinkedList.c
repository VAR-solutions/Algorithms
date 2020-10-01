#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

void Create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

int Max(struct Node *p)
{
    int max = INT_MIN;
    while (p != NULL)
    {
        if (p->data > max)
            max = p->data;
        p = p->next;
    }
    return max;
}

int Min(struct Node *p)
{
    int min = INT_MAX;
    while (p != NULL)
    {
        if (p->data < min)
            min = p->data;
        p = p->next;
    }
    return min;
}

int RMax(struct Node *p)
{
    int x = 0;
    if (p == 0)
        return INT_MIN;
    x = RMax(p->next);
    if (x > p->data)
        return x;
    else
        return p->data;
}
int main()
{
    int A[] = {3, 5, 7, 10, 15, 8, 12, 2};
    Create(A, 8);
    printf("Maximum Number is : %d \n", RMax(first));
    printf("Minimum Number is : %d ", Min(first));

    return 0;
}

// Output :
// Maximum Number is : 15
// Minimum Number is : 2

// Iterative
// Time : O(n), Space O(1)

// Recursive
// Time : O(n), Space(n)
