#include <iostream>
using namespace std;

int lps(string s){
    int n=s.length();
	int lps[n][n];
	// length 1
    for(int i=0 ; i<n ; i++){
        lps[i][i] = 1;
   }
	for(int l=2 ; l<=n ; l++){
        for(int i=0 ; i<n-l+1 ; i++){
            int j = i+l-1;
            // when l=2 it should be handled correctly 
	          if(s[i] == s[j]){
	            lps[i][j] = (l == 2) ? 2 : (2 + lps[i+1][j-1]);
            }else{
               lps[i][j] = max(lps[i+1][j] , lps[i][j-1]);
	        }
	   }
   }
	 return lps[0][n-1];
}

int main() 
{ 
    string s = "bbabcbcab"; 
    cout << "The length of the LPS is " << lps(s);  
    return 0; 
}
