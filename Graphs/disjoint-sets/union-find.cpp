#include <bits/stdc++.h>
using namespace std;

#define SizeNodes 10
#define INF 1e8

vector<int> adj[SizeNodes];
int id[SizeNodes], size[SizeNodes];

void init(int i){
	id[i] = i; 
	size[i] = 1; 
}

int find(int i){
	if(id[i] == i) return i;
	return id[i] = find(id[i]); 
}

void unionSet(int a, int b){
	a = find(a);
	b = find(b);

	if(a == b) return;

	if(size[a] > size[b]) swap(a, b);
	
	id[a] = b;
	size[b] += size[a];
}

int main(){
	for(int i = 0; i < SizeNodes; i++) 
		init(i);

	unionSet(1, 3);
	unionSet(3, 7);

	unionSet(0, 5);

	cout << find(7) << " " << find(0) << endl;
  
return 0;
}
