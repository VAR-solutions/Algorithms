//Lazy propagation is used to perform range updates on segment tree efficiently.
//Given an array all elements initialized to zero.
//2 types of queries:
//type1: add a value to all the elements of array in given range of indices
//type2: find the maximum element of the array in the given range of indices

#include<bits/stdc++.h>
#define endl "\n"
#define ll long long int
#define N (ll)(1e9+7)
#define T ll
#define P pair<T,T>
#define umap unordered_map<T,T>
#define uset unordered_set<T>
#define rep(i,n) for(i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define print(v) for(auto x:v) cout<<x<< " "
#define pb push_back
using namespace std;

ll *tree,*lazy;

void update(ll v,ll start,ll End,ll l,ll r,ll val)
{
	if(lazy[v]!=0)
	{
		tree[v]+=lazy[v];
		if(start!=End)
		{
			lazy[2*v]+=lazy[v];
			lazy[2*v+1]+=lazy[v];
		}
		lazy[v]=0;
	}

	if(start>r || End<l)
		return;
	if(start>=l && End<=r)
	{
		tree[v]+=val;
		if(start!=End)
		{
			lazy[2*v]+=val;
			lazy[2*v+1]+=val;
		}
		return;
	}
	ll mid=start+(End-start)/2;
	update(2*v,start,mid,l,r,val);
	update(2*v+1,mid+1,End,l,r,val);
	tree[v]=max(tree[2*v],tree[2*v+1]);
}

ll query(ll v,ll start,ll End,ll l,ll r)
{
	if(start>r || End<l)
		return INT_MIN;
	if(lazy[v]!=0)
	{
		tree[v]+=lazy[v];
		if(start!=End)
		{
			lazy[2*v]+=lazy[v];
			lazy[2*v+1]+=lazy[v];
		}
		lazy[v]=0;
	}
	if(start>=l && End<=r)
		return tree[v];
	ll mid=start+(End-start)/2;
	ll p1=query(2*v,start,mid,l,r);
	ll p2=query(2*v+1,mid+1,End,l,r);
	return max(p1,p2);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n,q;
    cin>>n>>q;
    ll i;
   
   
    tree=new ll[4*n+5];
    lazy=new ll[4*n+5];
    rep(i,4*n+5)
    {
    	tree[i]=0;
    	lazy[i]=0;
    }

    while(q--)
    {
    	ll type;
    	cin>>type;
    	if(type==1)
    	{
    		ll l,r,v;
    		cin>>l>>r>>v;
    		update(1,0,n-1,l,r,v);
    	}
    	else
    	{
    		ll l,r;
    		cin>>l>>r;
    		cout<<query(1,0,n-1,l,r)<<endl;
    	}
    }

    return 0;
}

