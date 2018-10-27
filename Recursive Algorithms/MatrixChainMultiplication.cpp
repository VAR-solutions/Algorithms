/* A  Recursive implementation of Matrix Chain Multiplication*/
#include<bits/stdc++.h> 
using namespace std;
  
// Matrix Ai has dimension a[i-1] x a[i] for i = 1..n 
int mcm(vector<int> a, int i, int j) 
{ 
    if(i == j)  return 0; 
    int mini = INT_MAX; 
    for (int k = i; k <j; k++) 
    { 
      int temp = mcm(a, i, k) + mcm(a, k+1, j) + a[i-1]*a[k]*a[j]; 
      mini = min(mini,temp); 
    } 
    // Return minimum count 
    return mini; 
} 
   
int main() 
{ 
    vector<int> v{40, 20, 30, 10, 30}; 
    int n = v.size(); 
  
    cout << "Minimum number of multiplications is " << mcm(v, 1, n-1) << endl; 
    return 0; 
} 
