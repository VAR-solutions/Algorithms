#include "arvore_rb_c.h"

/*
* Tree constructor:
* This implementation uses Sentinel nodes, so I create one, make his color black
* and then I make my root point to it.
*/
Tree::Tree(){
	
	this->T_NIL = criar_no(0,this->T_NIL);
	this->T_NIL->color = BLACK;
	this->root = this->T_NIL;

}

/*
* For the deconstructor I just remove all nodes from the memory.
*/

Tree::~Tree(){
	limpar(this->root, this->T_NIL);
	
	free(this->T_NIL);
}

/*
*	For the insertion in a RB, we just insert a RED node the same way we would in a Binary Search Tree.
*   If the properties of the RB are violated, we have to fix it, that's why we call InsertFix.
*/

void Tree::insert(int x){
	
	// If there's no nodes in the tree. I just insert at the root.
	if(this->root == this->T_NIL){ 
		this->root = criar_no(x,this->T_NIL);
		this->root->color = BLACK; 
		return;
	}

	// Insertion like on an Binary Search Tree, saving the node's father.
	node *tmp = this->root, *y;
	while(tmp != this->T_NIL){
		y = tmp;
		if(tmp->value > x){
			tmp = tmp->left;
		} 
		else{
			tmp = tmp->right;
		}
	}

	tmp = criar_no(x, T_NIL); 
	tmp->p = y; 
	if(tmp->value < y->value) y->left = tmp; 
	else y->right = tmp; 
	tmp->right = tmp->left = T_NIL;
	insertFix_RB(tmp); 
}


// This function transforms node v into u.
void Tree::transplant(node* u, node *v){ 
	// If u is the root, v becomes the root.
	if(u->p == T_NIL) this->root = v; 
	// If u is a left child, v becomes a left child.
	else if(u == u->p->left) u->p->left = v;
	// if u is a right child, v becomes a right child.
	else u->p->right = v;
	
	// The father of v becomes u.
	v->p = u->p;
	// Then we delete node u.
	free(u);
}

/*
*	This function deletes a node from the RB.
* 	The removal of a node is the same as a Binary Search Tree.
*	If we delete a RED node, there's no need to fix the RB since no properties are violated.
*	Else we call the function DeletionFix.
*/

void Tree::delet(node *z){ 
	node *y = z, *x; 
	
	int yOriginalColor = y->color; 
	
	// Deleting like a Binary Search Tree.

	// If there's no left child.
	if(z->left == T_NIL){ 
		x = z->right; 
		transplant(z,z->right); 
	}

	// If there's no right child.
	else if(z->right == T_NIL){ 
		x = z->left;
		transplant(z, z->left); 
	}
	
	// If it has both childs.
	else{ 
		y = minimum(y->right); 
		yOriginalColor = y->color; 
		x = y->right; 
		if(y->p == z) x->p = y;
		else{
			transplant(y, y->right); 
			y->right = z->right;
			y->right->p = y;
		}
		transplant(z,y); 
		y->left = z->left; 
		y->left->p = y; 
		y->color = z->color; 
	}

	if(yOriginalColor == BLACK) deleteFix_RB(x);
}

/*
*	Functions that rotates to the left or right around a node x.
*/

void Tree::rotacionar_esquerda(node *x){

	node *y = x->right;
	x->right = y->left;

	if(y->left != T_NIL){ 
		y->left->p = x; 
	}

	y->left = x;

	if(x->p == this->T_NIL) this->root = y; 
	else if(x->p->left == x) x->p->left = y; 
	else x->p->right = y;

	y->p = x->p; 
	x->p = y;
}

void Tree::rotacionar_direita(node *x){ 
	
	node *y = x->left;
	x->left = y->right;
	
	if(y->right != T_NIL){
		y->right->p = x;
	}
	
	y->right = x;
	
	if(x->p == this->T_NIL) this->root = y;
	else if(x->p->left == x) x->p->left = y;
	else x->p->right = y;
	
	y->p = x->p;
	x->p = y;
}

/*
*	Function so search in a Binary Search Tree, returns the node found.
*/

node *Tree::search(int x){ 

	node *tmp = this->root;
	
	while(tmp != T_NIL && tmp->value != x){
	
		if(tmp->value > x){
			tmp = tmp->left;
		}
	
		else if(tmp->value < x){
			tmp = tmp->right;
		}
	
	}
	return tmp;
}

/*
*	Finds the minimum element on a sub-tree with root x.
*/

node *Tree::minimum(node *x){
	
	while(x->left != T_NIL){
		x = x->left;
	}
	return x;
}

/*
*	This function fixes the RB properties after an insertion.
*	It's divided in three cases if the father of my node is RED, since we know that the actual node is RED.
*	Case 1: If the father of node x is RED and it's uncle is red, then we paint them both black
*	and the grandfather red. Then, x becomes the grandfather, so we can fix it.
*	Case 2: If the uncle is not RED and x is a right child, we rotate left.
*	Case 3: If the uncle is not RED and x is a left child, we paint x father to black and it's grandfather to RED,
*	then we rotate right.
*	Case 2 can fall in Case 3. On the end we paint the root black.
*	There's two symetrical cases when the father is left or right.
*/

void Tree::insertFix_RB(node *x){
	
	node *y; 
	
	while(x->p->color == RED){ 
		
		if(x->p == x->p->p->left){ 

			// Case 1:
			y = x->p->p->right; 
			if(y->color == RED){ 
				x->p->color = BLACK; 
				y->color = BLACK;
				x->p->p->color = RED; 
				x = x->p->p; 
			}

			else{ 

				// Case 2:
				if(x == x->p->right){
					x = x->p; 
					rotacionar_esquerda(x);
				}

				// Case 3: 

				x->p->color = BLACK; 
				x->p->p->color = RED; 

				rotacionar_direita(x->p->p); 
			}
		}

		// Symetrical counterpart.
		else{

			// Case 1:
			y = x->p->p->left;
			
			if(y->color == RED){
				x->p->color = BLACK;
				y->color = BLACK;
				x->p->p->color = RED;
				x = x->p->p;
			}

			else{ 
				// Case 2:
				if(x == x->p->left){
					x = x->p;
					rotacionar_direita(x);
				}

				// Case 3:
				x->p->color = BLACK;
				x->p->p->color = RED;
				rotacionar_esquerda(x->p->p);
			}
		}
	} 
	this->root->color = BLACK;
}

void Tree::deleteFix_RB(node *x){
	node *w;
	while(x != this->root && x->color == BLACK){
		if(x == x->p->left){
			w = x->p->right;
			if(w->color == RED){
				w->color = BLACK;
				x->p->color = RED;
				rotacionar_esquerda(x->p);
				w = x->p->right;
			}
			if(w->left->color == BLACK && w->right->color == BLACK){
				w->color = RED;
				x = x->p;
			}
			else{
				if(w->right->color == BLACK){
					w->left->color = BLACK;
					w->left->color = RED;
					rotacionar_direita(w);
					w = x->p->right;
				}
				w->color = x->p->color;
				x->p->color = BLACK;
				w->right->color = BLACK;
				rotacionar_esquerda(x->p);
				x = this->root;
			}
		}
		else{
			w = x->p->left;
			if(w->color == RED){
				w->color = BLACK;
				x->p->color = RED;
				rotacionar_direita(x->p);
				w = x->p->left;
			}
			if(w->right->color == BLACK && w->left->color == BLACK){
				w->color = RED;
				x = x->p;
			}
			else{
				if(w->left->color == BLACK){
					w->right->color = BLACK;
					w->right->color = RED;
					rotacionar_esquerda(w);
					w = x->p->left;
				}
				w->color = x->p->color;
				x->p->color = BLACK;
				w->left->color = BLACK;
				rotacionar_direita(x->p);
				x = this->root;
			}
		}
	}
	x->color = BLACK;
}

// Prints the whole tree.

void Tree::print(){
	printt(this->root, this->T_NIL);
}


// Allocates a node in the memory and returns it.

node *criar_no(int x, node *T_NIL){
	node *no = (node*) malloc(sizeof(node));
	no->left = no->right = no->p = T_NIL;
	no->value = x;
	no->color = RED;
	return no;
}

// Prints the node by parameter, does a BFS to print by Level.
void printt(node *no, node *T_NIL){
	
	if(no == NULL) return;
	queue < int > sp;
	queue < node* > q;
	q.push(no);
	sp.push(0);
	
	while(!q.empty()){
		
		node *tmp = q.front();
		int spaces = sp.front();
		sp.pop();
		q.pop();
		
		for(int i = 0;i < spaces;i++){
			cout << "-";
		}
		
		if(tmp->color == RED) cout << "\033[1;31m " << tmp->value << "\033[0m" << endl;
		
		else cout << tmp->value << endl;
		
		if(tmp->left != T_NIL) {
			q.push(tmp->left);
			sp.push(spaces+7);
		}
		
		if(tmp->right != T_NIL){
			q.push(tmp->right);
			sp.push(spaces+7);
		}
	}
}


// Cleans the tree.
void limpar(node *no, node *T_NIL){
	if(no == T_NIL) return;
	limpar(no->left, T_NIL);
	limpar(no->right, T_NIL);
	free(no);
}