#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node
{
    int num;
    struct Node *next;
    struct Node *prev;
};

typedef struct Node UInt;

void insert(UInt **head, int x)
{
    UInt *n = malloc(sizeof(UInt));
    n->num = x;
    n->next = NULL;
    UInt *ptr = *head;
    if (*head == NULL)
    {
        *head = n;
        return;
    }
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = n;
    n->prev = ptr;
}

multiply(UInt *head, int x)
{
    int c = 0;
    UInt *p = head;
    while (p != NULL)
    {
        int t = p->num;
        int product = t * x + c;
        p->num = product % 10;
        c = product / 10;
        p = p->next;
    }
    while (c)
    {
        insert(&head, c % 10);
        c = c / 10;
    }
}

void exp(int x)
{
    UInt *head = malloc(sizeof(UInt));
    head->num = x;
    head->next = NULL;
    head->prev = NULL;
    for (int i = 1; i < x; i++)
    {
        multiply(head, x);
    }
    UInt *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    while (p != NULL)
    {
        printf("%d", p->num);
        p = p->prev;
    }
    printf("\n");
}

int main()
{
    int n = 0;
    printf("Enter number: ");
    scanf("%d", &n);
    exp(n);
    return 0;
}