#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
    
    Node(int x){
        data=x;
        next=NULL;
        }
};

int SumOfElements(Node *head){
    
    int sum=0;
    struct Node *curr=head;
    while(curr!=NULL){
       sum+=curr->data;
       curr=curr->next;
    }
    return sum;
}

int main()
{
    int data,n;
    cin>>n;
    cin>>data;
    struct Node *head= new Node(data);
    struct Node *tail= head;
    for(int i=0;i<n-1;i++){
        cin>>data;
        tail->next=new Node(data);
        tail=tail->next;
    }
    cout<<SumOfElements(head)<<endl;
    return 0;
   
}
