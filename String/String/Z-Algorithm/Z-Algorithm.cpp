vector<int> zAlgorithm(string s) {
        
    int n = (int)s.length();
    
    vector<int> z(n, 0);
    
    int l = 0, r = 0, k;
    
    for(int i = 1; i<s.length(); i++) {
        
        if(i>r) {
            
            l = r = i;

            while(r<n && s[r-l] == s[r]) {
                r++;
            }
            
            z[i] = r-l;
            r--;
            
        } else {
            
            k = i-l;
            
            if(z[k] < r-i+1) {
                
                z[i] = z[k];
                
            } else {
                
                l = i;
                
                while(r<n && s[r-l] == s[r]) {
                    r++;
                }
            
                z[i] = r-l;
                r--;
            }
        }
    }

    return z;
}
