#include<bits/stdc++.h>
#define maxn 100001
using namespace std;
vector<int>v[maxn],arr[maxn],t[maxn];
int p[maxn],d[maxn],sz[maxn],nxt[maxn],a[maxn],chain[maxn],szc[maxn],st[maxn],top[maxn],nd=0,tim=0,seg[4*maxn+1],lazy[4*maxn+1],n;
int dfs(int s,int r)
{
    p[s]=r;
    d[s]=d[r]+1;
    sz[s]=1;
    for(int i=0;i<t[s].size();i++)
    {
        int x=t[s][i];
        if(x==r)
        continue;
        sz[s]+=dfs(x,s);
        if(nxt[s]==-1 || sz[x]>sz[nxt[s]])
            nxt[s]=x;
    }
    return sz[s];
}
void hld(int s,int pp=0)
{
    chain[s]=nd;
      st[s]=++tim;
     if(!szc[nd])
      {top[nd]=s;}
      szc[nd]++;
 
     if(nxt[s]!=-1)
     hld(nxt[s],s);
 
    for(int i=0;i<t[s].size();i++)
    {
        int x=t[s][i];
        if(x==pp || x==nxt[s])
            continue;
        nd++;
        hld(x,s);
    }
 
}
void update(int x,int st,int en,int l,int r,int val)
{
    if(lazy[x])
    {
          seg[x]=lazy[x];
           if(st!=en)
           {
          if(!seg[2*x])
          lazy[2*x]=lazy[x];
          if(!seg[2*x+1])
          lazy[2*x+1]=lazy[x];
            }
          lazy[x]=0;
    }
    if(l>en || r<st || l>r || seg[x])
        return ;
    if(l<=st && en<=r)
    {
       seg[x]=val;
      if(st!=en)
      {
          if(!seg[2*x])
          lazy[2*x]=val;
          if(!seg[2*x+1])
          lazy[2*x+1]=val;
      }
      return ;
    }
    int mid=(st+en)/2;
    update(2*x,st,mid,l,r,val);
    update(2*x+1,mid+1,en,l,r,val);
    if(seg[2*x] && seg[2*x+1] && !seg[x])
    seg[x]=seg[2*x];
}
void go(int x,int y,int val)
{
    int sx=st[x],sy=st[y],sny,snx;
    while(chain[x]!=chain[y])
    {
        if(d[top[chain[x]]]<d[top[chain[y]]])swap(x,y);
        snx=st[x];
        if(st[x]==sx || st[x]==sy)snx=st[x]-1;
        update(1,1,n,st[top[chain[x]]],snx,val);
        x=p[top[chain[x]]];
    }
     if(d[x]>d[y])swap(x,y);
     snx=st[x];sny=st[y];
     if(st[x]==sx || st[x]==sy)snx=st[x]+1;
     if(st[y]==sx || st[y]==sy)sny=st[y]-1;
     update(1,1,n,snx,sny,val);
}
int qry(int x,int l,int r,int ind)
{
     if(lazy[x])
     {
          seg[x]=lazy[x];
           if(l!=r)
           {
          if(!seg[2*x])
          lazy[2*x]=lazy[x];
          if(!seg[2*x+1])
          lazy[2*x+1]=lazy[x];
            }
          lazy[x]=0;
     }
   if(ind<l || ind>r)
    return 0;
 
   if(l==r)
    return seg[x];
   int mid=(l+r)/2;
   return (qry(2*x,l,mid,ind)+qry(2*x+1,mid+1,r,ind));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int x,y;
   for(int i=1;i<=maxn;i++)
   for(int j=i;j<=maxn;j+=i)
    v[j].push_back(i);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        for(int j=0;j<v[a[i]].size();j++)
        arr[v[a[i]][j]].push_back(i);
    }
    for(int i=1;i<=n-1;i++)
    {
        cin>>x>>y;
        t[x].push_back(y);
        t[y].push_back(x);
    }
    memset(p,-1,sizeof(p));
    memset(nxt,-1,sizeof(nxt));
    memset(chain,-1,sizeof(chain));
    dfs(1,0);p[1]=-1;
    hld(1);
    for(int i=maxn;i>=1;i--)
    if(arr[i].size()>1)
    {
 
         x=arr[i][0];y=arr[i][arr[i].size()-1];
        for(int j=1;j<arr[i].size();j++)
           go(x,arr[i][j],i);
 
        for(int j=max((int)arr[i].size()-10,0);j<arr[i].size()-1;j++)
       go(y,arr[i][j],i);
    }
    for(int i=1;i<=n;i++)
        cout<<qry(1,1,n,st[i])<<" ";
        cout<<endl;
}
