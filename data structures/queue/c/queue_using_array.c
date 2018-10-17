#include <stdio.h>
#include <stdlib.h>

#define MAX 500

struct Queue
{
    int size;
    int *a;
    int front;
    int rear;
};

typedef struct Queue queue;

queue *createQueue()
{
    queue *q = malloc(sizeof(queue));
    q->size = 0;
    q->front = 0;
    q->rear = 0;
    q->a = malloc(MAX * sizeof(int));
}

int isEmpty(queue *q)
{
    if (q->size == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(queue *q)
{
    if (q->size == MAX)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(queue *q, int n)
{
    if (isFull(q))
    {
        printf("Queue is full.\n");
    }
    else
    {
        (q->rear)++;
        q->a[q->rear] = n;
        q->size++;
        printf("%d enqueued in the queue.\n", n);
    }
}

void dequeue(queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("%d dequeued from the queue.\n", q->a[++q->front]);
        q->size--;
    }
}

int peek(queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty.\n");
    }
    else
    {
        return q->a[q->front];
    }
}

void display(queue *q)
{
    int i = 0;
    for (i = q->front + 1; i < q->rear + 1; i++)
    {
        printf("%d\t", q->a[i]);
    }
    printf("\n");
}

int main()
{
    queue *q = createQueue();
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
            enqueue(q, n);
            break;
        case 2:
            dequeue(q);
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