//This program is for josephus permutation in C language using Linked List and dynamic memory allocation
//Josephus permutation is a problem in which in a given list of numbers ,we give a start position and the skip count 
//so after every skip number the number is deleted and then this process is continued till the last number in the list is obtained
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* link;
};
typedef struct node node_t;


struct singly_list
{
	node_t* head;
	int no_Of_Nodes;
};
typedef struct singly_list slist_t;
void initialize_List(slist_t*);
int josephus_survivor(slist_t*, int, int);
int main()
{
	slist_t l;
	initialize_List(&l);
	int step;
	int pos;
	int ele;
  printf("Enter the no of steps to be skipped and position\n");	
	scanf("%d%d", &step, &pos);
	printf("%d\n",josephus_survivor(&l, step, pos));
  return 0;
}
void initialize_List(slist_t* list)
{
	list -> head = NULL;
	list -> no_Of_Nodes = 0;
}

node_t* create_Node(int data)
{
	node_t* temp = (node_t*)malloc(sizeof(node_t));
	temp -> data = data;
	temp -> link = NULL;

	return temp;
}

int josephus_survivor(slist_t* list, int skip, int pos)
{
	if(list -> head == NULL)
	{
		return -1;
	}
	else
	{
		node_t* curr = list -> head;
		node_t* prev = NULL;
		int count = 0;
		//while(curr -> link != curr)
		while(count != pos)
		{
			prev = curr;
			curr = curr -> link;
			count++;
		}
		while(list -> no_Of_Nodes != 1) 
		{
			for(int i = 0; i < skip; ++i)
			{
				prev = curr;
				curr = curr -> link;
			}
			prev -> link = curr -> link;
			free(curr);
			curr = prev -> link;
			--list -> no_Of_Nodes;
		}
		list -> head = curr;
		return curr -> data;
	}

}
