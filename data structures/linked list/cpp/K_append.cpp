#include<iostream>
using namespace std;


class node{
public:
	long data;
	node*next;
	node(long d){
		data = d;
		next = NULL;
	}
};
void insertAtTail(node*&head, long n){
	
	while(n>0){
		int d;
		cin>>d;
		if(head == NULL){
			head = new node(d);
		}
		else{
			node*temp = head;
			while(temp->next!=NULL){
				temp = temp->next;
			}
			temp->next = new node(d);
		}
        n--;
	}
}


void print(node*head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
}
node* k_append(node *head,long k){
    node *oldHead = head;
    node *fast = head;
    node *slow = head;
    for(long i=0;i < k && fast->next!=NULL ;i++){
        fast = fast->next;
    }
    while(fast->next!=NULL && fast!=NULL){
        fast = fast->next;
        slow = slow->next;
    }
    node *newHead = slow->next;
    slow->next = NULL;
    fast->next = oldHead;
    return newHead;
}


int main(){
node*head = NULL;
long n,key;
cin>>n;
insertAtTail(head,n);
cin>>key;
key = key%n;
if(key==0)
	print(head);
else{
node* t = k_append(head,key);
print(t);
}
return 0;
}
