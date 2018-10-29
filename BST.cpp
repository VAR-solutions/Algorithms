#include <stdio.h>
#include <stdlib.h>

//Implementação para BST(Binary Search Tree)

struct node{

	int key;
	int valor;
	struct node* left;
	struct node* right;

};


struct node* Create_node(int key, int valor){
	struct node* noh;

	noh = (struct node *) malloc(sizeof(struct node));
	noh->key = key;
	noh->valor = valor;
	noh->left = NULL;
	noh->right = NULL;

	return noh;
}


struct node* Find_help(struct node* root, int key){

	if(root == NULL) return NULL;

	else if(root->key > key){

		return Find_help(root->left, key);
	}
	else if(root->key == key){
		return root;

	}	
	else{
		return Find_help(root->right, key);
	}
}

struct node* Find(struct node* root, int key){
	root = Find_help(root, key);
	return root;
}

struct node* Insert_help(struct node* root, int key, int valor){

	if(root == NULL) {
		root = Create_node(key, valor);
	}
	else if(key < root->key){
		root->left = Insert_help(root->left, key, valor);

	}
	else{
		root->right = Insert_help(root->right, key, valor);

	}
	return root;

}


struct node* Insert(struct node* root, int key, int valor){

	root = Insert_help(root, key, valor);
	return root;
}

void Print_pre_order(struct node* root){
	if(root != NULL){
		printf("%d\n", root->valor);
		Print_pre_order(root->left);
		Print_pre_order(root->right);
	}
}

void Print_pos_order(struct node* root){
	if(root != NULL){
		Print_pos_order(root->left);
		Print_pos_order(root->right);
		printf("%d\n", root->valor);
	}
}

void Print_in_order(struct node* root){
	if(root != NULL){
		Print_in_order(root->left);
		printf("%d\n", root->valor);
		Print_in_order(root->right);
	}
}

struct node* Get_min(struct node* root){

	if(root->left == NULL) return root;

	else return Get_min(root->left);

}

struct node* Delete_min(struct node* root){

	if(root->left == NULL) return root->right;
	else root->left = Delete_min(root->left);

	return root;
}


struct node* Remove_help(struct node* root, int key){

	if(root == NULL) return NULL;

	if(key < root->key){
		root->left = Remove_help(root->left, key);
	}

	else if(key > root->key){
		root->right = Remove_help(root->right, key);
	}
	else{
		if(root->left == NULL) return root->right;
		else if(root->right == NULL) return root->left;
		else{
			struct node* temp;
			temp = Get_min(root->right);
			root->valor = temp->valor;
			root->key = temp->key;
			root->right = Delete_min(root->right);
		}
	}

	return root;

}

struct node* Remove(struct node* root, int key){

	struct node* temp = Find_help(root, key);

	if(temp != NULL){
		root = Remove_help(root, key);
	}

	return root;
}

struct node* RemoveAny(struct node* root){

	if(root == NULL) return NULL;
	root = Remove_help(root, root->key);

	return root;

}

int main(){

	struct node* root = NULL;

	int n;

	while(scanf("%d", &n), n){
		root = Insert(root, n, n);
	}

	Print_in_order(root);
	puts("");

	return 0;
}
