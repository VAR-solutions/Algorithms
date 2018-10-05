/ calculating minimum total sum of a minimum spanning tree formed from a graph


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

vector<pii> ad[100005];
// p stores parent of each node and c stores size of subtree of each node
vector<ll> p(100005, -1);
vector<ll> c(100005, 1);

// calculates the root of each tree
ll parent(ll v)
{
	if(p[v] == -1)
		return v;
	p[v] = parent(p[v]);
	return p[v];
}

// checking if v1 and v2 are already connected
bool cycle(ll v1, ll v2)
{
	if(parent(v1) == parent(v2))
		return true;
	else
	{
		ll x1 = parent(v1);
		ll x2 = parent(v2);
		// making root of larger tree the parent of smaller tree and updating its subtree size
		if(c[x1] <= c[x2])
		{
			p[x1] = x2;
			c[x2] += c[x1];
		}
		else
		{
			p[x2] = x1;
			c[x1] += c[x2];
		}
		return false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n, m;
	// n is number of vertices and m is number of edges in the graph
	cin >> n >> m;
	ll i;
	set< pair <ll, pii> > x;
	ll ans = 0;
	for(i = 0 ; i < m ; i ++)
	{
		// there is an edge from a to b with weight c
		ll a, b, c;
		cin >> a >> b >> c;
		ad[a].pb(mp(b, c));
		ad[b].pb(mp(a, c));
		x.insert(mp(c, mp(a, b)));
		// inserting edges inside a set
	}
	i = 0;
	// iterating edges in ascending order of their weights
	for(auto it = x.begin() ; it != x.end() ; it++)
	{
		ll v1 = (*it).second.first;
		ll v2 = (*it).second.second;
		// if v1 and v2 are not connected then add that edge weight in answer
		if(!cycle(v1,v2))
		{
			i ++;
			ans += (*it).first;
		}
		// if number of edges = n - 1 (equal to number of edges in the tree then break)
		if(i == n - 1)
			break;
	}
	cout << ans << endl;
	return 0;
}
