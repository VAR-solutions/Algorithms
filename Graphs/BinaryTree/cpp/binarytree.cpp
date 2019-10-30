#include<iostream>
using namespace std;
struct Node{
	int data;
	struct Node *left;
	struct Node *right;
}
struct Node* newNode{
	struct Node* temp = new Node;
	temp->key = key;
	temp->left = temp->key = NULL;
	return temp;
}
void insert(strct Node* temp, int key)
{
	queue<struct Node*> q;
	q.push(temp);
	
	while(!q.empty())
	{
		sruct Node* temp = q.front();
		q.pop();
		
		if(!temp->left)
		{
			temp->left = newNode(key);
			break;
		}
		else
		{
			q.push(temp->left);
		}
		
		if(!temp->right)
		{
			temp->right = newNode(key);
			break;
		}
		else
		{
			q.push(temp->right);
		}	
	}
}
int main()
{
	struct Node* root = newNode(10);
	root->left = newNode(11);
	root->left->left = newNode(7);
	root->right = newnode(9);
	root->right->left = newNode(15);
	root->right->left = newNode(8);
	
	int key = 12;
	insert(root, key);
}