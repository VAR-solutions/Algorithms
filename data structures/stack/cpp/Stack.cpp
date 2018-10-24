#include<iostream>

using namespace std;

struct node
{
    int info;
    node *link;
};

class stak
{
    node *ptr,*top = NULL,*a;
    int pos = 0 , x, item;
    char ch='y';
public:
    void push();
    void pop();
    void show();
    void search();
};

void stak::push()
{
    ch = 'y';
    while(ch == 'y' || ch == 'Y')
    {
        cout<<"\nEnter element : ";
        cin>>x;
        ptr = new node;
        ptr -> info = x;
        ptr -> link = NULL;
        if(top == NULL)
        {
            top = ptr;                         
        }    
        else
        {
            ptr -> link = top;
            top = ptr;
        }
        cout<<"\nWant to enter more elements?(y/n)...";
        cin>>ch;
    }
}

void stak::pop()
{
    ch = 'y';
    while(ch == 'Y' || ch == 'y')
    {
        if(top == NULL)
        {
            cout<<"\nUNDERFLOW!";
            break;
        }
        a = top;
        top = top -> link;
        cout<<a->info<<" Deleted successfullly!\n ";
        delete(a);
        pos -= 1;   
        cout<<"\nWant to delete more?(y/n)...";
        cin>>ch;
    }
}

void stak::show()
{
    pos = 0;
    if(top == NULL)
    {
        cout<<"\nThe list is empty!";
        return;
    }
    cout<<"\nThe List is : ";
    while(top != NULL)
    {
        cout<<top->info <<"--> ";
        top = top -> link;
        pos++;
    }
}

void stak::search()
{
    int tmp;
    ch ='y';
    while(ch == 'y' || ch== 'Y')
    {
        tmp = pos;
        cout<<"\nEnter element you want to search  : ";
        cin>>item;
        ptr = top;
        while( ptr != NULL)
        {
            if(item == ptr -> info)
            {
                cout<<"\nElement found at pos : "<<tmp;
                break;
            }
            tmp -= 1;
            ptr = ptr -> link;
        }
        if(ptr == NULL)
            cout<<"\nElement not found!";
        cout<<"\nWant to search any other element ?(y/n)...";
        cin>>ch;
    }
}

int main()
{
    int choice;
    stak o;
    while(1)
    {
         cout<<"\n\tMENU\n1.Push\n2.Pop \n3.Show\n4. Search\n5. Exit";
         cout<<"\nEnter your choice : ";
         cin>>choice;
         switch (choice)
         {
             case 1 :   o.push();
                        break;
            case 2 :    o.pop();
                        break;
            case 3 :    o.show();
                        break;
            case 4 :    o.search();
                        break;
            case 5 :    exit(0);
            default:    cout<<"\nInvalid choice!";
                        break; 
        }
    }
    return 0; 
}

    
