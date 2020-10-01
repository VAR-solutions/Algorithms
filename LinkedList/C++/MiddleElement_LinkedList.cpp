#include<iostream>
using namespace std;
struct node{
    int data;
    node *next;
};
void printList(node *n){
   int cnt=0;
while(n!=NULL){
    cout<<n->data<<endl;
    n=n->next;
cnt++;
}
cout<<"NO of Element inside is :"<<cnt<<endl;
}

void printMiddleElement(node *head){
   node *slow=head;
   node *fast=head;
   if(head!=NULL){
      while(fast!=NULL && fast->next!=NULL){
         fast=fast->next->next;
         slow=slow->next;
      }
      cout<<"middle element is:"<<slow->data;
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
    seven->next=NULL;

//calling of function

    printMiddleElement(head);
}
