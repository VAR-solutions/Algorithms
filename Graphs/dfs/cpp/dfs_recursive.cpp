#include <bits/stdc++.h>
using namespace std;

#define NODES 10

vector<int> adj[NODES];
int visit[NODES];

void DFS(int v){
  visit[v] = 1;
  
  for(int i = 0; i < adj[v].size(); i++)[
    int next = adj[v][i];
    
    if(visit[next] == 0) dfs(next);
  }
}

int main(){
  dfs(initialNode);
}
