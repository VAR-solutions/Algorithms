// insert at beginning takes o(1) time and insert at the end takes o(n) time so we use insert at beginning in stack implementation of linkedlist.
#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

class stack {
    private:
        node* top;
    public:
        stack() {
            top = NULL;
        }
        
        void push(int x) {
            node* newnode = new node;
            newnode->data = x;
            cout << "pushed " << newnode->data << endl;
            if(top == NULL)
                top = newnode;
            else
                newnode->next = top;
                top = newnode;
        }
        
        void pop() {
            node* temp;
            if(top == NULL)
                cout << "Underflow" << endl;
            else {
                temp = top;
                cout << "popped " << temp->data << endl;
                top = temp->next;
                delete(temp);
            }
        }
};

int main()
{
    stack s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
}

//output:
// pushed 10
// pushed 20
// pushed 30
// pushed 40
// pushed 50
// popped 50
// popped 40
// popped 30
// popped 20
// popped 10
// Underflow
// Underflow