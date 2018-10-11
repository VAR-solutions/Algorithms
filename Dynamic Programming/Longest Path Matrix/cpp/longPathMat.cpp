#include<bits/stdc++.h>
#define max 1000

using namespace std;

int findLongestFromACell(int i, int j, int mat[max][max], int dp[max][max], int n){
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

int finLongestOverAll(int mat[max][max], n){
    int result = 1;
    int dp[n][n];
    memset(dp, -1, sizeof dp);
    for (int i=0; i<n; i++){
      for (int j=0; j<n; j++){
          if (dp[i][j] == -1)
             findLongestFromACell(i, j, mat, dp, n);
          result = max(result, dp[i][j]);
       }
     }
     return result;
}

int main(){
  int n;
	int mat[max][max]
	 cin>>n;
	 for(int i=0;i<n;i++){
		 for(int j=0;j<n;j++){
			 cin>>mat[i][j];
		 }
	 }
   cout << "Length of the longest path is "<< finLongestOverAll(mat, n)<<endl;
   return 0;
}
