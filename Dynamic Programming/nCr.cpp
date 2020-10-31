int nCrModp(int n, int r) 
{ 
    int dp[n+1][r+1]={0};
    if(r>n){
        return 0;
    }
    else if(r==n){
        return 1;
    }
    else{
    for(int i=0;i<=n;i++){
        dp[i][0] = 1;
    }
    for(int j=1;j<=r;j++){
        dp[0][j] = 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=r;j++){
            if(i==j){
                dp[i][j] = 1;
            }
            else{
                dp[i][j] = ((dp[i-1][j]%p) + (dp[i-1][j-1]%p))%p;
            }
        }
    }
    return (dp[n][r]%p);
    }
} 
