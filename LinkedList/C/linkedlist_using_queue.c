#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node *list;
};
struct node *front = NULL;
struct node *rear = NULL;
void enqueue(int element);
void dequeue();
void display();
void main()
{
 int x, element;
 while(1)
{
 printf("Enter Choice-");
 printf("\n1)Enqueue\n2)Dequeue\n3)Display\n4)Exit\n");
 scanf("%d",&x);
 switch(x){
case 1: printf("Enter Element-");
scanf("%d", &element);
enqueue(element);
break;
case 2: dequeue();
break;
case 3: display();
 break;
case 4: exit(0);
default: printf("Choose a correct option!\n");
 }
 }
}
void enqueue(int element)
{
 struct node *new;
 new = (struct node*)malloc(sizeof(struct node));
 new->data = element;
 new->list = NULL;
 if(front == NULL)
 front = rear = new;
 else{
 rear->list = new;
 rear = new;
 }
 printf("\nElement inserted successfully!\n\n");
}
void dequeue()
{
 if(front == NULL)
 printf("Queue is Empty\n");
 else{
 struct node *new = front;
 front = front -> list;
 printf("\nDequeued Element-%d\n\n", new->data);
 free(new);
 }
}
void display()
{
 if(front == NULL)
 printf("\nQueue is Empty\n");
 else
{ printf("Elements in Queue are-");
 struct node *new = front;
 while(new->list != NULL){
printf("%d ",new->data);
new = new ->list;
 }
 printf("%d \n",new->data);
 }
}
