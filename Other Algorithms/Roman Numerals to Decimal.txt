#include <bits/stdc++.h> 
using namespace std; 
  
// This function returns value 
// of a Roman symbol 
int value(char r) 
{ 
    if (r == 'I') 
        return 1; 
    if (r == 'V') 
        return 5; 
    if (r == 'X') 
        return 10; 
    if (r == 'L') 
        return 50; 
    if (r == 'C') 
        return 100; 
    if (r == 'D') 
        return 500; 
    if (r == 'M') 
        return 1000; 
  
    return -1; 
} 
  
// Returns decimal value of 
// roman numaral 
int romanToDecimal(string& str) 
{ 
    // Initialize result 
    int res = 0; 
  
    // Traverse given input 
    for (int i = 0; i < str.length(); i++) { 
        // Getting value of symbol s[i] 
        int s1 = value(str[i]); 
  
        if (i + 1 < str.length()) { 
            // Getting value of symbol s[i+1] 
            int s2 = value(str[i + 1]); 
  
            // Comparing both values 
            if (s1 >= s2) { 
                // Value of current symbol 
                // is greater or equal to 
                // the next symbol 
                res = res + s1; 
            } 
            else { 
                // Value of current symbol is 
                // less than the next symbol 
                res = res + s2 - s1; 
                i++; 
            } 
        } 
        else { 
            res = res + s1; 
        } 
    } 
    return res; 
} 
  
// Driver Program 
int main() 
{ 
    // Considering inputs given are valid 
    string str = "MCMIV"; 
    cout << "Integer form of Roman Numeral is "
         << romanToDecimal(str) << endl; 
  
    return 0; 
}