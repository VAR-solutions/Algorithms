#include <iostream>
using namespace std;

int lps(string s , int si , int ei){
    if(si > ei) return 0;
    if(si == ei) return 1;
    if(s[si] == s[ei]){
        return 2+lps(s,si+1, ei-1);
    }else{
        return max(lps(s,si,ei-1) , lps(s,si+1,ei));
    }
}
int main() 
{ 
    string s = "bbabcbcabbb"; 
    cout << "The length of the LPS is " << lps(s,0,s.length()-1);  
    return 0; 
}
