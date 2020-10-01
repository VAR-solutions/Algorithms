int uniquePaths(int m, int n) {
        
    /*
        1 1 1
        1 2 3
    */
    
    int dp[m][n];
    
    dp[0][0] = 1;
    
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i && j) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            } else if (i) {
                dp[i][j] = dp[i-1][j];
            } else if (j) {
                dp[i][j] = dp[i][j-1];
            }
        }
    }
    
    return dp[m-1][n-1];
}
