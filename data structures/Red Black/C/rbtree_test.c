#include "minitest.h"
#include "bstrlib.h"
#include "rbtree.c"
#include <assert.h>


static RB_Tree *rbtree = NULL;
/*The following set of nodes will be needed for the complete creation of the tree.*/
static RB_Node *node1 = NULL;
static RB_Node *node2 = NULL;
static RB_Node *node3 = NULL;
static RB_Node *node4 = NULL;
static RB_Node *node5 = NULL;
static RB_Node *node6 = NULL;
static RB_Node *node7 = NULL;
//static RB_Node *node8 = NULL;
//static RB_Node *node9 = NULL;

struct tagbstring key1 = bsStatic("Hola Lola !");
struct tagbstring key2 = bsStatic("Ho"); 
struct tagbstring key3 = bsStatic("Hola Lola ! La");
struct tagbstring key4 = bsStatic("H");
struct tagbstring key5 = bsStatic("Hola Lo");
struct tagbstring key6 = bsStatic("Hola");
struct tagbstring key7 = bsStatic("Hol"); 
//struct tagbstring key7 = bsStatic("Hola ");
//struct tagbstring key8 = bsStatic("Hola Lol"); 
//struct tagbstring key9 = bsStatic("Hola"); 

char *test_rbtree_create(void)
{
	START("CREATE RED-BLACK TREE");
	rbtree = Create_rbtree(NULL); //a compare function is needed.
	mu_assert(rbtree != NULL, "Red-Black tree creation failed");
	return NULL;
}

char *test_destroy(void)
{
	START("DESTROY RED-BLACK TREE");
	Destroy_rbtree(rbtree);
	return NULL;
}

char *test_rbtree_node_create(void)
{
	START("CREATE A SINGLE NODE");
	node1 = Create_rbtree_node(NULL, &key1, 'b');
	mu_assert(node1 != NULL, "Failed to create rbtree node1");
	mu_assert(node1->key == &key1, "Wrong key in node1");
	mu_assert(node1->color == 'b', "Wrong color in node1");

	return NULL;
}

char *test_fillup_tree(void)
{
	START("FILLING UP RB TREE");
	mu_assert(node1 != NULL, "Failed the creation of node1");
	node2 = Create_rbtree_node(node1, &key2, 'r');
	mu_assert(node2 != NULL, "Failed the creation of node2");

	node3 = Create_rbtree_node(node1, &key3, 'b');
	mu_assert(node3 != NULL, "Failed the creation of node3");

	node4 = Create_rbtree_node(node2, &key4, 'b');
	mu_assert(node4 != NULL, "Failed the creation of node4");

	node5 = Create_rbtree_node(node2, &key5, 'b');
	mu_assert(node5 != NULL, "Failed the creation of node5");

	node6 = Create_rbtree_node(node5, &key6, 'r');
	mu_assert(node6 != NULL, "Failed the creation of node6");

	node7 = Create_rbtree_node(NULL, &key7, 'r');

	/*we now that is NULL*/
	rbtree->root = node1;
	node1->parent = rbtree->root;

	/*node1 children*/
	node1->left = node2;
	node1->right = node3;

	/*node2 children*/
	node2->left = node4; node2->right = node5;
	
	/*node5 child*/
	node5->left = node6;

	return NULL;
}

char *test_insert_node(void)
{
	START("INSERTING NODES INTO RB TREE");
	RB_insert(rbtree, node7);
	mu_assert(rbtree->root->key == &key1, "Wrong key of root after insertion");
	mu_assert(rbtree->root->color == 'b', "Wrong color of root element");

	RB_Node *mini = Tree_minimum(rbtree->root);
	mu_assert(mini->key == &key4, "Wrong key of minimum node");
	mu_assert(mini->color == 'b', "Wrong color of minimum node");
	
	mu_assert(rbtree->root->left->right->key == &key6, "Wrong key of parent of just inserted node");
	mu_assert(rbtree->root->left->right->color == 'b', "Wrong color of parent of just inserted node");

	mu_assert(rbtree->root->left->right->left->key == &key7, "Wrong key of left child  element");
	mu_assert(rbtree->root->left->right->left->color == 'r', "Wrong color of left child inserte element");

	mu_assert(rbtree->root->left->right->right->key == &key5, "Wrong key of right child of root element");
	mu_assert(rbtree->root->left->right->right->color == 'r', "Wrong color of right child element");

	return NULL;
}

int main(int argc, char *argv[])
{
	PASSED(test_rbtree_create());
	PASSED(test_rbtree_node_create());
	PASSED(test_fillup_tree());
	PASSED(test_insert_node());
	PASSED(test_destroy());
	return 0;
}
