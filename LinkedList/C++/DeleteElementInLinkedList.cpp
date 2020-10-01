#include <iostream>
using namespace std;
struct Node {
   int data;
   struct Node *next;
};

struct Node* head = NULL;
struct Node* pr = NULL;

//struct Node* prev=NULL;
void insert(int new_data) {
    
    if(head==NULL){
        Node*new_node=new Node();
        new_node->data=new_data;
        new_node->next=NULL;
        head=new_node;
        pr=new_node;
    }
    else{
        cout<<"It is in else"<<endl;
        Node*new_node=new Node();
        new_node->data=new_data;
        new_node->next=NULL;
       pr->next=new_node;
        pr=new_node;
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

void length(){
     struct Node* ptr;
   ptr = head;
   int count=0;
   while (ptr != NULL) {
      count++;
       ptr = ptr->next;
   }
   cout<<count;
}


void search(int find)
{
    struct Node* ptr=head;
    int isfound=0;
    int index=0;
    while(ptr!=NULL){
        if(ptr->data==find)
        {
            cout<<index;
            return;
        }
       index++;
       ptr = ptr->next;
    }
    cout<<endl;
    cout<<-1<<endl;
    return;
    
    
}


void deleteIndex(int index)
{
    struct Node* ptr=head;
 int count=0;
 if(index==0)
 {
     
     head = ptr->next;
     delete ptr;
    // break;
 }
 else{
    
    
    
    while(ptr!=NULL){
      
      if(index-1==count)
      {
        
          struct Node* temp=ptr;
          ptr=ptr->next; //element to be deleted
          if (ptr->next==NULL)
          {
                temp->next=NULL;
                delete ptr ;
          }
          //ptr=ptr->next;
          else{
            temp->next=ptr->next;
          delete ptr;
          
         // cout<<"element Deleted"<<endl;
          }
          
         // delete ptr;
          break;
      }
      
       count++;
       ptr = ptr->next;
    }
 }
}

void addNodeatBegin(int new_data)
{
    Node*new_node=new Node();
    new_node->data=new_data;
    new_node->next=head;
    head=new_node;
}

int main() {
   insert(3);
      insert(5);
   insert(7);
   insert(8);
   insert(4);

  
  // addNodeatBegin(0);
   cout<<"The linked list is: ";
   display();
   cout<<endl;
   cout<<"Length of linked list:"<<endl;
   length();
   cout<<endl;
   search(7);
   deleteIndex(0);// delete first element 
  //deleteIndex(0);
   cout<<"Linked list is :"<<endl;
   display();
  
  // deleteIndex(2);
   
   cout<<endl;
   deleteIndex(1);// delete random element
   deleteIndex(3);// delete last element
   cout<<"Linked list is :"<<endl;
   display();
   //cout<<length()<<endl;
   return 0;
}