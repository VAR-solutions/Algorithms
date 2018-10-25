#include <bits/stdc++.h>
using namespace std; 
  
struct Node 
{ 
    Node * left; 
    Node* right; 
    int hd; 
    int data; 
}; 
  
Node* newNode(int key) 
{ 
    Node* node=new Node(); 
    node->left = node->right = NULL; 
    node->data=key; 
    return node; 
} 
  
void topview(Node* root) 
{ 
    if(root==NULL) 
       return; 
     queue<Node*>qa; 
     map<int,int> mp;  
     int hd=0; 
     root->hd=hd; 
       
    qa.push(root); 
      
    cout<< "The top view of the tree - "; 
      
    while(qa.size()) 
    { 
        hd=root->hd; 
          
        // count function returns 1 if the container  
        // contains an element whose key is equivalent  
        // to hd, or returns zero otherwise. 
        if(mp.count(hd)==0)   
        mp[hd]=root->data; 
        if(root->left) 
        { 
            root->left->hd=hd-1; 
            qa.push(root->left); 
        } 
        if(root->right) 
        { 
            root->right->hd=hd+1; 
            qa.push(root->right); 
        } 
        qa.pop(); 
        root=qa.front(); 
        
    } 
      
      
      
     for(auto i=mp.begin();i!=mp.end();i++) 
    { 
        cout<<i->second<<" "; 
    } 
      
} 
   
// Driver Program to test above functions 
int main() 
{ 
    /* 
    Create following Binary Tree  
        1  
        / \  
      22 333  
       \  
       4444  
         \  
        55555  
           \  
         666666

     */
   Node* root = newNode(1); 
    root->left = newNode(22); 
    root->right = newNode(333); 
    root->left->right = newNode(4444); 
    root->left->right->right = newNode(55555); 
    root->left->right->right->right = newNode(666666); 
    cout<<"Following are nodes in top view of the given binary tree ";  
    topview(root); 
    return 0; 
} 