#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define N 200002
vector<int> v[N];
vector<int> ans[N];
vector<int> an[N];
int P[N][19];
int pos[N][2];
ll a[N];
ll b[N];
bool vis[N];
int L[N]={0};
int par[N]={0};
int sub[N];
vector<int> chain[N];
int cn=0;

int n,m,x,y;
void dfs(int u,int p)
{
    L[u]=L[p]+1;
    vis[u]=1;
    par[u]=p;
    for(int i=0;i<v[u].size();i++)
    {
        if(!vis[v[u][i]])
        {
            dfs(v[u][i],u);
            sub[u]+=sub[v[u][i]];
            sub[u]++;
        }
    }
    
}
void hld(int x)
{
    pos[x][0]=cn;
    pos[x][1]=chain[cn].size();
    chain[cn].push_back(x);
    ans[cn].push_back(0);
    an[cn].push_back(0);
    
    int mx=0;
    for(int i=0;i<v[x].size();i++)
    {
        if(v[x][i]!=par[x])
        mx=max(mx,sub[v[x][i]]);
    }

    for(int i=0;i<v[x].size();i++)
    {

        if(sub[v[x][i]]==mx)
        {
            hld(v[x][i]);
            sub[v[x][i]]=-1;
            break;

        }
    }

    for(int i=0;i<v[x].size();i++)
    {

        if(v[x][i]!=par[x] && sub[v[x][i]]!=-1)
        {

            cn++;
            hld(v[x][i]);
        }
    }


}

void pro()
  {
      int i, j;
   par[0]=0;
    par[1]=1;
      for (i = 0; i <=n; i++)
          for (j = 0; 1 << j <=n; j++)
              P[i][j] = -1;
   
      for (i = 0; i <=n; i++)
          P[i][0] = par[i];
   
      for (j = 1; 1 << j <=n; j++)
         for (i = 0; i <=n; i++)
             if (P[i][j - 1] != -1)
                 P[i][j] = P[P[i][j - 1]][j - 1];
  }
 
 int lca(int p, int q)
  {
      int tmp, log, i;
   
      if (L[p] < L[q])
          tmp = p, p = q, q = tmp;
  
      for (log = 1; 1 << log <= L[p]; log++);
      log--;
   
      for (i = log; i >= 0; i--)
          if (L[p] - (1 << i) >= L[q])
              p = P[p][i];
   
      if (p == q)
          return p;
   
      for (i = log; i >= 0; i--)
          if (P[p][i] != -1 && P[p][i] != P[q][i])
              p = P[p][i], q = P[q][i];
   
      return par[p];
  }



int main()
{
    cin>>n;
    memset(vis,false,sizeof vis);
    memset(vis,false,sizeof vis);
  
    for(int i=1;i<=n;i++)cin>>a[i];
    
    for(int i=1;i<=n;i++)cin>>b[i];
    
    for(int i=1;i<n;i++)
    {
        
        cin>>x>>y;
       // cout<<x<<y<<endl;
        v[x].push_back(y);
        v[y].push_back(x);
        
    }
    L[1]=0;
    dfs(1,0);
    //cout<<n<<" "<<par[n]<<endl;
    hld(1);
    pro();
    
     int i,j,k,c,t=0;
    cin>>m;
   int w;
  
    while(m--)
    {
        cin>>c>>x>>y;
        int z=lca(x,y);
        if(c==1)
        {
           
            while(pos[x][0]!=pos[z][0])
            {
                

                t=chain[pos[x][0]][0];
                j=pos[t][0];
                k=pos[t][1];
                
                ans[j][k]+=1;
                j=pos[x][0];
                k=pos[x][1]+1;
                ans[j][k]-=1;
                x=par[t];
                
            }
            if(x!=z)
            {
                w=chain[pos[z][0]][pos[z][1]+1];
                j=pos[w][0];
                k=pos[w][1];
                ans[j][k]+=1;
                j=pos[x][0];
                k=pos[x][1]+1;
                ans[j][k]-=1;
                               
                
            }
            while(pos[y][0]!=pos[z][0])
            {
                t=chain[pos[y][0]][0];
                j=pos[t][0];
                k=pos[t][1];
                ans[j][k]+=1;
                j=pos[y][0];
                k=pos[y][1]+1;
                ans[j][k]-=1;
                                
                y=par[t];


            }
            if(y!=z)
            {
                
               w=chain[pos[z][0]][pos[z][1]+1];
                
                j=pos[w][0];
                k=pos[w][1];
                ans[j][k]+=1*1ll;
                j=pos[y][0];
                k=pos[y][1]+1;
                ans[j][k]-=1;
                               
                

            }
            ans[pos[z][0]][pos[z][1]]+=1;
            ans[pos[z][0]][pos[z][1]+1]-=1;


        }
        else
        {
            
            while(pos[x][0]!=pos[z][0])
            {

                t=chain[pos[x][0]][0];
                j=pos[t][0];
                k=pos[t][1];
                
                an[j][k]+=1;
                j=pos[x][0];
                k=pos[x][1]+1;
                an[j][k]-=1;
                x=par[t];

            }
            if(x!=z)
            {
                w=chain[pos[z][0]][pos[z][1]+1];
               
                j=pos[w][0];
                k=pos[w][1];
                an[j][k]++;
                j=pos[x][0];
                k=pos[x][1]+1;
                an[j][k]--;
                
            }
            while(pos[y][0]!=pos[z][0])
            {
                t=chain[pos[y][0]][0];
                j=pos[t][0];
                k=pos[t][1];
                
                an[j][k]++;
                j=pos[y][0];
                k=pos[y][1]+1;
                an[j][k]--;    
                y=par[t];

            }
            if(y!=z)
            {
                w=chain[pos[z][0]][pos[z][1]+1];
                j=pos[w][0];
                k=pos[w][1];
                an[j][k]++;
                j=pos[y][0];
                k=pos[y][1]+1;
                an[j][k]--;       
            }
            an[pos[z][0]][pos[z][1]]++;
            an[pos[z][0]][pos[z][1]+1]--;


        }
    }
   for(i=0;i<=cn;i++)
    {
        for( j=0;j<ans[i].size();j++)
        {
            if(j>=1)
            {
            ans[i][j]+=ans[i][j-1];
            an[i][j]+=an[i][j-1];
            }
        }
    }
    for(i=0;i<=cn;i++)
    {
        for(j=0;j<ans[i].size();j++)
        {
            a[chain[i][j]]*=(ll)ans[i][j];
            b[chain[i][j]]*=(ll)an[i][j];
        }
    }
   for(int i=1;i<=n;i++)
    {
    	
    	a[i]+=b[i];
    	cout<<a[i]<<" ";
    }
    
    
    return 0;
}
