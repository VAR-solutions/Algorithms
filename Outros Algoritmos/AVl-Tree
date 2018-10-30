#include <stdio.h>
#include <stdlib.h>

typedef struct nod{

	int key;
	int nodecountL;
	int nodecountR;
	int height;
	struct nod *left;
	struct nod *right;
}Node;

typedef struct{

	Node *root;
}BST;

BST *create_bst(){

	BST *bst;

	bst = (BST *) malloc(sizeof(BST));
	bst->root = NULL;

	return bst;
}

int max(int a,int b){

	if(a>b) return a;
	else return b;
}

int height(Node *node){

	if(node==NULL) return -1;
	else return node->height;
}

int total(Node *node){

	if(node==NULL) return 0;
	else return (1+(node->nodecountL) + (node->nodecountR));
}

Node *leftRotate(Node *node){

	Node *r,*rl;

	r = node->right;
	rl = r->left;
	r->left = node;
	node->right = rl;
	node->nodecountR = total(rl);
	r->nodecountL = total(node);
	node->height = max(height(node->left),height(node->right)) + 1;
	r->height = max(height(r->left),height(r->right)) + 1;

	return r;
}

Node *rightRotate(Node *node){

	Node *l,*lr;

	l = node->left;
	lr = l->right;
	l->right = node;
	node->left = lr;
	node->nodecountL = total(lr);
	l->nodecountR = total(node);
	node->height = max(height(node->left),height(node->right)) + 1;
	l->height = max(height(l->left),height(l->right)) + 1;

	return l;
}

Node *inserthelp(Node *node,int x){

	int balance;
	if(node==NULL){
		node = (Node *) malloc(sizeof(Node));
		node->key = x;
		node->nodecountL = 0;
		node->nodecountR = 0;
		node->height = 0;
		node->left = NULL;
		node->right = NULL;
		return node;
	}
	if(x < node->key){
		node->left = inserthelp(node->left,x);
		node->nodecountL++;
	}
	else{
		node->right = inserthelp(node->right,x);
		node->nodecountR++;
	}
	node->height = max(height(node->left),height(node->right)) + 1;
	balance = height(node->left) - height(node->right);
	if(balance > 1 && x < (node->left->key)){
		node = rightRotate(node);
	}
	else if(balance < -1 && x > (node->right->key)){
		node = leftRotate(node);
	}
	else if(balance > 1 && x > (node->left->key)){
		node->left = leftRotate(node->left);
		node = rightRotate(node);
	}
	else if(balance < -1 && x < (node->right->key)){
		node->right = rightRotate(node->right);
		node = leftRotate(node);
	}

	return node;

}

void insert(BST *bst,int x){

	bst->root = inserthelp(bst->root,x);
}

int findhelp(Node *node,int x,int value){

	if(node==NULL) return -1;
	if(node->key == x) return (value+(node->nodecountL)+1);
	else if(x > node->key){
		value+= (total(node->left) + 1);
		return findhelp(node->right,x,value);
	}
	else{
		return findhelp(node->left,x,value);
	}
}

int find(BST *bst,int x){

	return findhelp(bst->root,x,0);
}

Node *apagar(Node *node){

	if(node==NULL) return NULL;
	node->left = apagar(node->left);
	node->right = apagar(node->right);
	free(node);
	return NULL;
}

void clear(BST *bst){

	bst->root = apagar(bst->root);
}


int main(){

	BST *bst;
	int q,op,x,i,st;

	bst = create_bst();
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		scanf("%d %d",&op,&x);
		if(op==1){
			insert(bst,x);
		}
		else{
			st = find(bst,x);
			if(st==-1){
				printf("Data tidak ada\n");
			}
			else{
				printf("%d\n",st);
			}
		}
	}
	clear(bst);
	free(bst);

	return 0;
}
