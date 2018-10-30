#include <stdio.h>
#include <stdlib.h>

struct QNode
{
    int data;
    struct QNode *next;
};

typedef struct QNode QNode;

void enqueue(QNode **q, int data)
{
    QNode *n = malloc(sizeof(QNode));
    n->data = data;
    n->next = NULL;
    if (*q == NULL)
    {
        *q = n;
    }
    else
    {
        QNode *ptr = *q;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = n;
    }
    printf("%d queued in the queue.\n", data);
}

void dequeue(QNode **q)
{
    if (*q == NULL)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        QNode *temp = *q;
        *q = (*q)->next;
        printf("%d dequeued from the queue.\n", temp->data);
        free(temp);
    }
}

int peek(QNode *q)
{
    if (q == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        return q->data;
    }
}

void display(QNode *q)
{
    QNode *ptr = q;
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
    QNode *q = NULL;
    int c = 0;
    printf("Enter 1 to enqueue elements in queue.\nEnter 2 to dequeue element from the queue.\nEnter 3 to peek topmost element in queue.\nEnter 4 to display content of the queue.\n");
    scanf("%d", &c);
    do
    {
        switch (c)
        {
        case 1:
            printf("Enter element to be enqueued: ");
            int n = 0;
            scanf("%d", &n);
            enqueue(&q, n);
            break;
        case 2:
            dequeue(&q);
            break;
        case 3:
            printf("%d\n", peek(q));
            break;
        case 4:
            display(q);
            break;
        default:
            printf("Invalid input.\n");
        }
        scanf("%d", &c);
    } while (c != -1);
    return 0;
}