// SINGLE LINKED LIST IN C WITH INSERT DELETE AND PRINT FUNCTIONS

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

// head node depicting the start of the list
struct Node *head;


//function to print the list
void printList(){
    struct Node *temp = head;

    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

// Printing the list in reverse order
void printRevList(struct Node *p){

   if(p == NULL) return;
   printRevList(p->next);
   printf("%d ",p->data);

}

//creating an initial list
int create( int x){
    
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));

    temp->data = x; 
    
    // the head is pointed to the new node
    // the starting value is pushed to the last
    if(head != NULL){
       temp->next = head;
    } else{
       temp->next = NULL;
    }
    head = temp;
    
}

//inserting data at nth position of the exsisting list
int nInsert(int value, int pos){
   struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
   struct Node *temp1 = (struct Node*)malloc(sizeof(struct Node));

   temp1->data = value;
   temp1->next = NULL;

    //in case an empty list
   //special case for pos = 1
   if(pos == 1){
       temp1->next = head;
       head = temp1;
   }
   else{
        //traversal of list to the required point
        temp = head;
        for(int i = 1; i < pos-1; i++){
            temp = temp->next;
        }
        temp1 ->next = temp->next;
        temp->next = temp1;
   }
}

// deleting an exsisting node from the list
void delete(int val){

    struct Node *temp = head;

    // special case for pos = 1
    if(temp->data == val){
        head = temp->next;
        return;
    }

    while(temp != NULL){
        if(temp->next->data == val){
            temp->next = temp->next->next;
            return;
        }
        temp = temp->next;
    }
    printf("\nData not found in the list");
    return;
}

int main(){
    char ans;
    int x, n;
    head = NULL;

    //create a list
    printf("\nHow many no.'s?");
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        printf("\nEnter the number:");
        scanf("%d",&x);
        create(x);
    }

    printf("\nList created: \n");
    printList();
    printf("\nList in reversed Order: \n");
    printRevList(head);

    //Inserts at nth postion
    nInsert(2,3); //data,position
    nInsert(5,3);
    nInsert(3,2);
    nInsert(16,1);
    nInsert(23,4);

    printf("\nList after insertion of values: \n");
    printList();
    printf("\nList in reversed order after insertion: \n");
    printRevList(head);

    delete(3);
    delete(2);
    delete(16);
    printf("\nList after deletion:\n");
    printList();
    
    return 0;
}