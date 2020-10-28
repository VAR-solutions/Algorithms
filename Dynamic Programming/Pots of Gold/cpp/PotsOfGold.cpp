// Full problem Statement: https://practice-stage.geeksforgeeks.org/problems/pots-of-gold-game/1

#include <bits/stdc++.h>
using namespace std;

int maxCoins(int A[],int N)
{
    int n=N;
    int dp[N][N];
    memset(dp,0,sizeof(dp));
    for(int gap=0;gap<n;gap++){
        for(int i=0,j=i+gap;i<n && j<n;i++,j++){
            if(gap==0)
            dp[i][j]=A[i];
            else if(gap==1)
            dp[i][j] = max(A[i],A[j]);
            else{
                dp[i][j] = max(A[i]+min(dp[i+2][j],dp[i+1][j-1]),
                               min(dp[i][j-2],dp[i+1][j-1])+A[j]);
            }
        }
        
    }
    return dp[0][n-1];
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
			cin>>a[i];		
		cout<<maxCoins(a,n)<<endl;		
	}
	return 0;
}
