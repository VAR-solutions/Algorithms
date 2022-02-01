#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

//print with endl
template <typename Arg1>
void pf(Arg1&& arg1)
{ cout<<arg1<<"\n";}
template <typename Arg1, typename... Args>
void pf(Arg1&& arg1, Args&&... args)
{ cout<<arg1<<"\n"; pf(args...); }

//print with space
template <typename Arg1>
void ps(Arg1&& arg1)
{ cout<<arg1<<" ";}
template <typename Arg1, typename... Args>
void ps(Arg1&& arg1, Args&&... args)
{ cout<<arg1<<" "; ps(args...); }

//printing via for loop
template <typename Arg1>
void pvs(Arg1&& arg1, ll n)
{ for(ll i=0;i<n;i++)ps(arg1[i]); }
template <typename Arg1>
void pvn(Arg1&& arg1, ll n)
{ for(ll i=0;i<n;i++)ps(arg1[i]); }



ll lcm(ll a,ll b) 
{ return (a*b)/__gcd(a,b); }


#define fast  ios::sync_with_stdio(false); cin.tie(NULL);  cout.tie(NULL);
#define MOD 1000000007 
#define MAX 1e9
#define MIN -1e9
#define rep0(i,n) for(i=0;i<n;i++)
#define rep1(i,n) for(i=1;i<=n;i++)
#define repr(i,n) for(i=n-1;i>=0;i--)
#define pb push_back
#define mp make_pair 
#define all(a) a.begin(),a.end()
#define vl vector<ll>
#define vll vector<vl>
#define vs vector<string>
#define pl pair<ll,ll>
#define vpl vector<pl>
#define f first
#define s second
#define um unordered_map
vl l[101];
ll v[101],d[101];
ll in_node[101];
vl res;
bool kahn(ll n)
{
	ll i,j;
	priority_queue<ll,vl,greater<ll>> pq;
	for(i=1;i<=n;i++)
	{
		if(in_node[i]==0)
		pq.push(i);
    }
	while(!pq.empty())
	{
		ll curr=pq.top();
		res.pb(curr);
		pq.pop();
		for(auto node: l[curr])
		{
			in_node[node]--;
			if(in_node[node]==0)
			pq.push(node);
		}
	}
	
	// condition for cyclic graphs
    if(res.size()==n)
	return true;
	else
	return false; // cyclic graph
}
void solve()
 {
     ll n,m,i,j;
	 cin>>n>>m;
	 while(m--)
	 {
		 ll x,y;
		 cin>>x>>y;
		 l[x].pb(y);
         in_node[y]++;
	 }
	if(kahn(n)) 
	{
        
	 for(i=0;i<res.size();i++)
	   cout<<res[i]<<" ";
	}

 }
int main()
{
    fast;
	// ll t;
	// cin>>t;
	// while(t--)
	// {
	   solve();
	//}
}

