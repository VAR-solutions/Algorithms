#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

class linkedlist {
    private:
    node *head;
    public:
    linkedlist() {
        head = NULL;
    }
    
    node* getHead() {
    return head;
    }
    
    
    void insert(int data) {
        node* temp = new node;
        temp->data = data;
        temp->next = head;
        head = temp;
    }
    
    
    void display() {
        node* temp = head;
        cout << "List is :";
        while(temp!= NULL) {
            int tempo = temp->data;
            cout << tempo << " ";
            temp = temp->next;
        }
        cout << endl;
    }
     
    
    void removeduplicates() { 
        node *temp1, *temp2, *repeat; 
        temp1 = head; 
        while (temp1 != NULL && temp1->next != NULL) { 
            temp2 = temp1; 
            while (temp2->next != NULL) { 
                if (temp1->data == temp2->next->data) { 
                    repeat = temp2->next; 
                    temp2->next = temp2->next->next; 
                    delete(repeat); 
                } 
                else
                    temp2 = temp2->next; 
            } 
            temp1 = temp1->next; 
        } 
        } 

};

int main()
{
   int m, n;
   node* temp;
   linkedlist l1; 
      l1.insert(3);
      l1.insert(5);
      l1.insert(11);
      l1.insert(2);
      l1.insert(11);
      l1.insert(2);
      l1.insert(10);
      l1.insert(4);
      l1.insert(11);
      l1.insert(4);
      l1.insert(4);
	  
      l1.display();
	  
      l1.removeduplicates(); 
	  
      l1.display();

      return 0;
}

// Output :
// List is :4 4 11 4 10 2 11 2 11 5 3 
// List is :4 11 10 2 5 3 



