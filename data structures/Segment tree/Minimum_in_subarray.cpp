#include<bits/stdc++.h>
using namespace std;

void buildtree(int *a,int *tree,int st,int end,int ind)
{
    if(st==end)
    {
        tree[ind]=a[st];
        return;
    }
    int mid=(st+end)/2;
    
    buildtree(a,tree,st,mid,2*ind+1);
    buildtree(a,tree,mid+1,end,2*ind+2);
    
    tree[ind]=min(tree[2*ind+1],tree[2*ind+2]);
}

void update(int* a,int* tree,int st,int end,int ind,int req,int val)
{
    if(st==end)
    {
        a[req]=val;
        tree[ind]=val;
        return;
    }
    int mid=(st+end)/2;
    if(req>mid)
        update(a,tree,mid+1,end,2*ind+2,req,val);
    else
        update(a,tree,st,mid,2*ind+1,req,val);
    tree[ind]=min(tree[2*ind+1],tree[2*ind+2]);
}

int query(int* tree,int st,int end,int ind,int left,int right)
{
    if(st>right or end<left)
        return INT_MAX;
    
     if(st>=left and end<=right)
        return tree[ind];
    

        int mid=(st+end)/2,a1,a2;
        a1=query(tree,st,mid,2*ind+1,left,right);
        a2=query(tree,mid+1,end,2*ind+2,left,right);
        return min(a1,a2);
    
    
}

int main() {
    int n,q;
    cin>>n>>q;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int *tree=new int[4*n];
    buildtree(a,tree,0,n-1,0);
    while(q--)
    {
        char x;
        cin>>x;
        int l,r;
        cin>>l>>r;
        if(x=='q')
        {
            cout<<query(tree,0,n-1,0,l-1,r-1)<<"\n";
        }
        else
        {
            update(a,tree,0,n-1,0,l-1,r);
        }
    }
}
