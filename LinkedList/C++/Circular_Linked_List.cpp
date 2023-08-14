#include<iostream>
using namespace std;
struct node{
    int data;
    node *next;
};


void printCircularList(node *start){
    node *temp=start;
    if(start!=NULL){
       cout<<temp->data<<endl;
       temp=temp->next;
       while(temp!=start){
          cout<<temp->data<<endl;
       temp=temp->next;
       }
    }
}
int main(){

    //LinkedList Data set..
    //creation of linked list
    node *head=new node();
    node *second=new node();
    node *third=new node();
    node *four=new node();
    node *five=new node();
    node *six=new node();
    node *seven=new node();
            
 //list1   
    head->data=5;
    head->next=second;
 //list2
    second->data=9;
    second->next=third;
 //list3
    third->data=7;
    third->next=four;
 //list4
    four->data=4;
    four->next=five;
 //list5
    five->data=6;
    five->next=six;
 //list6
    six->data=8;
    six->next=seven;
 //list7
    seven->data=10;
    seven->next=head;

//calling of function

    printCircularList(head);
}
