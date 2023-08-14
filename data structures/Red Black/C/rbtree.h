#include <stdio.h>
#include <stdlib.h>

typedef int (*RB_Tree_compare)(void *a, void *b);

typedef struct RB_Node {
	char color;
	void *key;
	struct RB_Node *left;
	struct RB_Node *right;
	struct RB_Node *parent;
} RB_Node;

typedef struct RB_Tree {
	int count;
	RB_Tree_compare cmp;
	RB_Node *root;	
} RB_Tree;

typedef int (*RB_traverse_cb)(RB_Node *node);

RB_Tree *Create_rbtree(RB_Tree_compare cmp);
RB_Node *Create_rbtree_node(RB_Node *parent, void *key, char color);

void Destroy_rbtree(RB_Tree *T);

void Left_rotate(RB_Tree *T, RB_Node *x);
void Right_rotate(RB_Tree *T, RB_Node *y);
void RB_insert(RB_Tree *T, RB_Node *z);
void RB_insert_fixup(RB_Tree *T, RB_Node *z);

int RB_Tree_traverse(RB_Tree *T, RB_traverse_cb traverse_cb);

void RB_Transplant(RB_Tree *T, RB_Node *u, RB_Node *v);
void RB_Delete(RB_Tree *T, RB_Node *z);
void RB_Delete_fixup(RB_Tree *T, RB_Node *x);
