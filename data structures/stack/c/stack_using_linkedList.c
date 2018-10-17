#include <stdio.h>
#include <stdlib.h>

struct SNode
{
    int data;
    struct SNode *next;
};

typedef struct SNode SNode;

void push(SNode **top, int n)
{
    SNode *sNode = malloc(sizeof(SNode));
    sNode->next = *top;
    sNode->data = n;
    *top = sNode;
    printf("%d pushed to stack.\n", n);
}

void pop(SNode **top)
{
    if (*top == NULL)
    {
        printf("Underflow");
    }
    else
    {
        SNode *temp = *top;
        *top = (*top)->next;
        printf("%d popped from the stack.\n", temp->data);
        free(temp);
    }
}

int peek(SNode *top)
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        return top->data;
    }
}

void display(SNode *top)
{
    SNode *ptr = top;
    printf("Elements entered are: \n");
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main()
{
    SNode *s = NULL;
    int c = 0;
    printf("Enter 1 to push elements to stack.\nEnter 2 to pop elements from the stack.\nEnter 3 to peek topmost element in stack.\nEnter 4 to display content of the stack.\n");
    scanf("%d", &c);
    do
    {
        switch (c)
        {
        case 1:
            printf("Enter element to be pushed: ");
            int n = 0;
            scanf("%d", &n);
            push(&s, n);
            break;
        case 2:
            pop(&s);
            break;
        case 3:
            printf("%d\n", peek(s));
            break;
        case 4:
            display(s);
            break;
        default:
            printf("Invalid input");
        }
        scanf("%d", &c);
    } while (c != -1);
    return 0;
}