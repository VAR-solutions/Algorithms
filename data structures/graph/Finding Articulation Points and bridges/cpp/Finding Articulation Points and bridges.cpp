#include <bits/stdc++.h>
using namespace std;
 
#define FOR(i,n)    for(int i=0;i<n;i++)
#define FOR1(i,n)   for(int i=1;i<=n;i++)
#define lli long long int
#define ld long double
#define ii pair<int,int>
#define vii vector<ii>
#define ff first
#define ss second
#define unvisited int(1000000)
vector<vector<int> > adj(600);
int dfs_num[110],dfs_parent[110],dfs_low[110],art_v[110];
int dfscount1,dfsRoot,rootChildren;

artNbridge(int u)
{
	dfs_low[u] = ++dfscount1;
	dfs_num[u] = dfscount1;
	
	FOR(i,adj[u].size())
	{
		int v = adj[u][i];
		
		if(dfs_num[v] == unvisited)
		{
			dfs_parent[v] = u;
			if(u == dfsRoot) rootChildren++;
			
			cout<<u<<"->"<<v<<endl;
			artNbridge(v);
			
			if(dfs_low[v] >= dfs_num[u] )
			{
				art_v[u] = 1;
			}
			dfs_low[u] = min(dfs_low[u],dfs_low[v]);
		}
		else if(v != dfs_parent[u]) dfs_low[u] = min(dfs_low[u], dfs_num[v]);
	}
}


int main() {
    int n;
    string s;
    map <string,int> m;
    cin>>n;cin.ignore();
    while(n)
    {
    	//cin.ignore();
    	FOR(i,n)	{
    		getline(cin,s);
    		m[s] = i;
    		cout<<m[s];
		}
    	int t;
    	cin>>t;cin.ignore();
    	
		/*Input the entire map*/
		
		FOR(i,t)	
    	{
    		string r;
    		cin>>s>>r;
    		cout<<m[s]<<"   "<<m[r]<<endl;
    		adj[m[s]].push_back(m[r]);
    		adj[m[r]].push_back(m[s]);
		}
		
		// INIT
		FOR(i,n)
		{
			dfs_low[i] = 0; 
			dfs_parent[i] = 0;
			art_v[i] = 0;
			dfs_num[i] = unvisited;
		}
		cout<<"LAST : "<<t;
		
		FOR(i,n)
		{
			if(dfs_num[i] == unvisited)
			{
				dfsRoot = i,rootChildren = 0;
				dfscount1 = 0;
				artNbridge(i);
				art_v[i] = (rootChildren > 1);
				
			}
		}
		
		/*PRINTING MAP*/
		FOR(i,n)
		{
			cout<<i<<" : ";
			FOR(k,adj[i].size())
			{
				cout<<adj[i][k];
			}
			cout<<endl;
		}
		FOR(i,n)
		{
			
			if(art_v[i] == 1)	cout<<i;
			//else cout<<"..";
		}
		FOR(i,n)	adj[i].clear();
		cin>>n;cin.ignore();
		
		FOR(i,n) printf("%d ",art_v[i]);
		cout<<endl;
		FOR(i,n) printf("%d ",dfs_low[i]);
		cout<<endl;
		FOR(i,n) printf("%d ",dfs_parent[i]);
		cout<<endl;
		
	}
    
	return 0;
}
