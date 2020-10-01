#include "rbtree.h"
#include "bstrlib.c"
#include "dbg.h"

/*This file contains an implementation of a Red Black Tree.
 * Many of the methods are from LCTHW, thanks Zed.
 * Red Black Tree properties:
 * 1. Every node is either red or black.
 * 2. The root is black.
 * 3. Every leaf (NULL) is black.
 * 4. If a node is red, then both its children are black.
 * 5. For each node, all simple path from the node to descendent leaves contain
 * 	the same number of black nodes.
 * */

/*default_compare: just do the int comparition.*/
static int default_compare(void *a, void *b)
{
	return bstrcmp((bstring)a, (bstring)b);
}

/*Create_rbtree: create a Red Black tree and returns it.*/
RB_Tree *Create_rbtree(RB_Tree_compare cmp)
{
	RB_Tree *T = calloc(1, sizeof(RB_Tree));
	check_mem(T);

	T->cmp = cmp == NULL ? default_compare: cmp;
	return T;
error:
	if (T) 
		Destroy_rbtree(T);
	return NULL;
}

/*Create_rbtree_node: create a node of a Red-Black Tree and returns it.*/
RB_Node *Create_rbtree_node(RB_Node *parent, void *key, char color)
{
	RB_Node *node = calloc(1, sizeof(RB_Node));
	check_mem(node);
	
	node->color = color;
	node->key = key;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;
	return node;	
error:
	return NULL;
}

/*RB_destroy_cb: free up the memory hold by the given node.*/
int RB_destroy_cb(RB_Node *node)
{
	free(node);
	return 0;
}

/*Destroy_rbtree: free up the memory reserved by the given tree.*/
void Destroy_rbtree(RB_Tree *T)
{
	if (T) {
		RB_Tree_traverse(T, RB_destroy_cb);
		free(T);
	}
}

/*RB_Tree_traverse_nodes: traverse the subtree of a node and call
 * treverse_cb when it reach the bottom. So it will free up memory
 * from the bottom to the top.*/
int RB_Tree_traverse_nodes(RB_Node *node, RB_traverse_cb traverse_cb)
{
	int rc = 0;

	if (node->left) {
		rc = RB_Tree_traverse_nodes(node->left, traverse_cb);
		if (rc != 0) return rc;
	}

	if (node->right) {
		rc = RB_Tree_traverse_nodes(node->right, traverse_cb);
		if (rc != 0) return rc;
	}

	return traverse_cb(node);
}

/*RB_Tree_traverse: go through the node of the rbtree.*/
int RB_Tree_traverse(RB_Tree *T, RB_traverse_cb traverse_cb)
{
	if (T->root)
		return RB_Tree_traverse_nodes(T->root, traverse_cb);
	return 0;
}

/*Tree_minimum: find and return the minimum node.*/
RB_Node *Tree_minimum(RB_Node *node)
{
	while(node->left != NULL)
	       node = node->left;
	return node;
}

/*Left_rotate: update the node according to a left rotation.*/
void Left_rotate(RB_Tree *T, RB_Node *x)
{
	RB_Node *y = x->right;
	x->right = y->left;
	if (y->left != NULL)
		y->left->parent = x;
	
	y->parent = x->parent;
	if (x->parent == NULL)
		T->root = y;
	else if (x == x->parent->left)
		x->parent->left = y;
	else 
		x->parent->right = y;

	y->left = x;
	x->parent = y;
}

/*Rigth_rotate: update the node according to a right rotation.*/
void Right_rotate(RB_Tree *T, RB_Node *y)
{
	RB_Node *x = y->left;
	y->left = x->right;
	if (x->right != NULL)
		x->right->parent = y;
	
	x->parent = y->parent;
	if (y->parent == NULL)
		T->root = x;
	else if (y == y->parent->right)
		y->parent->right = x;
	else 
		y->parent->left = x;

	x->right = y;
	y->parent = x;
}

/*RB_insert: insert the given node into the RB_Tree and update the color.*/
void RB_insert(RB_Tree *T, RB_Node *z)
{
	RB_Node *y = NULL;
	RB_Node *x = T->root;
	while (x != NULL) {
		y = x;
		if (T->cmp(z->key, x->key) < 0)
			x = x->left;
		else
			x = x->right;
	}

	z->parent = y;
	if (y == NULL)
		T->root = z;
	else if (T->cmp(z->key, y->key) < 0)
		y->left = z;
	else
		y->right = z;
	z->left = NULL;
	z->right = NULL;
	z->color = 'r';
	RB_insert_fixup(T, z);
}

/*choose_side:to avoid repetition nothing magic. 0 is left and
 * anyother number is right.*/
void choose_side(RB_Tree *T, RB_Node *z, int side)
{	
	RB_Node *y = side == 0 ? z->parent->parent->left : z->parent->parent->right;
	RB_Node *nephew_side = side == 0? z->parent->left: z->parent->right;
	
	if (y != NULL && y->color == 'r') { //NULL does not have a color attribute.
		z->parent->color = 'b';
		y->color = 'b';
		z->parent->parent->color = 'r';
		z = z->parent->parent;
	} else { 
		if (z == nephew_side) {
			z = z->parent;
			Left_rotate(T, z);
		}
		z->parent->color = 'b';
		z->parent->parent->color = 'r';
		Right_rotate(T, z->parent->parent);
	}

}	

/*RB_insert_fixup: fix the tree in a way that hold the properties of a RB_Tree.
 * This is the most magic method.*/
void RB_insert_fixup(RB_Tree *T, RB_Node *z)
{
	while (z->parent->color == 'r') {
		if (z->parent == z->parent->parent->left)
			choose_side(T, z, 1);
		else 
			choose_side(T, z, 0);
	}
	T->root->color = 'b';
}

/*RB_Transplant: reorganize the subtrees of the node to be deleted appropiately.
 * This method is meant to be used by RB_Tree_delete.*/
void RB_Transplant(RB_Tree *T, RB_Node *u, RB_Node *v)
{
	if (u->parent == NULL) 
		T->root = v;
	else if (u == u->parent->left)
		u->parent->left = v;
	else
		u->parent->right = v;
	v->parent = u->parent;
}

/*RB_Delete: delete a given node from the Red-Black Tree.*/
void RB_Delete(RB_Tree *T, RB_Node *z)
{
	RB_Node *y = z, *x = z->right;
	char y_origin_color = y->color;

	if (z->left == NULL) {
		x = z->right;
		RB_Transplant(T, z, z->right);
	} else if (z->right == NULL) {
		x = z->left;
		RB_Transplant(T, z, z->left);
	} else {
		y = Tree_minimum(z->right);
		y_origin_color = y->color;
		x = y->right;
		
		if (y->parent == z)
			x->parent = y;
		else {
			RB_Transplant(T, y, y->right);
			y->right = z->right;
			y->right->parent = y;
		}
		RB_Transplant(T, z, y);
		y->left = z->left;
		y->left->parent = y;
		y->color = z->color;
	}

	if (y_origin_color == 'b')
		RB_Delete_fixup(T, x);
}

/*restore_by_side: restore the properties according to the side of the node.
 * If it is a right child or a left one.*/
void restore_by_side(RB_Tree *T, RB_Node *x, int side)
{
	RB_Node *w = side == 0? x->parent->left : x->parent->right; 
	if (w->color == 'r') {
		w->color = 'b';
		x->parent->color = 'r';
		Left_rotate(T, x->parent);
		w = side == 0 ? x->parent->left : x->parent->right;
	}
	if (w->left->color == 'b' && w->right->color == 'b') {
		w->color = 'r';
		x = x->parent;
	} else {
		char color_side = side == 0? w->left->color : w->right->color;
		if (color_side == 'b') {
			if (side == 0)
				w->right->color = 'b';
			else
				w->left->color = 'b';
			w->color = 'r';
			Right_rotate(T, w);
			w = side == 0 ? x->parent->left : x->parent->right;
		}
		w->color = x->parent->color;
		x->parent->color = 'b';
		if (side == 0)
			w->left->color = 'b';
		else
			w->right->color = 'b';
		Left_rotate(T, x->parent);
		x = T->root;
	}
	
}

/*RB_Delete_fixup: restore the properties of the rbtree.*/
void RB_Delete_fixup(RB_Tree *T, RB_Node *x)
{
	while (x != T->root && x->color == 'b') {
		if (x == x->parent->left) //check if it is a left child
			restore_by_side(T, x, 1);
		else 
			restore_by_side(T, x, 0);
		
	}
	x->color = 'b';
}
