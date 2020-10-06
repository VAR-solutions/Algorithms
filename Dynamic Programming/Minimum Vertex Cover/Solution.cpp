#include<bits/stdc++.h>
using namespace std;

// Source : GeeksForGeeks (https://www.geeksforgeeks.org/vertex-cover-problem-set-2-dynamic-programming-solution-tree/)
/* A binary tree node has data, pointer to left child and a pointer to 
   right child */
struct node 
{ 
    int data; 
    int vc; 
    struct node *left, *right; 
}; 
  
// A memoization based function that returns size of the minimum vertex cover. 
int vCover(node *root) 
{ 
    // The size of minimum vertex cover is zero if tree is empty or there 
    // is only one node 
    if (root == NULL) 
        return 0; 
    if (root->left == NULL && root->right == NULL) 
        return 0; 
  
    // If vertex cover for this node is already evaluated, then return it 
    // to save recomputation of same subproblem again. 
    if (root->vc != 0) 
        return root->vc; 
  
    // Calculate size of vertex cover when root is part of it 
    int size_incl = 1 + vCover(root->left) + vCover(root->right); 
  
    // Calculate size of vertex cover when root is not part of it 
    int size_excl = 0; 
    if (root->left) 
      size_excl += 1 + vCover(root->left->left) + vCover(root->left->right); 
    if (root->right) 
      size_excl += 1 + vCover(root->right->left) + vCover(root->right->right); 
  
    // Minimum of two values is vertex cover, store it before returning 
    root->vc =  min(size_incl, size_excl); 
  
    return root->vc; 
} 
  
// A utility function to create a node 
node* newNode( int data ) 
{ 
    node* temp = new node(); 
    temp->data = data; 
    temp->left = temp->right = NULL; 
    temp->vc = 0; // Set the vertex cover as 0 
    return temp; 
} 
  
// Driver program to test above functions 
int main() 
{ 
    // Let us construct the tree given in the above diagram 
    node *root = newNode(20); 
    root->left = newNode(8); 
    root->left->left = newNode(4); 
    root->left->right = newNode(12); 
    root->left->right->left = newNode(10); 
    root->left->right->right = newNode(14); 
    root->right  = newNode(22); 
    root->right->right= newNode(25); 
  
    cout<<"Min Vertex Cover is "<<vCover(root)<<endl; 
  
    return 0; 
} 