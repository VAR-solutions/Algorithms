int strStr(string haystack, string needle) {
        int n=needle.size();
        int m = haystack.size();
        if(n==0 && m==0) return 0;

        int dp[n+1];
        memset(dp,0,sizeof(dp));

        int i=0,j=1;
        while(j<n){
            while(i>0 && needle[i]!=needle[j]) i=dp[i-1];
            if(needle[i]==needle[j]) dp[j] = i+1,i++;
            j++;
        }
        i = 0,j = 0;
        while(i<m){
            while(i<m && j<n && haystack[i]==needle[j]) i++,j++;
            if(j==n) return i-n;
            if(j!=0) j = dp[j-1];
            if(j==0 && haystack[i]!=needle[j]) i++;
        }
        return -1;
    }
};
