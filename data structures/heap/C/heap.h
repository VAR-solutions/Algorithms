#ifndef HEAP_H
#define HEAP_H
#define MAX_NODES 100


/* An implementation of a MinHeap, a tree based data structure in which which each node's value is lesser than its children.*/

typedef struct
{
    int N;
    int heap[MAX_NODES];
} MinHeap;

void add(MinHeap* h, int value);

void rmv(MinHeap* h, int node);

void sift(MinHeap* h, int node);

void percolate(MinHeap* h, int node);

void swap_nodes(MinHeap* h, int node1, int node2);


int get_value_at_node(MinHeap* h, int node);
#endif // HEAP_H
