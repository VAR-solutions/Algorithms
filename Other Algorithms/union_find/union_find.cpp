/*
*	Algorithm that merges two disjointed sets and can find
*	what set each element is.
*/

#include <bits/stdc++.h>
#define MAXN 10010

using namespace std;

// Declare the variables that will store the fathers and the ranks of each element.

int father[MAXN], rank[MAXN];

int find(int x){
	
	if(father[x] == x) return x;

	return father[x] = find(father[x]);

}

void merge(int x, int y){
	
	x = find(x);
	y = find(y);
	
	if(x == y) return;

	if(rank[x] > rank[y]){
		father[y] = x;
	}

	else{
		father[x] = y;
		if(rank[x] == rank[y]) rank[y]++;
	}
}


// Initializes each father to itself and rank to 0
int init(){
	memset(rank,0,sizeof(rank));
	for(int i = 1; i <= MAXN-1;++i) pai[i] = i;
}