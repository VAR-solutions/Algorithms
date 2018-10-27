// A Recursive C++ program to find the  minimum number of operations to convert str1 to str2 
#include<bits/stdc++.h> 
using namespace std; 
  
int editDist(string str1 , string str2 , int m ,int n) 
{ 
    // If first string is empty, the only option is to insert all characters of second string into first 
    if (m == 0) return n; 
  
    // If second string is empty, the only option is to remove all characters of first string 
    if (n == 0) return m;  
    
    if (str1[m-1] == str2[n-1]) 
        return editDist(str1, str2, m-1, n-1); 
    return 1 + min (editDist(str1,  str2, m, n-1),
     min(editDist(str1,  str2, m-1, n), editDist(str1,  str2, m-1, n-1))); // Insert, Remove, Replace 
} 

int main() 
{  
    string str1 = "vintage"; 
    string str2 = "vintsgesk"; 
  
    cout << editDist( str1 , str2 , str1.length(), str2.length()); 
  
    return 0; 
} 
