#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
#define mod 1000000007
#define CLEAR(a) memset((a),0,sizeof(a))
#define ll long long int
#define pii pair<ll,ll> 
#define level 18 
vector <int> tree[100000]; 
int depth[100000]; 
int parent[100000][18];  
void dfs(int cur, int prev) 
{ 
    depth[cur] = depth[prev] + 1; 
    parent[cur][0] = prev; 
    for (int i=0; i<tree[cur].size(); i++) 
    { 
        if (tree[cur][i] != prev) 
            dfs(tree[cur][i], cur); 
    } 
} 
void precomputeSparseMatrix(int n) 
{ 
    for (int i=1; i<level; i++) 
    { 
        for (int node = 1; node <= n; node++) 
        { 
            if (parent[node][i-1] != -1) 
                parent[node][i] = 
                    parent[parent[node][i-1]][i-1]; 
        } 
    } 
} 
int lca(int u, int v) 
{ 
    if (depth[v] < depth[u]) 
        swap(u, v); 
    int diff = depth[v] - depth[u];
    for (int i=0; i<level; i++) 
        if ((diff>>i)&1) 
            v = parent[v][i];  
    if (u == v) 
        return u; 
    for (int i=level-1; i>=0; i--) 
        if (parent[u][i] != parent[v][i]) 
        { 
            u = parent[u][i]; 
            v = parent[v][i]; 
        } 
    return parent[u][0]; 
}  
int main() 
{ 
    memset(parent,-1,sizeof(parent)); 
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    } 
    depth[0] = 0;  
    dfs(1,0); 
    precomputeSparseMatrix(n); 
    int q;
    cin>>q;
    while(q--)
    {
        int a,b;
        cin>>a>>b;
        cout<<lca(a,b)<<endl;
    } 
    return 0; 
}