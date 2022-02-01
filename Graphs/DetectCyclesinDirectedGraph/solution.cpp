#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<int> adj[], vector<bool> & visited, int s,unordered_map<int, bool> &mp){
    visited[s]=true;
    mp[s]=true;
    for(int x: adj[s]){
        if(!visited[x]){
            if(dfs(adj,visited,x,mp))
                return true;
        }
       else if(mp[x]==true){
            return true;
        }
        mp[x]=false;
    }
    
    return false;
    
    
}


bool isCyclic(int V, vector<int> adj[])
{
    int i,j;
    vector<bool> visited(V+1);

    for(i=0;i<V;i++){
        if(!visited[i]){
            unordered_map<int,bool> mp;
            if(dfs(adj,visited,i,mp))
                return true;
        }
    }
    return false;
}
int main(){

 
    int v,e;
    cin>>v>>e;
    vector<int> adj[v];
    int x,y;
    for(int i=0;i<e;i++){
        cin>>x>>y;
        adj[x].push_back(y);

    }
    cout<<isCyclic(adj,v)<<"\n";

}