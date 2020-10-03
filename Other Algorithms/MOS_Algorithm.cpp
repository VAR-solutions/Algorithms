#include <bits/stdc++.h>
using namespace std;
struct query
{
  int l;
  int r;
  int k;
  int ind;
};
int sqn;
int com(query a,query b)
{
    if((a.l)/sqn<(b.l)/sqn) return 1;
    else if((a.l)/sqn==(b.l)/sqn&&a.r<b.r) return 1;
    else return 0;
}

int main() {
cin.sync_with_stdio(false);

int t;
cin>>t;

for(int o=1;o<=t;o++)
{
 
int n,q;
cin>>n>>q;
	sqn = sqrt(n);
int a[n+1];
int ri[n+1];
int li[n+1];
int b[n+1];
query qu[q];
b[0]=0;
for(int i=1;i<=n;i++) {cin>>a[i]; b[i]=0;}
ri[1]=1;
for(int i=2;i<=n;i++) 
{
    if(a[i]==a[i-1]) ri[i]=ri[i-1]+1;
    else ri[i]=1;
}
li[n]=1;
for(int i=n-1;i>=1;i--) 
{
    if(a[i]==a[i+1]) li[i]=li[i+1]+1;
    else li[i]=1;
}

//for(int i=1;i<=n;i++) cout<<a[i]<<" ";cout<<endl;
//for(int i=1;i<=n;i++) cout<<ri[i]<<" ";cout<<endl;
//for(int i=1;i<=n;i++) cout<<li[i]<<" ";cout<<endl;


int l,r,k;
for(int i=0;i<q;i++)
{
    cin>>l>>r>>k;
    qu[i].l=l;
    qu[i].r=r;
    qu[i].k=k;
    qu[i].ind=i;
}
sort(qu,qu+q,com);

int cl=   qu[0].l;
int cr=cl-1;
int ans[q];
//for(int i=1;i<=3;i++) cout<<b[i]<<" ";cout<<endl;
for(int i=0;i<q;i++)
{
l=    qu[i].l;
r= qu[i].r;
    
    
    while(cl<l)
    {
        //cout<<"pehla"<<endl;
        if(li[cl]>cr-cl+1)
        b[cr-cl+1]--;
        else
        b[li[cl]]--;
        cl++;
        //for(int i=1;i<=3;i++) cout<<b[i]<<" ";cout<<endl;
    }
    
    while(cl>l)
    {
        //cout<<"duja"<<endl;
        cl--;
        if(li[cl]>cr-cl+1)
        b[cr-cl+1]++;
        else
        b[li[cl]]++;
        //for(int i=1;i<=3;i++) cout<<b[i]<<" ";cout<<endl;
        
    }
    
    while(cr<r)
    {
        //cout<<"teeja"<<endl;
        cr++;
        if(ri[cr]>cr-cl+1)
        b[cr-cl+1]++;
        else
        b[ri[cr]]++;
        //for(int i=1;i<=3;i++) cout<<b[i]<<" ";cout<<endl;
    }
    
    while(cr>r)
    {
        //cout<<"choutha"<<endl;
        if(ri[cr]>cr-cl+1)
        b[cr-cl+1]--;
        else
        b[ri[cr]]--;
        cr--;
        //for(int i=1;i<=3;i++) cout<<b[i]<<" ";cout<<endl;
    }
    
    ans[qu[i].ind]=b[qu[i].k];
}
for(int i=0;i<q;i++)
cout<<ans[i]<<endl;

}
}