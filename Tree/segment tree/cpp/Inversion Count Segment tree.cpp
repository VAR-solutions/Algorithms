#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll tree[800001],n,sum;
struct nud{
	ll val,id;
}a[200001];
bool cmp(nud n1,nud n2)
{
	if(n1.val==n2.val)
		return n1.id>n2.id;
	return n1.val>n2.val;
}
void query(ll node,ll l,ll r,ll pos)
{
	if(l==r)
	{
		tree[node]++;
		return;
	}
	ll mid=(l+r)/2;
	if(pos<=mid)
	{
		query(2*node,l,mid,pos);
	}
	else{
		sum+=tree[2*node];
		query(2*node+1,mid+1,r,pos);
	}
	tree[node]=tree[2*node]+tree[2*node+1];
}
int main() {
	// your code goes here
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll i,j,k=0;
		sum=0;
		memset(tree,0,sizeof(tree));
		for(i=1;i<=n;i++)
		{
			cin>>a[i].val;
			a[i].id=i;
		}
		sort(a+1,a+n+1,cmp);
		for(i=1;i<=n;i++)
		{
			query(1,1,n,a[i].id);
		}
		cout<<sum<<endl;
	}
	return 0;
}