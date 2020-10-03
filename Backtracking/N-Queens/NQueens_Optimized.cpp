#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007;
using namespace std;
int c=0;
int column[100]={0},d1[100]={0},d2[100]={0};
//Use  bool or int for optimization 
void solve(int i,int n)
{
    if(i==n)
    {
        c++;
        return ;
    }
    for(int j=0;j<n;j++)
    {
        if(column[j]==0&&d1[i-j+n-1]==0&&d2[i+j]==0)
        {
            column[j]=1;
            d1[i-j+n-1]=1;
            d2[i+j]=1;
            solve(i+1,n);
            column[j]=0;
            d1[i-j+n-1]=0;
            d2[i+j]=0;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    solve(0,n);
    cout<<c<<endl;
    return 0;
}
