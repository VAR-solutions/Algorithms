#include <bits/stdc++.h>
using namespace std;
int arr[1000];
int siz[1000];
void build()
{
for(int i=1;i<=1000;i++)
{
    arr[i]=i;
    siz[i]=1;
}    
}
int root(int i)
{
    while(i!=arr[i])
    {
        arr[i]=arr[arr[i]]; //for path compression
        i=arr[i];
    }
    return i;
}
int rootsimple(int i)
{
    while(i!=arr[i])
    {
        i=arr[i];
    }
    return i;
}
void unionn(int a,int b)
{
    int roota= root(a);
    int rootb=root(b);
    
    if(siz[rootb]>siz[roota])
 {   arr[roota]=arr[rootb];
    siz[rootb]=siz[rootb]+siz[roota];
}
else
{
    arr[rootb]=arr[roota];
    siz[roota]=siz[roota]+siz[rootb];
}
    
}
bool find(int a,int b)
{
    int roota=root(a);
    int rootb= root(b);
    if(roota==rootb) return true;
    else return false;
}
int main() {

   int n,e,q;
   cin>>n>>e>>q;
   int x,y;
   build();
   for(int i=0;i<e;i++)
   {
       cin>>x>>y;
       unionn(x,y);
       
   }
   bool ans[q];
for(int i=0;i<q;i++)
   {
       cin>>x>>y;
       ans[i]=find(x,y);
       
   }
   
   for(int i=0;i<q;i++)
   {
       cout<<ans[i]<<endl; }
   
}