#include <bits/stdc++.h>
using namespace std;

#define NODES 10
#define INF 1e8

typedef pair<int, int> ii;

vector<ii> graph[NODES];
int D[NODES], visit[NODES];

priority_queue<ii, vector<ii>, greater<ii> > min_heap;

void dijkstra(int v){
	D[v] = 0; // d(v, v) = 0
	min_heap.push(ii(0, v));
	
	while(!min_heap.empty()){
		ii now = min_heap.top();
		min_heap.pop();
		
		visit[now.second] = 1;
		
		for(int i = 0; i < graph[now.second].size(); i++){
			ii next = graph[now.second][i];

			if(visit[next.second] == 0){ 
				if(D[next.second] > D[now.second] + next.first){
					D[next.second] = D[now.second] + next.first;
				
					min_heap.push(ii(D[next.second], next.second));
				}
			}
		}
	}
}


int main(){
  for(int i = 0; i < SizeNodes; i++) 
  	D[i] = INF;
	
  // dijkstra(initialNode);
  // cout << D[arrivalNode] << endl;

return 0;
}
