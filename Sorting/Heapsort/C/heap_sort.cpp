#include "stdafx.h"
#include <stdio.h> 
#include <stdlib.h> 
#define LEN 10
#define OFFSET 1
#define SWAP(x,y) {int t; t = x; x = y; y = t;} 

void heapSort(int*, int len, int(*)(int, int));
void heapTree(int*, int, int(*)(int, int));
void selectFromHeap(int*, int, int(*)(int, int));

void bubbleLeaf(int*, int, int(*)(int, int));
int isBubbleable(int*, int, int, int(*)(int, int));

void bubbleRoot(int*, int, int(*)(int, int));
int idxFromChilds(int*, int, int, int(*)(int, int));
int isRightLeafSuitable(int*, int, int, int(*)(int, int));

void print(int*, int len);
int ascending(int, int);
int descending(int, int);

int main(void) {
	int num[LEN] = { 10, 9, 1, 2, 5, 3, 8, 7, 12, 11 };

	heapSort(num, LEN, descending);
	print(num, LEN);

	heapSort(num, LEN, ascending);
	print(num, LEN);

	system("PAUSE");

	return 0;
}

void heapSort(int* num, int len, int(*compar)(int, int)) {
	heapTree(num, len, compar);
	selectFromHeap(num, len, compar);
}

void heapTree(int* num, int len, int(*compar)(int, int)) {
	int i, end;
	for (i = 1, end = len + 1; i < end; i++) { bubbleLeaf(num, i, compar); }
}

void selectFromHeap(int* num, int len, int(*comp)(int, int)) {
	int end;
	for (end = len; end > OFFSET; end--) {
		SWAP(num[1 - OFFSET], num[end - OFFSET]);
		bubbleRoot(num, end, comp);
	}
}

void bubbleLeaf(int* num, int eleIdx, int(*compar)(int, int)) {
	int childIdx, parentIdx;
	for (childIdx = eleIdx, parentIdx = eleIdx / 2;
		isBubbleable(num, childIdx, parentIdx, compar);
		childIdx = parentIdx, parentIdx = childIdx / 2) {
		SWAP(num[parentIdx - OFFSET], num[childIdx - OFFSET]);
	}
}

int isBubbleable(int* num, int childIdx,
	int parentIdx, int(*compar)(int, int)) {
	return childIdx > OFFSET &&
		compar(num[parentIdx - OFFSET], num[childIdx - OFFSET]) < 0;
}

void bubbleRoot(int* num, int end, int(*comp)(int, int)) {
	int parentIdx, childIdx;
	for (parentIdx = 0 + OFFSET,
		childIdx = idxFromChilds(num, parentIdx, end, comp);
		childIdx < end &&
		comp(num[childIdx - OFFSET], num[parentIdx - OFFSET]) > 0;
		parentIdx = childIdx,
		childIdx = idxFromChilds(num, parentIdx, end, comp)) {
		SWAP(num[parentIdx - OFFSET], num[childIdx - OFFSET]);
	}
}

int idxFromChilds(int* num, int parentIdx, int end, int(*comp)(int, int)) {
	int childIdx = parentIdx * 2;
	return isRightLeafSuitable(num, childIdx, end, comp) ?
		childIdx + 1 : childIdx;
}

int isRightLeafSuitable(int* num, int childIdx,
	int end, int(*comp)(int, int)) {
	return childIdx < end - 1 &&
		comp(num[childIdx + 1 - OFFSET], num[childIdx - OFFSET]) > 0;
}

void print(int* arr, int len) {
	int i;
	for (i = 0; i < len; i++) { printf("%d ", arr[i]); }
	printf("\n");
}

int ascending(int a, int b) { return a - b; }
int descending(int a, int b) { return -ascending(a, b); }