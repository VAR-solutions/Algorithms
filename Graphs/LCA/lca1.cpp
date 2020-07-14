// Efficient method to find LCA.

// Efficient method to find LCA.

#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

#define ll long long

#define rep(i,a,b) for(ll i=a;i<b;i++)

#define pb push_back

const ll logN = 20;
const ll N = 100005;

ll dp[2*N][logN],euler[2*N],level[2*N],first[N];
vector<ll> adj[N];
ll n,cnt=0;

void dfs(ll node,ll par,ll lev){ 
    euler[cnt]=node;
    level[cnt]=lev;
    cnt++;
    for(auto i:adj[node]){
        if(i!=par){  
            dfs(i,node,lev+1);
            euler[cnt]=node;
            level[cnt]=lev;
            cnt++;
        }
    }
}

void fillsparse(){
    rep(i,0,2*n-1)  dp[i][0]=i;
    rep(i,1,logN){
    	ll p = 1<<i;
        for(ll j=0;j+(1<<i)<2*n;j++){
            if(level[dp[j][i-1]]<level[dp[j+(1<<(i-1))][i-1]])
                dp[j][i]=dp[j][i-1];
            else
                dp[j][i]=dp[j+(1<<(i-1))][i-1];
        }
    }  
}

ll lca(ll u,ll v){
    ll l = first[u];
    ll r = first[v];
    if(l>r) swap(l,r);
    ll d = r - l;
    ll k = log2(d);
    if(l==r)    return  euler[l];
    if(level[dp[l][k]]>level[dp[r-(1<<k)+1][k]])    
        return euler[dp[r-(1<<k)+1][k]];
    return euler[dp[l][k]];
}


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    rep(i,0,n-1){
    	ll u,v;
    	cin>>u>>v;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }
    cnt=0;dfs(1,0,1);
    rep(i,1,n+1)  first[i]=-1;;
    rep(i,0,2*n-1)
        if(first[euler[i]]==-1) first[euler[i]]=i;
    fillsparse();
    ll q;
    cin>>q;
    rep(i,0,q){
    	ll u,v;
    	cin>>u>>v;
    	ll lca1 = lca(u,v);
    	cout<<lca1<<endl;
    }
    return 0;
}
