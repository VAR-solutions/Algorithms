#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;

bool sort_by_third(pair<pair<ll,ll>,ll> a1,pair<pair<ll,ll>,ll>  a2)
{
    return a1.second<a2.second;
}class d_set{
  public:
    ll val;
    ll rank;
    ll size;
};
map<ll,class d_set> m;
void make_set(ll value)
{
    class d_set node;
    node.val=value;
    node.rank=0;
    node.size=1;
    m[value]=node;
}
class d_set find_parent(ll value)
{
    class d_set node=m[value];
    if(node.val==value)
        return node;
    else
        return node=find_parent(node.val);
}
void set_union(ll value1,ll value2)
{
    class d_set p1,p2;
    p1=find_parent(value1);
    p2=find_parent(value2);
    if(p1.val==p2.val)
        ;
    else{
    if(p1.rank>p2.rank)
    {
        p1.size=p1.size+p2.size;
        m[p1.val]=p1;
        m[p2.val]=p1;
        
    }
    else if(p1.rank<p2.rank)
    {
        p2.size=p2.size+p1.size;
        m[p2.val]=p2;
         m[p1.val]=p2;
    }
    else
    {
        p1.rank++;
        p1.size=p1.size+p2.size;
        m[p1.val]=p1;
        m[p2.val]=p1;
    }}
}
ll kruskal(vector<pair<pair<ll,ll>,ll>> v)
{
    ll ans=0;
    for(int i=0;i<v.size();++i)
    {
           class d_set p1,p2;
            p1=find_parent(v[i].first.first);
            p2=find_parent(v[i].first.second);
        if(p1.val==p2.val)
            continue;
        else{
            ans+=v[i].second;
            set_union(v[i].first.first,v[i].first.second);
        }
    }
    return ans;
}
int main()
{
    vector<pair<pair<ll,ll>,ll>> v;
    ll node,e,a,b,w;
    cin>>node>>e;
    for(int i=1;i<=node;++i)
        make_set(i);
    for(int i=0;i<e;++i)
    {
        cin>>a>>b>>w;
        v.pb(mp(mp(a,b),w));
        v.pb(mp(mp(b,a),w));
    }
    sort(v.begin(),v.end(),sort_by_third);
    cout<<kruskal(v)<<endl;
}