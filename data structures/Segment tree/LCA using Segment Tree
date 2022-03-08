#include<bits/stdc++.h>
using namespace std;
         
typedef long long ll;
typedef vector<ll> vll;
typedef vector<char> vc;
typedef vector<string> vst;
typedef pair<ll,ll> pll;
typedef pair<char,ll> pcl;
typedef pair<string,ll> psl;
typedef set<ll> sll;
typedef set<char> sc;
typedef set<string> sst;
typedef map<char,ll> mcl;
typedef map<ll,ll> mll;
typedef map<string,ll> msl;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) c.begin(),c.end()
#define fill(a,v) memset(a,v,sizeof a)
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,a,b) for(ll i=a;i>=b;i--)
#define srep(i,s) for(ll i=0;s[i]!='\0';i++)
#define PI 3.1415926535897932384626
#define INF 999999999999999
#define mod 1000000007
#define nn cout<<"\n"
#define sp cout<<" "
#define ifalse ios_base::sync_with_stdio(false),cin.tie(NULL)


inline ll add(ll x, ll y) { x += y; if(x >= mod) x -= mod; return x; }
inline ll sub(ll x, ll y) { x -= y; if(x < 0) x += mod; return x; }
inline ll mul(ll x, ll y) { return ((x % mod) * (y % mod)) % mod; }

inline ll powr(ll a, ll b){
    ll x = 1LL;
    while(b) {
        if(b & 1) x = mul(x, a);
        a = mul(a, a);
        b >>= 1;
    }
    return x;
}

bool check(ll n)
{
    if(n == 1) return 0;
    if(n == 2 or n == 3) return 1;
    if(n % 2 == 0 or n % 3 == 0) return 0;

    for(ll i = 5; i * i <= n; i += 6) if(n % i == 0 or n % (i + 2) == 0) return 0;
    return 1;
}

#define maxN 200005

vector<ll> v[maxN];
vector<ll> euler;
ll first[maxN];
ll height[maxN];
ll seg[4*maxN];

void dfs(ll x,ll p,ll h)
{
    height[x]=h;
    first[x]=euler.size();
    euler.push_back(x);

    for(auto u:v[x])
    {
        if(u==p) continue;
        dfs(u,x,h+1);
        euler.push_back(x);
    }
}

void BUILD(ll node,ll s,ll e)
{
    if(s==e) seg[node]=euler[s];
    else
    {
        ll mid=(s+e)>>1;
        BUILD(node<<1,s,mid);
        BUILD(node<<1|1,mid+1,e);
        seg[node]=height[seg[node<<1]]<height[seg[node<<1|1]]?seg[node<<1]:seg[node<<1|1];
    }
}

ll QUE(ll node,ll s,ll e,ll l,ll r)
{
    if(r<s or l>e) return -1;
    if(l<=s and e<=r) return seg[node];

    ll mid=(s+e)>>1;
    ll p1=QUE(node<<1,s,mid,l,r);
    ll p2=QUE(node<<1|1,mid+1,e,l,r);
    if(p2==-1) return p1;
    if(p1==-1) return p2;
    return height[p1]<height[p2]?p1:p2;
}

ll lca(ll a,ll b)
{
    ll l=first[a],r=first[b];
    if(l>r) swap(l,r);
    return QUE(1,0,euler.size()-1,l,r);
}


int main()
{
    ifalse;
    
    ll n=0;
    cin>>n;
    rep(i,0,n-1)
    {
        ll x,y;
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }

    dfs(1,0,0);
    ll sz=euler.size()-1;
    BUILD(1,0,sz);

    ll q=0;
    cin>>q;
    while(q--)
    {
        ll x,y;
        cin>>x>>y;
        cout<<lca(x,y)<<"\n";
    }
    return 0;
}
