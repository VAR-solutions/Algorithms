#include "heap.h"



void add(MinHeap* h, int value) {
	h->heap[++(h->N)] = value;

	sift(h, h->N);
	percolate(h, h->N);
}

void rmv(MinHeap* h, int node) {
	swap_nodes(h, node, h->N);
	h->N--;

	sift(h, node);
	percolate(h, node);
}

void sift(MinHeap* h, int node) {
	int son;

	do {
		son = 0;
		if(2*node+1 <= h->N) {
			if (h->heap[2*node+1] < h->heap[2*node]) {
				son = 2*node+1;
			} else {
				son = 2*node;
			}
		} else if (2*node <= h->N) {
			son = 2*node;
		}

		if(h->heap[node] < h->heap[son]) {
			son = 0;
		}

		if(son) {
			swap_nodes(h, node, son);
			node = son;
		}
	} while (son);
}

void percolate(MinHeap* h, int node) {
	while(node > 1 && h->heap[node] < h->heap[node/2]) {
		swap_nodes(h, node, node/2);
		node/=2;
	}
}

void swap_nodes(MinHeap* h, int node1, int node2) {
	int man = h->heap[node1];
	h->heap[node1] = h->heap[node2];
	h->heap[node2] = man;
}

int get_value_at_node(MinHeap* h, int node) {
	return h->heap[node];
}
