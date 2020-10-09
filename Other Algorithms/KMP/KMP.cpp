vector<int> longestSuffixPrefix(string needle) {
        
        vector<int> lsp(needle.length(), 0);
        
        int i = 1, j = 0;
        
        while(i<needle.length()) {
            
            if(needle[i] == needle[j]) {
                j++;
                lsp[i] = j;
                i++;
            } else {
                
                if(j != 0) {
                    j = lsp[j-1];
                } else {
                    i++;
                }
            }
        }
        
        return lsp;
    }
    
    int kmp(string haystack, string needle) {
        
        vector<int> lsp = longestSuffixPrefix(needle);
        
        int i = 0, j = 0;
        
        while(i<haystack.length()) {
            
            if(haystack[i] == needle[j]) {
                i++;
                j++;
            } else {
                
                if(j != 0) {
                    j = lsp[j-1];
                } else {
                    i++;
                }
            }
            if(j == needle.length()) {
                return i - j;
            }
        }
        
        return -1;
    }
