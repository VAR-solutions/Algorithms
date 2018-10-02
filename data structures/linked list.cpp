#include<bits/stdc++.h>
#include<iostream> //Replaced iostream.h with iostream
using namespace std;

using namespace std;
void insert_beg();   //singly linked list insertion at beginning
void insert_end();   // singly linked list insertion at end
void insert_ind();   //singly linked list insertion at specific index
void del_beg();      //singly linked list deletion from beginning
void del_end();      //singly linked list deletion at end
void del_ind();      //singly linked list deletion at specific index
void rev();          // reverse of a singly linked list
void insert_beg_d(); // doubly linked list insertion at beginning
void insert_end_d(); // doubly linked list insertion at end
void insert_ind_d(); // doubly linked list insertion at specific index
void del_beg_d();    //doubly linked list deletion from beginning
void del_end_d();    //doubly linked list deletion from end
void del_ind_d();    //doubly linked list deletion from beginning
void rev_d();        //reverse of a doubly linked list
void printi();       //function to print singly linked list
void printi_d();     //function to print doubly linked list
void singly();       //driver function for singly linked list
void doubly();       //driver function for doubly linked list
struct node
{
    int data;
    node *next;
    node *prev;
};

node *head = NULL;

void insert_beg_d()
{
    int data;
    cout << "\nEnter data: ";
    cin >> data;
    if (head == NULL)
    {
        node *temp = new node;
        temp->data = data;
        temp->next = NULL;
        temp->prev = NULL;
        head = temp;
    }
    else
    {
        node *temp = new node;
        temp->data = data;
        temp->next = head;
        temp->prev = NULL;
        head = temp;
    }
    getchar();;
    doubly();
}
void insert_end_d()
{
    int data;
    cout << "\nEnter data: ";
    cin >> data;

    if (head == NULL)
    {
        node *temp = new node;
        temp->data = data;
        temp->next = NULL;
        temp->prev = NULL;
        head = temp;
    }
    else
    {
        node *temp1;
        temp1 = head;
        while (temp1->next != NULL)
        {
            temp1 = temp1->next;
        }

        node *temp = new node;
        temp->data = data;
        temp->next = NULL;
        temp->prev = temp1;
        temp1->next = temp;
    }
    getchar();;
    doubly();
}
void insert_ind_d()
{
    int data;
    int index;
    cout << "\nData to be inserted: ";
    cin >> data;
    cout << "Index(start 1): ";
    cin >> index;
    node *temp;
    temp = head;
    int len = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    if (index > len)
    {
        cout << "\nNot enough nodes\n";
    }
    else
    {
        int i = 0;
        node *temp1;
        temp1 = head;

        for (int i = 1; i < index - 1; i++)
        {
            temp1 = temp1->next;
        }
        node *temp4 = new node;
        temp4->data = data;
        node *temp3;
        temp3 = temp1->next;
        temp1->next = temp4;
        temp4->next = temp3;
        temp4->prev = temp3->prev;
        temp3->prev = temp4;
        cout << "Data inserted at index " << index << " succesfully!!\n";
    }

    getchar();;
    singly();
}
void del_beg_d()
{
    node *temp;
    if (head == NULL)
    {
        cout << "\nNot enough nodes!!\n";
    }
    else
    {
        temp = head;
        head = head->next;
        free(temp);
        head->prev = NULL;
    }
    cout << "\nElement deleted succesfully!!\n";
    getchar();;
    doubly();
}
void del_end_d()
{
    node *temp;

    int l = 0;
    temp = head;

    if (head == NULL)
    {
        cout << "\nNot enough nodes!!\n";
    }
    else
    {
        node *temp2;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp2 = temp->prev;
        free(temp);
        temp2->next = NULL;
    }
    cout << "\nElement deleted succesfully!!\n";
    getchar();;
    doubly();
}
void del_ind_d()
{
    int ind;
    cout << "\nEnter the index: ";
    cin >> ind;
    node *temp;
    temp = head;
    node *temp2;
    node *temp1;
    temp1 = head;
    int l = 0;
    while (temp1 != NULL)
    {
        temp1 = temp1->next;
        l++;
    }
    if (ind <= l)
    {

        for (int i = 1; i < ind - 1; i++)
        {
            temp = temp->next;
        }
        node *temp3;
        temp2 = temp->next;
        temp3 = temp2->next;
        temp->next = temp2->next;
        temp3->prev = temp;
        free(temp2);
        cout << "\nElement deleted succesfully!!";
    }
    else
    {
        cout << "\nNot enough nodes to delete";
    }
    getchar();;
    doubly();
}

void rev_d()
{

    node *temp2 = head;
    node *temp1 = NULL;
    node *temp = NULL;
    while (temp2)
    {
        temp1 = temp2->next;
        temp2->next = temp;
        temp2->prev = temp1;
        temp = temp2;
        temp2 = temp1;
    }
    head = temp;

    cout << "\nString reversed succesfully";
    getchar();;
    doubly();
}
void printi_d()
{
    node *temp;
    temp = head;
    if (head == NULL)
    {
        cout << "\n\t\tLIST EMPTY!!\n";
    }
    else
    {

        while (temp != NULL)
        {
            cout << temp->data << "<->";
            temp = temp->next;
        }
    }
    getchar();;
    doubly();
}

void insert_beg()
{
    int data;
    cout << "\nEnter data: ";
    cin >> data;
    if (head == NULL)
    {
        node *temp = new node;
        temp->data = data;
        temp->next = NULL;
        head = temp;
    }
    else
    {
        node *temp = new node;
        temp->data = data;
        temp->next = head;
        head = temp;
    }
    getchar();;
    singly();
}
void insert_end()
{
    int data;
    cout << "\nEnter data: ";
    cin >> data;

    if (head == NULL)
    {
        node *temp = new node;
        temp->data = data;
        temp->next = NULL;
        head = temp;
    }
    else
    {
        node *temp1;
        temp1 = head;
        while (temp1->next != NULL)
        {
            temp1 = temp1->next;
        }

        node *temp = new node;
        temp->data = data;
        temp->next = NULL;
        temp1->next = temp;
    }
    getchar();;
    singly();
}
void insert_ind()
{
    int data;
    int index;
    cout << "\nData to be inserted: ";
    cin >> data;
    cout << "Index(start 1): ";
    cin >> index;
    node *temp;
    temp = head;
    int len = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    if (index > len)
    {
        cout << "\nNot enough nodes\n";
    }
    else
    {
        int i = 0;
        node *temp1;
        temp1 = head;

        for (int i = 1; i < index - 1; i++)
        {
            temp1 = temp1->next;
        }
        node *temp4 = new node;
        temp4->data = data;
        node *temp3;
        temp3 = temp1->next;
        temp1->next = temp4;
        temp4->next = temp3;
        cout << "Data inserted at index " << index << " succesfully!!\n";
    }

    getchar();;
    singly();
}

void del_beg()
{
    node *temp;
    if (head == NULL)
    {
        cout << "\nNot enough nodes!!\n";
    }
    else
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    cout << "\nElement deleted succesfully!!\n";
    getchar();;
    singly();
}
void del_end()
{
    node *temp;
    node *temp1;
    int l = 0;
    temp = head;
    temp1 = head;
    if (head == NULL)
    {
        cout << "\nNot enough nodes!!\n";
    }
    else
    {
        node *temp2;

        while (temp->next != NULL)
        {
            temp = temp->next;
            l++;
        }
        while (l - 1 > 0)
        {
            temp1 = temp1->next;
            l--;
        }
        temp1->next = NULL;
    }
    cout << "\nElement deleted succesfully!!\n";
    getchar();;
    singly();
}
void del_ind()
{
    int ind;
    cout << "\nEnter the index: ";
    cin >> ind;
    node *temp;
    temp = head;
    node *temp2;
    node *temp1;
    temp1 = head;
    int l = 0;
    while (temp1 != NULL)
    {
        temp1 = temp1->next;
        l++;
    }
    if (ind <= l)
    {

        for (int i = 1; i < ind - 1; i++)
        {
            temp = temp->next;
        }
        temp2 = temp->next;
        temp->next = temp2->next;
        free(temp2);
        cout << "\nElement deleted succesfully!!";
    }
    else
    {
        cout << "\nNot enough nodes to delete";
    }
    getchar();;
    singly();
}
void rev()
{
    node *temp = NULL;
    node *temp1 = NULL;
    node *temp2 = NULL;
    node *temp4;
    int l = 0;
    temp4 = head;
    temp2 = head;
    /*while(temp!=NULL)
  {
      temp4 = temp4->next;
      l++;
  }*/
    while (temp2 != NULL)
    {
        temp = temp1;
        temp1 = temp2;
        temp2 = temp2->next;
        temp1->next = temp;
    }
    head = temp1;

    cout << "reversed succesfully!!\n";
    getchar();;
    singly();
}
void printi()
{
    node *temp;
    temp = head;
    if (head == NULL)
    {
        cout << "\n\t\tLIST EMPTY!!\n";
    }
    else
    {

        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
    }
    getchar();;
    singly();
}
void singly()
{
    system("cls");
    cout << "\n\t\t Singly Linked List\n";
    int x;
    cout << "Select the operation: \n";
    cout << "1. Insert @beginning\n2. Insert @end\n3. Insert @index\n4. Delete @beginning\n5. Delete @end\n6. Delete @index\n7. Reverse\n8. Print the list\n";
    cout << "Your choice: ";
    cin >> x;
    switch (x)
    {
    case 1:
        insert_beg();
        break;
    case 2:
        insert_end();
        break;
    case 3:
        insert_ind();
        break;
    case 4:
        del_beg();
        break;
    case 5:
        del_end();
        break;
    case 6:
        del_ind();
        break;
    case 7:
        rev();
        break;
    case 8:
        printi();
        break;
    default:
        cout << "\nInvalid choice";
        break;
    }
}
void doubly()
{
    system("cls");
    cout << "\n\t\t DOUBLY Linked List\n";
    int x;
    cout << "Select the operation: \n";
    cout << "1. Insert @beginning\n2. Insert @end\n3. Insert @index\n4. Delete @beginning\n5. Delete @end\n6. Delete @index\n7. Reverse\n8. Print the list\n";
    cout << "Your choice: ";
    cin >> x;
    switch (x)
    {
    case 1:
        insert_beg_d();
        break;
    case 2:
        insert_end_d();
        break;
    case 3:
        insert_ind_d();
        break;
    case 4:
        del_beg_d();
        break;
    case 5:
        del_end_d();
        break;
    case 6:
        del_ind_d();
        break;
    case 7:
        rev_d();
        break;
    case 8:
        printi_d();
        break;
    default:
        cout << "\nInvalid choice";
        break;
    }
}
int main()
{

    system("cls");
    cout << "Choose the type of list: ";
    cout << "\n1. Singly linked list\n2. Doubly linked list\n";
    cout << "Your choice:  ";
    int a;
    cin >> a;
    switch (a)
    {
    case 1:
        singly();
        break;
    case 2:
        doubly();
        break;
    default:
        cout << "Invalid choice\n";
        break;
    }

    return 0;
}
