#include <iostream>
#include<stdlib.h>

using namespace std;
class Node{
public:
Node* next;
int data;
};

class cll{
public:
Node* head = new Node;
cll(){
head=NULL;
}
Node* createnode(int val);
void display();
void addeleatbeg(int val);
void addeleatlast(int val);
void deleleatbeg();
void deleleatlast();
void divideintotwo();
void exchangefirstandlastnode();
};


int main()
{
int value;
int i;
cll obj;
while(1){
 cout<<"\n\n1.ADD ELEMENT AT BEGINNING\n2.ADD ELEMENT AT THE LAST\n3.DISPLAY LIST\n4.DELETE AT BEG\n5.DELETE AT LAST\n6.DIVIDE IN TWO\n7.EXCHANGE FIRST AND LAST NODE\n8.EXIT\nChoose your Option : ";
 cin>>i;
switch(i){
case 1:
cout<<"\n\nEnter value you want to add : ";
cin>>value;
obj.addeleatbeg(value);
break;
case 2:
cout<<"\n\nEnter value you want to add : ";
cin>>value;
obj.addeleatlast(value);
break;
case 3:
obj.display();
break;
case 4:
obj.deleleatbeg();
break;
case 5:
obj.deleleatlast();
break;
case 6:
obj.divideintotwo();
break;
case 7:
obj.exchangefirstandlastnode();
break;
case 8:
exit(0);
break;
}
}
return 0;
}
//createnode function
Node* cll::createnode(int val){
Node* temp = new Node;
temp->data = val;
return temp;
}
//display function
void cll::display(){
if(head==NULL){
cout<<"\n\nBLANK LIST !\n\n";
return;
}else{
Node* ptr=new Node;
ptr = head;
do{
cout<<ptr->data<<" ";
ptr=ptr->next;
}while(ptr!=head);
}
}
//element at the beginning
void cll::addeleatbeg(int val){
Node* temp = createnode(val);
if(head==NULL){
head=temp;
temp->next = head;
cout<<"\n\nELEMENT ADDED !\n\n";
}else{
Node* ptr = new Node;
ptr = head;
while(ptr->next!=head){
ptr=ptr->next;
}
temp->next=head;
ptr->next = temp;
head = temp;

cout<<"\n\nELEMENT ADDED !\n\n";
}
}
//add element at last
void cll::addeleatlast(int val){
if(head==NULL){
addeleatbeg(val);
}else{
Node* temp = createnode(val);
Node* ptr = new Node;
ptr=head;
while(ptr->next!=head){
ptr=ptr->next;
}
ptr->next = temp;
temp->next = head;
cout<<"\n\nELEMENT ADDED !\n\n";
}
}
//delete element at beg
void cll::deleleatbeg(){
if(head==NULL){
cout<<"\n\nUNDERFLOW !\n\n";
return;
}else if(head->next==head){
head = NULL;
cout<<"\n\nELEMENT AT BEGINNING DELETED !\n\n";
return;
}
Node * ptr = new Node;
Node * preptr = new Node;
preptr=head;
do{
preptr=preptr->next;
}while(preptr->next!=head);
ptr=head;
head = ptr->next;
preptr->next = head;
delete ptr;
cout<<"\n\nELEMENT AT BEGINNING DELETED !\n\n";
}
//delete element at last
void cll::deleleatlast(){
if(head==NULL){
cout<<"\n\nUNDERFLOW !\n\n";
return;
}else if(head->next==head){
head = NULL;
cout<<"\n\nELEMENT AT LAST DELETED !\n\n";
return;
}
Node * preptr = new Node;
Node * ptr =new Node;
ptr=head;
do{
preptr =ptr;
ptr=ptr->next;
}while(ptr->next!=head);
preptr->next =head;
delete ptr;
cout<<"\n\nELEMENT AT LAST DELETED !\n\n";
}
//Divide list into 2 lists
void cll::divideintotwo(){
if(head==NULL){
cout<<"\n\nBLANK LIST!\n\n";
return;
}
Node* ptr = new Node;
ptr=head;
int coun = 1,h1,h2;
do{
coun++;
ptr=ptr->next;
}while(ptr->next!=head);
ptr=head;
if(coun%2==0){
h1=coun/2;
h2=h1;
}else{
h1 = coun/2+1;
h2 = coun/2;
}
cll ob1,ob2;
for(int i=1;i<=coun;i++){
if(i<=h1){
ob1.addeleatlast(ptr->data);
ptr=ptr->next;
}else{
ob2.addeleatlast(ptr->data);
ptr=ptr->next;
}
}
cout<<"\nFIRST HALF : ";
ob1.display();
cout<<"\n\n";
cout<<"\nSECOND HALF : ";
ob2.display();
cout<<"\n\n";
}
//exchange first and last node
void cll::exchangefirstandlastnode(){
if(head==NULL){
cout<<"\n\nBLANK LIST !\n\n";
return;
}
Node* prev=new Node;
Node* lastp = new Node;
Node* firstp = new Node;
firstp= head;
lastp=head;
while(lastp->next!=head){
prev=lastp;
lastp=lastp->next;
}
head = lastp;
lastp->next=firstp->next;
prev->next=firstp;
firstp->next = head;
cout<<"\n\nELEMENTS SWAPPED/EXCHANGED\n\n";
}
