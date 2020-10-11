/*
Kosaraju's Double Pass Algorithm to find Strongly Connected Components

Resources to learn: https://www.geeksforgeeks.org/strongly-connected-components/

Input format:
n - number of nodes
m - number of edges
u, v - edge from u to v

Output format:
List of Strongly connected components in every line
*/
#include<bits/stdc++.h>
/*-------------------------------------------------------- */
using namespace std;

/*-------------------------------------------------------- */

#define rep(i,val,n) for(ll i=val;i<n;i++)
#define per(j,val,n) for(ll j=val;j>=n;j--)
#define pb push_back
#define pi 3.14157
#define mp make_pair
#define MODULO 1000000007
#define INF 1000000000000000
#define fastread ios_base::sync_with_stdio(false); cin.tie(NULL);


/*-------------------------------------------------------- */

typedef long long ll;
typedef vector<bool> boolean;
typedef vector<ll> vec;


/*-------------------------------------------------------- */

ll gcd(ll a, ll b)
{
	if(b == 0)
	{
		return a;
	}
	return gcd(b, a%b);
}

ll lcm(ll a, ll b)
{
	return ((a*b)/gcd(a,b));
}

/*-------------------------------------------------------- */
stack<ll> S;
void dfs(vec *adj, boolean &visited, ll s)
{
    visited[s] = true;
    vec::iterator it;
    for(it = adj[s].begin(); it != adj[s].end(); it++)
    {
        if(visited[*it] == false)
        {
            dfs(adj, visited, *it);
        }
    }
    S.push(s);
}

void dfs_again(vec *revadj, boolean &visited_again, ll s)
{
    visited_again[s] = true;
    cout<<s<<" ";
    vec::iterator it;
    for(it = revadj[s].begin(); it != revadj[s].end(); it++)
    {
        if(visited_again[*it] == false)
        {
            dfs_again(revadj, visited_again, *it);
        }
    }
}
void kosaraju(vec *revadj, ll n)
{
    boolean visited_again(n, false);
    while(!S.empty())
    {
        ll start = S.top();
        S.pop();
        if(visited_again[start] == false)
        {
            dfs_again(revadj, visited_again, start);
            cout<<endl;
        }
    }

}
int main()
{
	fastread;
    ll n, m, u, v;
    cin>>n>>m;
    vec *adj = new vec[n];
    vec *revadj = new vec[n];
    rep(i,0,m)
    {
        cin>>u>>v;
        adj[u].pb(v);
        revadj[v].pb(u);
    }
    boolean visited(n, false);
    rep(i,0,n)
    {
        if(visited[i] == false)
        {
            dfs(adj, visited, i);
        }
    }
    boolean visited_again(n, false);
    kosaraju(revadj, n);
	return 0;
}
