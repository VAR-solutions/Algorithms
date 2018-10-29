#include <iostream>
#include <queue>
using namespace std;

struct Node{
    //This is the structure of the binary tree.
    int data;
    Node *left;
    Node *right;
};

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    while(!q.empty()){
        root = q.front();
        q.pop();
        cout << root->data << " ";
        
        if(root->left!=NULL){
            q.push(root->left);
        }
        if(root->right!=NULL){
            q.push(root->right);
        }
    }
}

int main(int argc, char const *argv[])
{
    // Initializing a 3 element binary tree.
    Node *root = new Node();
    root->data = 10;
    root->right = new Node();
    root->right->data = 15;
    root->left = new Node();
    root->left->data = 5;
    root->left->left = new Node();
    root->left->left->data = 30;
    root->left->right = new Node();
    root->left->right->data = 50;

    levelOrderTraversal(root);
    return 0;
}    