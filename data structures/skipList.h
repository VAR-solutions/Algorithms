#pragma once
#include <iostream>

using namespace std;

// Class to implement node
class Node
{
public:
	int key;

	// Array to hold pointers to node of different level 
	Node **forward;
	Node(int, int);
};

Node::Node(int key, int level)
{
	this->key = key;

	// Allocate memory to forward 
	forward = new Node*[level + 1];

	// Fill forward array with 0(NULL)
	memset(forward, 0, sizeof(Node*)*(level + 1));
};

// Class for Skip list
class SkipList
{
	// Maximum level for this skip list
	int MAXLVL;

	// P is the fraction of the nodes with level 
	// i pointers also having level i+1 pointers
	float P;

	// current level of skip list
	int level;

	// pointer to header node
	Node *header;
public:
	SkipList(int, float);
	int randomLevel();
	Node* createNode(int, int);
	void insertElement(int);
	void displayList();
};

SkipList::SkipList(int MAXLVL, float P)
{
	this->MAXLVL = MAXLVL;
	this->P = P;
	level = 0;

	// create header node and initialize key to -1
	header = new Node(-1, MAXLVL);
};

// create random level for node
int SkipList::randomLevel()
{
	float r = (float)rand() / RAND_MAX;
	int lvl = 0;
	while (r < P && lvl < MAXLVL)
	{
		lvl++;
		r = (float)rand() / RAND_MAX;
	}
	return lvl;
};

// create new node
Node* SkipList::createNode(int key, int level)
{
	Node *n = new Node(key, level);
	return n;
};

// Insert given key in skip list
void SkipList::insertElement(int key)
{
	Node *current = header;

	// create update array and initialize it
	Node *update[MAXLVL + 1];
	memset(update, 0, sizeof(Node*)*(MAXLVL + 1));

	/*    start from highest level of skip list
	move the current pointer forward while key
	is greater than key of node next to current
	Otherwise inserted current in update and
	move one level down and continue search
	*/
	for (int i = level; i >= 0; i--)
	{
		while (current->forward[i] != NULL &&
			current->forward[i]->key < key)
			current = current->forward[i];
		update[i] = current;
	}

	/* reached level 0 and forward pointer to
	right, which is desired position to
	insert key.
	*/
	current = current->forward[0];

	/* if current is NULL that means we have reached
	to end of the level or current's key is not equal
	to key to insert that means we have to insert
	node between update[0] and current node */
	if (current == NULL || current->key != key)
	{
		// Generate a random level for node
		int rlevel = randomLevel();

		// If random level is greater than list's current
		// level (node with highest level inserted in 
		// list so far), initialize update value with pointer
		// to header for further use
		if (rlevel > level)
		{
			for (int i = level + 1; i<rlevel + 1; i++)
				update[i] = header;

			// Update the list current level
			level = rlevel;
		}

		// create new node with random level generated
		Node* n = createNode(key, rlevel);

		// insert node by rearranging pointers 
		for (int i = 0; i <= rlevel; i++)
		{
			n->forward[i] = update[i]->forward[i];
			update[i]->forward[i] = n;
		}
		cout << "Successfully Inserted key " << key << "\n";
	}
};

// Display skip list level wise
void SkipList::displayList()
{
	cout << "\n*****Skip List*****" << "\n";
	for (int i = 0; i <= level; i++)
	{
		Node *node = header->forward[i];
		cout << "Level " << i << ": ";
		while (node != NULL)
		{
			cout << node->key << " ";
			node = node->forward[i];
		}
		cout << "\n";
	}
};