#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node *prev;
    int data;
    struct Node *nxt;
};

struct Node *head = NULL;

void insertAtHead(int x){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    
    temp->data  = x;
    
    if(head == NULL){
        temp->prev = head;
        temp->nxt = NULL;  
    } else {
        temp->prev = head->prev;
        temp->nxt = head;
        head->prev = temp;
    }    
    head = temp;
}

void insertAtTail(int x){

    if(head == NULL){
        struct Node *temp2;
        temp2->data = x;
        temp2->prev = head;
        temp2->nxt = NULL;  
        head = temp2;
    }
    else
    {
        struct Node *temp1 = (struct Node*)malloc(sizeof(struct Node));
        temp1->data = x;
        temp1->nxt = NULL;

        struct Node *temp;
        temp = head;

        //traversal till end
        while(temp->nxt != NULL ){
            temp = temp->nxt;
        }
        temp->nxt = temp1;
        temp1->prev = temp;
    }
}

void print(){
    struct Node *temp ;
    temp = head;
    printf("\n");
    while ((temp != NULL)){
        printf("%d ",temp->data);
        temp = temp->nxt;
    }
    
}

void revprint(){
    struct Node *temp;
    temp = head;
    //traversal till end
    while(temp->nxt != NULL)temp = temp->nxt;
    printf("\n");
    while(temp != NULL){
        printf("%d ",temp->data);
        temp  = temp->prev;
    }
}

int main(){
    insertAtHead(5);print();revprint();
    insertAtTail(11);print();revprint();
    insertAtTail(75);print();revprint();
    insertAtHead(34);print();revprint();
    insertAtHead(89);print();revprint();
    insertAtHead(20);print();revprint();
    insertAtHead(45);print();revprint();
    insertAtTail(31);print();revprint();
    return 0;
}


