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


void addNodeatBegin(int new_data)
{
    Node*new_node=new Node();
    new_node->data=new_data;
    new_node->next=head;
    head=new_node;
}

int main() {
   insert(3);
   insert(1);
   insert(7);
   insert(2);
   insert(9);
   addNodeatBegin(0);
   cout<<"The linked list is: ";
   display();
   cout<<endl;
   cout<<"Length of linked list:"<<endl;
   length();
   cout<<endl;
   search(7);
   //cout<<length()<<endl;
   return 0;
}