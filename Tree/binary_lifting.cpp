//Binary Lifting algorithm
//Find the Lowest common ancestor (LCA) using binary lifting approach
//Preprocess: O(nlogn), Query: O(logn)

#include<bits/stdc++.h>
#define endl "\n"
#define ll long long int
#define N (ll)(1e9+7)
#define T int
#define P pair<T,T>
#define umap unordered_map<T,T>
#define uset unordered_set<T>
#define rep(i,n) for(i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define print(v) for(auto x:v) cout<<x<< " "
#define pb push_back
using namespace std;

const int M=1e5+5;
const int lgn=20;
int level[M],par[M];
int dp[M][lgn+1];
vector<int> adj[M];

//run dfs and find the levels of all the vertices

void dfs(int u,int par,int d)
{
  	level[u]=d;
  	for(auto x:adj[u])
  	{
    		if(x!=par)
    			dfs(x,u,d+1);
  	}
}

/*** preprocess for binary lifting algo *****/
//Runtime: O(nlogn)

void preprocess(int n)
{
    int i,j;
    memset(dp,-1,sizeof(dp));
    for(i=0;i<n;i++)
       dp[i][0]=par[i];
    for(j=1;j<=lgn;j++)
    {
        for(i=0;i<n;i++)
        {
            if(dp[i][j-1]!=-1)
              dp[i][j]=dp[dp[i][j-1]][j-1];
        }
    }
}

//find the LCA using binary lifting
//Runtime: O(logn)

int lca(int a,int b)
{
  	if(level[a]<level[b])
  		swap(a,b);
  	int i;
  	for(i=lgn;i>=0;i--)
  	{
    		if(level[a]-(1<<i)>=level[b])
    		{
    			a=dp[a][i];
    		}
  	}
  	if(a==b)
  		return a;
  	for(i=lgn;i>=0;i--)
  	{
    		if(dp[a][i]!=-1 && dp[a][i]!=dp[b][i])
    		{
      			a=dp[a][i];
      			b=dp[b][i];
    		}
  	}
  	return par[a];
}


//driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;  //number of vertices of the tree
    cin>>n;
    
    int i,j;

    //(n-1) edges of the tree
    rep(i,n-1)
    {
      	cin>>par[i+1];
      	adj[i+1].pb(par[i+1]);
      	adj[par[i+1]].pb(i+1);
    }
    
    preprocess(n);
   
    dfs(0,-1,0);
    
    int u,v;    //we have to find the LCA of vertices u and v
    cin>>u>>v;
    cout<<lca(u,v)<<endl;
    return 0;
}
