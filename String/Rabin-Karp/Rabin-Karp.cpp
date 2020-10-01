int rabinKarp(string haystack, string needle) {
        
        const int p = 31;
        vector<long long> pows (haystack.length());
        pows[0] = 1;
            
        for(int i=1; i<pows.size(); i++) {
            pows[i] = pows[i-1] * p;
        }

        vector<long long> haystackHash(haystack.length());
        
        for (int i=0; i<haystack.length(); ++i)
        {
            haystackHash[i] = (haystack[i] - 'a' + 1) * pows[i];
            if (i>0) {
                haystackHash[i] += haystackHash[i-1];
            }
        }
        
        long long needleHash = 0;
        for (int i=0; i<needle.length(); i++) {
            needleHash += (needle[i] - 'a' + 1) * pows[i];
        }
        
        for (int i = 0; i + needle.length() - 1 < haystack.length(); i++)
        {
            long long currentHash = haystackHash[i+needle.length()-1];
            if (i>0){
                currentHash -= haystackHash[i-1];
            }
            
            if (currentHash == needleHash * pows[i])
                return i;
        }
        
        return -1;
    }
