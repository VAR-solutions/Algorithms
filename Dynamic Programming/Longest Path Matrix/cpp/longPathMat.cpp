#include<bits/stdc++.h>
#define n 3

using namespace std;

int findLongestFromACell(int i, int j, int mat[n][n], int dp[n][n]){
    if (i<0 || i>=n || j<0 || j>=n)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (j<n-1 && ((mat[i][j] +1) == mat[i][j+1]))
       return dp[i][j] = 1 + findLongestFromACell(i,j+1,mat,dp);
    if (j>0 && (mat[i][j] +1 == mat[i][j-1]))
       return dp[i][j] = 1 + findLongestFromACell(i,j-1,mat,dp);
    if (i>0 && (mat[i][j] +1 == mat[i-1][j]))
       return dp[i][j] = 1 + findLongestFromACell(i-1,j,mat,dp);
    if (i<n-1 && (mat[i][j] +1 == mat[i+1][j]))
       return dp[i][j] = 1 + findLongestFromACell(i+1,j,mat,dp);
    return dp[i][j] = 1;
}

int finLongestOverAll(int mat[n][n]){
    int result = 1;
    int dp[n][n];
    memset(dp, -1, sizeof dp);
    for (int i=0; i<n; i++){
      for (int j=0; j<n; j++){
          if (dp[i][j] == -1)
             findLongestFromACell(i, j, mat, dp);
          result = max(result, dp[i][j]);
       }
     }
     return result;
}

int main(){ 
   int  mat[n][n] = {{1, 2, 9},
                    {5, 3, 8},
                    {4, 6, 7}};
   cout << "Length of the longest path is "<< finLongestOverAll(mat)<<endl;
   return 0;
}
