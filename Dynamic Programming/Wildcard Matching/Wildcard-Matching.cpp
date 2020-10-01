bool isMatch(string s, string p) {
    
    int n = (int)s.length();
    int m = (int)p.length();
    
    int dp[n+1][m+1];
    
    for(int i = 0; i<=n; i++) {
        dp[i][0] = false;
    }
    
    dp[0][0] = true;
    
    bool letter = false;
    
    for(int j = 1; j<=m; j++) {
        if(p[j-1] == '*' && !letter) {
            dp[0][j] = true;
        } else {
            dp[0][j] = false;
            letter = true;
        }
    }
    
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=m; j++) {
            if(s[i-1] == p[j-1] || p[j-1] == '?') {
                dp[i][j] = dp[i-1][j-1];
            } else if(p[j-1] == '*') {
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            } else {
                dp[i][j] = false;
            }
        }
    }
    
    return dp[n][m];
}
