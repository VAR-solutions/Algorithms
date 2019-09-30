/*
*	Red-Black tree implemented for a College Work.
*	No copyright included.
*	Done by joaobnetto
*/

#include <bits/stdc++.h>
#define BLACK 1
#define RED 2

using namespace std;



struct node{
		int value, color;
		struct node *left, *right, *p;
};


class Tree{
private:
	node *root;
	node *T_NIL;
public:
	Tree();
	~Tree();
	void insert(int x);
	void insertFix_RB(node *no);
	void delet(node *z);
	void deleteFix_RB(node *x);
	void rotacionar_esquerda(node *no);
	void rotacionar_direita(node *no);
	void transplant(node *u, node *v);
	node *minimum(node *x);
	node *search(int x);
	void print();

};

void imprime(node *no, node *T_NIL);

void printt(node *no, node *T_NIL);

node *criar_no(int x,node *T_NIL);

void limpar(node *no, node *T_NIL);