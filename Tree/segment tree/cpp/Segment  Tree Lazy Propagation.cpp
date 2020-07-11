#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll tree[400001],tree1[400001];
void lazy(ll node,ll l,ll r)
{
	tree[node]+=tree1[node]*(r-l+1);
	if(l==r)
	{
		tree1[node]=0;
		return;
	}
	tree1[2*node]+=tree1[node];
	tree1[2*node+1]+=tree1[node];
	tree1[node]=0;
}
ll q0(ll node,ll l,ll r,ll l1,ll r1,ll val=0){
	//cout<<val<<endl;
	lazy(node,l,r);
	if(l1<=l&&r<=r1)
	{
		tree1[node]+=val;
		lazy(node,l,r);
		//cout<<tree[node]<<" ";
		return tree[node];
	}
	else if(r<l1||r1<l)
	{
		return 0;
	}
	else{
		ll mid=(l+r)/2;
 
		ll x1=q0(2*node,l,mid,l1,r1,val);
		ll x2=q0(2*node+1,mid+1,r,l1,r1,val);
		tree[node]=tree[2*node]+tree[2*node+1];
		return x1+x2;
	}
}
int main() {
	// your code goes here
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,m;
		cin>>n>>m;
		ll i,j,k;
		memset(tree,0,sizeof(tree));
		memset(tree1,0,sizeof(tree1));
		while(m--)
		{
			ll x,p,q,v;
			cin>>x;
			if(x==0)
			{
				cin>>p>>q>>v;
				q0(1,1,n,p,q,v);
			}
			else{
				cin>>p>>q;
				cout<<q0(1,1,n,p,q)<<endl;
			}
		}
	}
	return 0;
}