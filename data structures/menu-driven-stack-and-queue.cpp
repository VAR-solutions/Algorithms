#include <iostream>
#include <stdlib.h>


using namespace std;
void stck();
void que();
void stck_list();
void que_list();
void stck_ins_arr();
void stck_del_arr();
void stck_print();
void que_ins_arr();
void que_del_arr();
void que_print();
void stck_ins_list();
void stck_del_list();
void stck_print_list();
void que_ins_list();
void que_del_list();
void que_print_list();
int top = -1;
int st[100];
int fron = -1;
int endi = -1;
int q[100];
struct node
{
    int data;
    node *next;
};
node *head = NULL;
void stck_ins_arr()
{
    system("cls");
    int data;
    cout << "Enter the data: ";
    cin >> data;
    if (top == -1)
    {
        top++;
        st[top] = data;
    }
    else
    {
        top++;
        st[top] = data;
    }
    cout << "\nElement inserted succesfully\n";
    getchar();
    stck();
}

void stck_del_arr()
{
    system("cls");
    if (top == -1)
    {
        cout << "No elemnts found to delete\n";
    }
    else
    {
        top--;
        cout << "\nElement deleted succesfully\n";
    }
    getchar();
    stck();
}
void stck_print()
{
    system("cls");
    cout << "\n\n\n\t\tThe Representation of stack is as follows\n\n";

    for (int i = top; i >= 0; i--)
    {
        if (i == top)
        {
            cout << "\t\t\t" << st[i] << "<-"
                 << "\n"
                 << "\t\t\t-"
                 << "\n";
        }
        else
        {

            cout << "\t\t\t" << st[i] << "\n"
                 << "\t\t\t-"
                 << "\n";
        }
    }
    getchar();
    stck();
}
void stck()
{
    system("cls");
    cout << "\n\t\t STACK AS ARRAY\n";
    cout << "Choose any option\n";
    cout << "\n1. Insert\n2. Delete\n3. Print\n";
    int n;
    cin >> n;
    switch (n)
    {
    case 1:
        stck_ins_arr();
        break;
    case 2:
        stck_del_arr();
        break;
    case 3:
        stck_print();
        break;
    default:
        cout << "\nInvalid choice\n";
        break;
    }
}

void que_ins_arr()
{
    system("cls");
    int data;
    cout << "\nEnter data to be inserted: ";
    cin >> data;
    if (fron == -1)
    {
        endi = fron = 0;

        q[fron] = data;
    }
    else
    {
        endi++;
        q[endi] = data;
    }

    cout << "\nElement inserted succesfully\n";

    getchar();
    que();
}
void que_del_arr()
{
    system("cls");

    if (fron == -1)
    {
        cout << "\nNot enough elements to delete\n";
    }
    else
    {
        fron++;
        cout << "\nElement deleted succesfully\n";
    }

    getchar();
    que();
}
void que_print()
{
    system("cls");
    cout << "\n\n\n\t\tThe Representation of queue is as follows\n\n";
    cout << "\t\t\t\t";
    for (int i = endi; i >= fron; i--)
    {
        cout << q[i] << " | ";
    }

    getchar();
    que();
}
void que()
{
    system("cls");
    cout << "\n\t\t QUEUE AS ARRAY\n";
    cout << "Choose any option\n";
    cout << "\n1. Insert\n2. Delete\n3. Print\n";
    int n;
    cin >> n;
    switch (n)
    {
    case 1:
        que_ins_arr();
        break;
    case 2:
        que_del_arr();
        break;
    case 3:
        que_print();
        break;
    default:
        cout << "\nInvalid choice\n";
        break;
    }
}
void stck_ins_list()
{
    system("cls");
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
    cout << "\nElement insereted successfully\n";
    getchar();
    stck_list();
}
void stck_del_list()
{
    system("cls");
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
    getchar();
    stck_list();
}
void stck_print_list()
{
    system("cls");
    node *temp;
    temp = head;
    if (head == NULL)
    {
        cout << "\n\t\tLIST EMPTY!!\n";
    }
    else
    {

        cout << "\n\n\n\t\tThe Representation of stack(linked list) is as follows\n\n";
        int i = 0;
        while (temp != NULL)
        {

            cout << "\t\t\t" << temp->data << "\n"
                 << "\t\t\t-"
                 << "\n";
            temp = temp->next;
        }
    }
    getchar();
    stck_list();
}

void stck_list()
{
    system("cls");
    cout << "\n\t\t STACK AS LINKED LIST\n";
    cout << "Choose any option\n";
    cout << "\n1. Insert\n2. Delete\n3. Print\n";
    int n;
    cin >> n;
    switch (n)
    {
    case 1:
        stck_ins_list();
        break;
    case 2:
        stck_del_list();
        break;
    case 3:
        stck_print_list();
        break;
    default:
        cout << "\nInvalid choice\n";
        break;
    }
}
void que_ins_list()
{
    system("cls");
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
    cout << "\nElement inserted succesfully\n";
    getchar();
    que_list();
}
void que_del_list()
{
    system("cls");
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
    getchar();
    que_list();
}
void que_print_list()
{
    system("cls");
    node *temp;
    temp = head;
    if (head == NULL)
    {
        cout << "\n\t\tLIST EMPTY!!\n";
    }
    else
    {

        cout << "\n\n\n\t\tThe Representation of queue is as follows\n\n";
        cout << "\t\t\t\t";
        while (temp != NULL)
        {
            cout << temp->data << " | ";
            temp = temp->next;
        }
    }
    getchar();
    que_list();
}

void que_list()
{
    system("cls");
    cout << "\n\t\t QUEUE AS LINKED LIST\n";
    cout << "Choose any option\n";
    cout << "\n1. Insert\n2. Delete\n3. Print\n";
    int n;
    cin >> n;
    switch (n)
    {
    case 1:
        que_ins_list();
        break;
    case 2:
        que_del_list();
        break;
    case 3:
        que_print_list();
        break;
    default:
        cout << "\nInvalid choice\n";
        break;
    }
}
int main()
{

    cout << "\nYou want to work with: ";
    cout << "\n1. Stack(as array)\n2. Queue(as array)\n3. Stack(as linked list)\n4. Queue(as linked list)\n";
    cout << "Enter choice: ";
    int n;
    cin >> n;
    switch (n)
    {
    case 1:
        stck();
        break;
    case 2:
        que();
        break;
    case 3:
        stck_list();
        break;
    case 4:
        que_list();
        break;
    default:
        cout << "Invalid Choice";
        break;
    }
    return 0;
}
