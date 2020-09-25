vector<int> longestSuffixPrefix(string s) {
        
    vector<int> lsp(s.length());
    
    lsp[0] = 0;
    
    int i = 1, j = 0;
    
    while(i<s.length()) {
        
        if(s[i] == s[j]) {
            j++;
            lsp[i] = j;
            i++;
        } else {
            
            if(j != 0)
                j = lsp[j-1];
            else
                i++;
        }
    }
    
    return lsp;
}

int kmp(string s1, string s2) {
        
    vector<int> lsp = longestSuffixPrefix(s2);
    
    int i = 0, j = 0;
    
    while(i<s1.length()) {
        
        if(s1[i] == s2[j]) {
            i++;
            j++;
        } else {
            
            if(j != 0)
                j = lsp[j-1];
            else
                i++;
        }
        if(j == s2.length())
            return i-j;
    }
    
    return -1;
}
