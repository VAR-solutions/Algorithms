#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;

};

node* new_node(int data)
{
    node* temp=new node;
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

node* insert_node(node *root,int data)
{
    if(root==NULL)
    return new_node(data);

    else
    {
        if(root->data<data)
            root->right= insert_node(root->right,data);

        else if(root->data >=data)
            root->left= insert_node(root->left,data);

        return root;

    }
}

node *leftshift(node *root)
{
    return root->left;
}

node *rightshift(node *root)
{
    return root->right;
}

void preOrder(node* root)
{
    if(root==NULL)
        return ;
    else
    {
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{
    int t;
    cin>>t;
    int rootData;
    cin>>rootData;

    node *root=new_node(rootData);
    node *r=new_node(rootData);
    t--;


    while(t--)
    {
        root=r;
        string s;
        cin>>s;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='L')
                root=leftshift(root);
            else
                root=rightshift(root);

        }
        int data;
        cin>>data;

        insert_node(root,data);
    }

    preOrder(r);
    return 0;
}
