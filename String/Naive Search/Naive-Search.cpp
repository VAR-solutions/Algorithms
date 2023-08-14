int strStr(string haystack, string needle) {
        
        if(needle.length() == 0) {
            return 0;
        }
        
        if(haystack.length() == 0) {
            return -1;
        }
        
        int i = 0, j = 0;
        
        while(i<haystack.length()) {
            if(haystack[i] == needle[j]) {
                i++;
                j++;
            } else {
                i -= j;
                j = 0;
                i++;
            }
            if(j == needle.length()) {
                return i-j;
            }
        }
        
        return -1;
    }
