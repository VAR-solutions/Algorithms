bool isMatch(string s, string p) {
    
     /*       . *
            0 1 2
          0 T F T
        a 1 F T T
        b 2 F T T
     */
    
    int n = (int)s.length();
    int m = (int)p.length();
    
    int dp[n+1][m+1];
    
    for(int i = 0; i<=n; i++) {
        for(int j = 0; j<=m; j++) {
            dp[i][j] = false;
        }
    }
    
    dp[0][0] = true;
    
    for(int j = 1; j<=m; j++) {
        if(p[j-1] == '*') {
            dp[0][j] = dp[0][j-2];
        }
    }
    
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=m; j++) {
            if(s[i-1] == p[j-1] || p[j-1] == '.') {
                dp[i][j] = dp[i-1][j-1];
            } else if(p[j-1] == '*') {
                dp[i][j] = dp[i][j-2];
                if(s[i-1] == p[j-2] || p[j-2] == '.') {
                    dp[i][j] |= dp[i-1][j];
                }
            } else {
                dp[i][j] = false;
            }
        }
    }
    
    return dp[n][m];
}
