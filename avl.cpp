//Implementação para AVL

#include <bits/stdc++.h>

using namespace std;

int indice;

int max(int a, int b){

	if(a > b) return a;
	else return b;

}

struct node{
	int key;
	int rank;
	int height;
	struct node* left;
	struct node* right;
};

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

struct node* Create_node(int key){
	struct node* noh;

	noh = (struct node *) malloc(sizeof(struct node));
	noh->key = key;
	noh->rank = 0;
	noh->height = -1;
	noh->left = NULL;
	noh->right = NULL;

	return noh;
}

int height(struct node* root){

	if(root==NULL){
		return -1;
	}
	return root->height;
}

int get_balance(struct node* root){

	if(root == NULL) return 0;
	return height(root->left) - height(root->right);
}


struct node* rightRotate(struct node* root){

	struct node* l = root->left; 
	struct node* lr = l->right;
	l->right = root;
	root->left = lr;

	root->height = max(height(root->left), height(root->right)) + 1;
	l->height = max(height(l->left), height(l->right)) + 1;

	return l;

}


struct node* leftRotate(struct node* root){

	struct node* r = root->right; 
	struct node* rl = r->left;
	r->left = root;
	root->right = rl;

	root->height = max(height(root->left), height(root->right)) + 1;
	r->height = max(height(r->left), height(r->right)) + 1;

	return r;

}


struct node* Insert_help(struct node* root, int key){

	if(root == NULL) {
		root = Create_node(key);
	}
	else if(key < root->key){
		root->left = Insert_help(root->left, key);

	}
	else{
		root->right = Insert_help(root->right, key);

	}

	root->height = 1 + max(height(root->left), height(root->right));

	int balance = get_balance(root);

	if(balance > 1 && key < root->left->key){
		return rightRotate(root);
	}

	if(balance < -1 && key >= root->right->key){
		return leftRotate(root);
	}

	if(balance > 1 && key >= root->left->key){
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	if(balance < -1 && key < root->right->key){
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;

}

struct node* Insert(struct node* root, int key){

	root = Insert_help(root, key);
	return root;
}

void Rankear(struct node* root){

	if(root != NULL){
		if(root->left != NULL){
			Rankear(root->left);
			indice++;
		}
		root->rank = indice;
		if(root->right != NULL){
			Rankear(root->right);
			indice++;
		}
	}
}

int main(){
	
	struct node* root = NULL, *search;

	int n, valor, op;

	scanf("%d", &n);

	while(n--){
		scanf("%d %d", &op, &valor);
		if(op==1){
			root = Insert(root, valor);
			indice = 1;
		}
		else{

			Rankear(root);
			search = Find(root, valor);
			if(search != NULL){
				printf("%d\n", search->rank);
			}
			else puts("Esse valor não existe na AVL :(");
		}

	}



	return 0;
}
