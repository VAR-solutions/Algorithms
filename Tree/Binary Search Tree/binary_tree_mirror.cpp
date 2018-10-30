#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node*left;	
	struct node*right;
};

struct node* insert(int d,struct node*root){
	if(root ==NULL){
		struct node*temp = (struct node*) malloc(sizeof(struct node));
		temp->data=d;
		temp->left=NULL;
		temp->right=NULL;
		return temp;
	}
	else if(d >root->data){
		root->right= insert(d,root->right);
	}
	else{
		root->left = insert(d,root->left);
	}
	return root;
}

void inorder(struct node*root){
	if(root==NULL){
		return;
	}
	inorder(root->left);
	printf("%d",root->data);
	inorder(root->right);
}

void mirror(struct node*root){
	if(root==NULL){
		return;
	}
	else{
		mirror(root->left);
		mirror(root->right);
		struct node*temp;
		temp=root->left;
		root->left=root->right;
		root->right=temp;
	}
}

int main(){
	int n;
	cin>>n;
	int a[n];
	struct node*root = NULL;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		root = insert(a[i],root);
	}	
	inorder(root);
	mirror(root);
	printf("\n");
	inorder(root);
}
