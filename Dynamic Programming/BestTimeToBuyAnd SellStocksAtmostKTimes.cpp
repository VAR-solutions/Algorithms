/*Given an array of integers A of size N in which ith element is the price of the stock on day i.

You can complete atmost B transactions.

Find the maximum profit you can achieve.

NOTE: You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

*/

      int dp[2000][2][1000];
int recur(vector<int> &A, int B,int st,int p,int n)
{
      if(p==0 && B == 0){
          dp[st][p][B] = 0;
    return 0;
      }
    
    if(dp[st][p][B]!=-1)
    return dp[st][p][B];
    
    if(st == n-1)
    {
        if(p==1){
            dp[st][p][B] = A[st];
        return A[st];
        }
        dp[st][p][B] = 0;
        return 0;
    }
    
    if(p == 0){
        dp[st][p][B] = max(recur(A,B-1,st+1,1,n)-A[st],recur(A,B,st+1,0,n));
    }
    if(p == 1){
        dp[st][p][B] = max(recur(A,B,st+1,1,n),A[st]+recur(A,B,st+1,0,n));
    }
    
    return dp[st][p][B];
    
    
}

int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    B = min(B,n/2);
   for(int i  =0;i<n;i++)
        {
            for(int j  =0;j<2;j++)
            {
                for(int K  =0;K<B+1;K++)
                    dp[i][j][K] = -1;
            }
        }
    return recur(A,B,0,0,n);
}
