#include<stdio.h>
#include<malloc.h>
struct node{
int info;
struct node *prev,*next;
};
struct node* start=NULL;
void insert()
{
struct node *n;
n=(struct node *)malloc(sizeof(struct node));
printf("enter the first info");
scanf("%d",&n->info);
n->prev=NULL;
n->next=NULL;
if(start==NULL)
start=n;
	else
	{
	start->prev=n;
	n->next=start;
	start=n;
	}
}
void delete()
{
struct node *r;
if(start==NULL)
printf("linkedlist is empty");
else
{
r=start;
start=start->next;
start->prev=NULL;
free(r);
}
}
void view()
{
struct node *t;
if(start==NULL)
printf("linked list is empty\n");
else{
t=start;
while(t->next!=NULL){
printf("%d ",t->info);
t=t->next;
}
if(t->next==NULL)
printf("%d",t->info);
printf("\n");
}
}
int main()
{
int ch;
while(1){
printf("1.insert\n2.delete\n3.view\n4.exit\n");
scanf("%d",&ch);
switch(ch)
{
case 1:insert();
break;
case 2:delete();
break;
case 3:view();
break;
case 4:return 1;
defult:printf("invalid choice\n");
}
}
return 0;
}
