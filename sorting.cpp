#include<iostream>
using namespace std;
class Node
{
private:
    int data;
    Node* next;
public:
    Node(int d=0)
    {
        data=d;
        next=NULL;
    }
friend class LinkedList;
};

class LinkedList
{
private:
    Node* head;


public:
    LinkedList()
    {
        head = NULL;
    }
    void InsertatBegin(int d)
    {
        Node* n=new Node(d);
        n->next=head;
        head=n;
    }
    void InsertatEnd(int d)
    {
        if (head==NULL) {InsertatBegin(d); return;}
        Node* temp=head;
        while (temp->next!=NULL){
            temp=temp->next;
        }

        temp->next=new Node(d);
    }

   void Print()
   {
        Node* temp=head;
        while (temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
   void DeleteatBegin()
   {
        if (head==NULL) return;
        Node* temp=head;
        head=head->next;
        delete temp;
    }

   void DeleteAtEnd()
   {
        if (head==NULL)
            return;
        if (head->next==NULL)
           {DeleteatBegin();return;}
        Node* temp=head;
        while (temp->next->next!=NULL)
          {
            temp=temp->next;
          }
        delete temp->next;
        temp->next=NULL;
    }




    Node* Merge(Node *h1, Node* h2)
    {
        ///if (h1==NULL && h2==NULL) return NULL;
        if (h1==NULL)
            return h2;
        if (h2==NULL)
            return h1;
        if (h1->data<h2->data)
           {
            h1->next=Merge(h1->next,h2);
            return h1;
           }
        else
            {
            h2->next=Merge (h1, h2->next);
            return h2;
           }
    }

   Node * Mid (Node *h)
    {
        Node * sp=h, *fp=h;
        while (fp->next!=NULL && fp->next->next!=NULL)
            {
            sp=sp->next;
            fp=fp->next->next;
            }
        Node* sl=sp->next;
        sp->next=NULL;
        return sl;
    }

  Node* MergeSort(Node * h)
   {
        if (h==NULL || h->next==NULL)
            return h;
        Node * sl=Mid (h);
        h = MergeSort(h);
        sl= MergeSort(sl);
        Node * nh=Merge(h,sl);
        return nh;
    }

  void MergeSort()
   {
        head=MergeSort(head);
    }



  Node* SelectionSort(Node * h)
  {

        if (h==NULL || h->next==NULL)
            return h;
        Node* smallest=h, *cur=h->next, *smallestPrev=NULL, *prev=h;
        while (cur!=NULL)
         {
            if (cur->data<smallest->data)
            {
                smallestPrev=prev;
                smallest=cur;
            }
            prev=cur;
            cur=cur->next;
        }
        if (smallest!=h)
           {
            smallestPrev->next=smallest->next;
            smallest->next=h;
        }

        smallest->next=SelectionSort(smallest->next);
        return smallest;
    }


  void SelectionSort()
   {
    head=SelectionSort(head);
    }

  Node * BubbleSort(Node * h, Node * till)
  {
        if (h==till || h->next==till)
           return h;
        Node *prev=NULL, *cur=h, *nxt=h->next;
        while (cur->next!=till)
          {
            nxt=cur->next;
            if (cur->data>nxt->data)
               {
                if (prev==NULL)
                  h=nxt;
               else prev->next=nxt;
                cur->next=nxt->next;
                nxt->next=cur;
                prev=nxt;

             } else
             {
                prev=cur;
                cur=nxt;
            }
        }
        return BubbleSort(h,cur);
    }

   void BubbleSort()
    {
        head=BubbleSort(head,NULL);
    }

   Node* InsertionSort(Node *h)
    {
        if(h == NULL || h->next == NULL)
          return h;
        Node *nh = InsertionSort(h->next);
        h->next = nh;
        if(h->data < h->next->data)
          return h;
        Node *cur = h;
        while(cur->next != NULL)
        {
            if(h->data < cur->next->data)
            {
                Node *tmp = h->next;
                h->next = cur->next;
                cur->next = h;
                h = tmp;
                return h;
            }
            cur=cur->next;
        }

        Node *tmp = h->next;
        h->next = NULL;
        cur->next = h;
        h = tmp;
        return tmp;
    }

  void InsertionSort()
    {
        head = InsertionSort(head);
    }

};

int main(){
LinkedList l;
cout<<"Number of nodes in linked list"<<endl;
int n;
cin>>n;
for(int i=0;i<n;i++)
     {
         cout<<"Enter data for the node: "<<endl;
         int c;
         cin>>c;
         l.InsertatBegin(c);
     }
cout<<"Entered list is: \n";
l.Print();
cout<<"Choose the operation you want to perform:\n";
cout<<"1: SelectionSort\n 2: MergeSort\n 3:InsertionSort\n 4: BubbleSort\n";
int r;
cin>>r;
switch(r)
  {
   case 1: l.SelectionSort();l.Print();break;
   case 2: l.MergeSort();l.Print();break;
   case 3: l.InsertionSort();l.Print();break;
   case 4: l.BubbleSort(); l.Print();break;
   default: cout<<"please enter a valid choice";break;
  }

}
