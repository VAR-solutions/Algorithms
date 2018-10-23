#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
    int data;
    struct node *next;
};

struct node *start = NULL;

void create(int n){
    struct node *new_node, *current_node;
    new_node=(struct node*)malloc(sizeof(node));
    new_node->data=n;
    new_node->next=NULL;

    if(start==NULL){
            start=new_node;
            current_node=new_node;
    }else{
        current_node->next=new_node;
        current_node=new_node;
    }

}

void display(){
    struct node* temp=start;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

void reverse_linked_list(){
    struct node *prev=NULL, *current=start, *next=NULL;
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    start=prev;
    cout<<"\n";
    display();
}

int main(){
    create(2);
    create(27);
    create(22);
    create(21);
    create(25);
    display();
    reverse_linked_list();
}
