

//Importing libraries
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
 
//Declaring Node
struct node
{
    int data;
    struct node *next;
    struct node *prev;
}*begin, *end;
int index = 0;

//Declaring a Circular Doubly Linked List Class
class circular_dlist
{
    public:
        node *create_node(int);
        void insert_begin();
        void insert_end();
        void insert_position();
        void insert_before();
        void insert_after();
        void delete_begin();
        void delete_end();
        void delete_position();
        void show_list();
        
        circular_dlist()
        {
            begin = NULL;
            end = NULL;			
        }
};
 
//Menu driven main function
int main()
{
    int choice;
    circular_dlist clist;
    while (1)
    {
        cout<<"\n-----------------------"<<endl;
        cout<<"List of Operations:"<<endl;
        cout<<"-----------------------"<<endl;         
        cout<<"1.Insert at Beginning of List"<<endl;
        cout<<"2.Insert at End of List"<<endl;
        cout<<"3.Insert at specific positon"<<endl;
        cout<<"4.Insert before specific value of node"<<endl;
        cout<<"5.Insert after specific value of node"<<endl;
        cout<<"6.Delete from Beginning of List"<<endl;
        cout<<"7.Delete from End of List"<<endl;
        cout<<"8.Delete from specific position"<<endl;
        cout<<"9.Show List"<<endl;
        cout<<"10.Exit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            clist.insert_begin();
            break;
        case 2:
            clist.insert_end();
            break;   
        case 3:
            clist.insert_position();
            break; 
        case 4:
            clist.insert_before();
            break; 
        case 5:
            clist.insert_after();
            break;
        case 6:
            clist.delete_begin();
            break;
        case 7:
            clist.delete_end();
            break;
		case 8:
            clist.delete_position();
            break;
        case 9:
            clist.show_list();
            break;
        case 10:
            exit(1); 
        default:
            cout<<"Not a valid choice"<<endl;	
        }
    }
    return 0;
}
 
//Function for Creating a Node
node* circular_dlist::create_node(int info)
{
    index++;  
    struct node *tmp;
    tmp = new(struct node);
    tmp->data = info;
    tmp->next = NULL;
    tmp->prev = NULL;
    return tmp;
}

//Function to insert a node at the beginning
void circular_dlist::insert_begin()
{
    int info;
    cout<<endl<<"Enter Value of Node to be inserted: ";
    cin>>info;
    struct node *tmp;
    tmp = create_node(info);
    if (begin == end && begin == NULL)
    {    
        cout<<"List created and first element inserted!"<<endl;
        begin = end = tmp;
        begin->next = end->next = NULL;
        begin->prev = end->prev = NULL;
    }
    else
    {
        tmp->next = begin;
        begin->prev = tmp;
        begin = tmp;
        begin->prev = end;
        end->next = begin;
        cout<<"Node inserted"<<endl;
    }
}
 
//Function to insert a node at the end
void circular_dlist::insert_end()
{
    int info;    
    cout<<endl<<"Enter Value of Node to be inserted: ";
    cin>>info; 
    struct node *tmp;
    tmp = create_node(info);
    if (begin == end && begin == NULL)
    {
        cout<<"List created and first element inserted!"<<endl;
        begin = end = tmp;
        begin->next = end->next = NULL;    
        begin->prev = end->prev = NULL;
    }
    else
    {
        end->next = tmp;
        tmp->prev = end;
        end = tmp;
        begin->prev = end;
        end->next = begin;
    }
}

//Function to insert a node at a specific position by index
void circular_dlist::insert_position()
{    
    int info, pst, i;
    cout<<endl<<"Enter Value of Node to be inserted: ";
    cin>>info;
    cout<<endl<<"Enter Position where Node will be inserted: ";
    cin>>pst;
    struct node *tmp, *s, *p;
    tmp = create_node(info);
    if (begin == end && begin == NULL)
    {
        if (pst == 1)
        {
            begin = end = tmp;
            begin->next = end->next = NULL;    
            begin->prev = end->prev = NULL;
        }
        else
        {
            cout<<"Index inserted is out of range"<<endl;
            index--;
            return;
        }
    }  
    else
    {
        if (index < pst)
        {
             cout<<"Index inserted is out of range"<<endl;
             index--;
             return;   		
        }
        s = begin;		
        for (i = 1;i <= index;i++)
        {
            p = s;
            s = s->next;
            if (i == pst - 1)
            {
                p->next = tmp;
                tmp->prev = p;
                tmp->next = s;
                s->prev = tmp;
                cout<<"Node inserted"<<endl;
                break;
            }
        }
    }
}

//Function to insert a node before a node containing a specific value
void circular_dlist::insert_before()
{
	int pst = 0, info, info1, i;
    bool cond = false;
    struct node *s;
    if (begin == end && begin == NULL)
    {
        cout<<"The Circular List is Empty!"<<endl;
        return;
    }
    cout<<endl<<"Enter the value of the node before which element would be inserted: ";
    cin>>info;
    s = begin;
    for (i = 0;i < index;i++)
    {
        pst++;
        if (s->data == info)
        {
            cond = true;
            break;
        }    
        s = s->next;
    }
    if (!cond)
    {
        cout<<"No match found in the list"<<endl; 
		return;
	}
    cout<<endl<<"Enter Value of Node to be inserted: ";
    cin>>info1;
    struct node *tmp, *p;
    tmp = create_node(info1);
    if (begin == end && begin == NULL)
    {
        if (pst == 1)
        {
            begin = end = tmp;
            begin->next = end->next = NULL;    
            begin->prev = end->prev = NULL;
        }
    }  
    else
    {
        s = begin;		
        for (i = 1;i <= index;i++)
        {
            p = s;
            s = s->next;
            if (i == pst - 1)
            {
                p->next = tmp;
                tmp->prev = p;
                tmp->next = s;
                s->prev = tmp;
                cout<<"Node inserted"<<endl;
                break;
            }
        }
    }
	
}

//Function to insert a node after a node containing a specific value
void circular_dlist::insert_after()
{
	int pst = 0, info, info1, i;
    bool cond = false;
    struct node *s;
    if (begin == end && begin == NULL)
    {
        cout<<"The Circular List is Empty!"<<endl;
        return;
    }
    cout<<endl<<"Enter the value of the node after which element would be inserted: ";
    cin>>info;
    s = begin;
    for (i = 0;i < index;i++)
    {
        pst++;
        if (s->data == info)
        {
			cond = true;
            break;
        }    
        s = s->next;
    }
    if (!cond)
    {
        cout<<"No match found in the list"<<endl; 
		return;
	}
    pst++;
	cout<<endl<<"Enter Value of Node to be inserted: ";
    cin>>info1;
    struct node *tmp, *p;
    tmp = create_node(info1);
    if (begin == end && begin == NULL)
    {
        if (pst == 1)
        {
            begin = end = tmp;
            begin->next = end->next = NULL;    
            begin->prev = end->prev = NULL;
        }
    }  
    else
    {
        s = begin;		
        for (i = 1;i <= index;i++)
        {
            p = s;
            s = s->next;
            if (i == pst - 1)
            {
                p->next = tmp;
                tmp->prev = p;
                tmp->next = s;
                s->prev = tmp;
                cout<<"Node inserted"<<endl;
                break;
            }
        }
    }
	
}

//Function to delete a node from the beginning	
void circular_dlist::delete_begin()
{
	node *p, *s;
	s = begin;
	index--;
    end->next = s->next;
    s->next->prev = end;
    begin = s->next;
    free(s);
    cout<<"First Node Deleted"<<endl;
    return;
}

//Function to delete a node from the end
void circular_dlist::delete_end()
{
	int i;
	node *p, *s;
	s = begin;
	for (i = 0;i < index - 1;i++ )
    {  
        s = s->next;
        p = s->prev;    	  
    }    
	p->next = s->next;
    s->next->prev = p;
	end = p;
    index--;
    free(s);
    cout<<"Node Deleted"<<endl;
}

//Function to delete a node from a specific position by index	
void circular_dlist::delete_position()
{    
    int pst, i;
    node *p, *s;
    if (begin == end && begin == NULL)
    {
        cout<<"Circular List is empty, deletion not possible"<<endl;
        return;
    }
    cout<<endl<<"Enter the position of Node to be deleted: ";
    cin>>pst;
    if (index < pst)
    {
        cout<<"Index inserted is out of range"<<endl;
        return;
    }
    s = begin;
    if(pst == 1)
    {
        index--;
        end->next = s->next;
        s->next->prev = end;
        begin = s->next;
        free(s);
        cout<<"Node Deleted"<<endl;
        return;	   
    }
    for (i = 0;i < pst - 1;i++ )
    {  
        s = s->next;
        p = s->prev;    	  
    }    
    p->next = s->next;
    s->next->prev = p;
    if (pst == index)
    {
        end = p; 	   
    }
    index--;
    free(s);
    cout<<"Node Deleted"<<endl;
}

//Function to print the list
void circular_dlist::show_list()
{
    int i;
    struct node *s;
    if (begin == end && begin == NULL)
    {
        cout<<"The Circular List is Empty!"<<endl;
        return;
    }
    s = begin;
    for (i = 0;i < index-1;i++)
    {	
        cout<<s->data<<"<->";
        s = s->next; 
    }
    cout<<s->data<<endl;
}
	 

