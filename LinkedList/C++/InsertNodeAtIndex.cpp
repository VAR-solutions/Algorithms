#include <iostream>
using namespace std;
struct Node {
   int data;
   struct Node *next;
   struct Node *previous;
};

struct Node* head = NULL;
//struct Node* pr = NULL;

//struct Node* prev=NULL;
void insert(int new_data) {
    
    if(head==NULL){
        //cout<<"in if"<<endl;
        Node*new_node=new Node();
        new_node->data=new_data;
        new_node->next=NULL;
        new_node->previous=NULL;
        head=new_node;
       // pr=new_node;
    }
    else{
      // cout<<"in else"<<endl;
        Node*temp=new Node();
        temp=head;
        //int count=0;
        while(temp->next!=NULL)
        {
           // cout<<count;
            //count++;
            
            temp=temp->next;
        }
        
        Node*newNode=new Node();
        newNode->data=new_data;
        newNode->previous=temp;
        newNode->next=NULL;
        
        temp->next=newNode;
        
        
        
    
        //pr=new_node;
    }
    

}




void display() {
   struct Node* ptr;
   ptr = head;
   
   while (ptr != NULL) {
      cout<< ptr->data <<" ";
      ptr = ptr->next;
   }
}




void InsertAt(int index,int value)
{
    if(index==0)
    {
         Node*tempNode=new Node();
          
          tempNode->previous=NULL;
          tempNode->data=value;
          tempNode->next=head;
          head->previous=tempNode;
     //     head->next=NULL;
          
          head=tempNode;
          
          
     
     
     
     
    }

    else{
    
    cout<<"In insert at"<<endl;
    int count=0;
    Node*temp=new Node();
     temp=head;
    while(count!=index)
    {
        temp=temp->next;
        count++;
    }
    
    Node*newNode=new Node();
    newNode->data=value;
    newNode->previous=temp->previous;
    newNode->next=temp;
    temp->previous->next=newNode;
    temp->previous=newNode;
  }
    return;
    
    
    
    
    
}




int main() {
   insert(3);
   insert(1);
   insert(7);
   insert(2);
   insert(9);
 InsertAt(0,4);
   
 
   cout<<"Linked list is :"<<endl;
   display();
   //cout<<length()<<endl;
   return 0;
}
