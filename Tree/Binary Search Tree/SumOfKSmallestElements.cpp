// Sum of k smallest elements in BST

#include <bits/stdc++.h> 
using namespace std; 
  
struct Node 
{ 
    int data; 
    Node* left, * right; 
}; 
  
struct Node *createNode(int data) 
{ 
    Node * new_Node = new Node; 
    new_Node->left = NULL; 
    new_Node->right = NULL; 
    new_Node->data = data; 
    return new_Node; 
} 
  
struct Node * insert(Node *root, int key) 
{ 
    if (root == NULL) 
        return createNode(key); 
  
    if (root->data > key) 
        root->left = insert(root->left, key); 
  
    else if (root->data < key) 
        root->right = insert(root->right, key); 

    return root; 
} 
  
int ksmallestElementSumRec(Node *root, int k, int &count) 
{ 
    if (root == NULL) 
        return 0; 
    if (count > k) 
        return 0; 
  
    int res = ksmallestElementSumRec(root->left, k, count); 
    if (count >= k) 
        return res; 
  
    res += root->data; 
  
    count++; 
    if (count >= k) 
      return res; 
    return res + ksmallestElementSumRec(root->right, k, count); 
} 
  
int ksmallestElementSum(struct Node *root, int k) 
{ 
   int count = 0; 
   ksmallestElementSumRec(root, k, count); 
} 
  
int main() 
{ 
	int n,ele,k;
    Node *root = NULL; 
    printf("Enter No of nodes\n");
    scanf("%d",&n);
    int i=0;
    while(i<n)
    {
    	printf("Enter node value\n");
    	scanf("%d",&ele);
    	root = insert(root, ele); 
    	i++;
    }
  	printf("Enter value of k till which sum has to be calcuated\n");
  	scanf("%d",&k);
    cout <<  ksmallestElementSum(root, k) <<endl; 
    return 0; 
} 