/*
@author: upizzz

*/
#include <bits/stdc++.h>
using namespace std;
long getWaysHelper(int, vector<long>,int);

//Recurrsive Solution
//TC = O(2^m) where m is the size of coins vector
//SC = O(m) is the Recurrsive depth 
long getWaysRecc(int n, vector<long> coins) {
    return getWaysHelper(n,coins,0);
} 
long getWaysHelper(int n, vector<long> coins,int i){
    if(n ==0)
        return 1;
    else if(n < 0)
        return 0;
    else{
        long change = 0; 
        for(int index = i;index<coins.size(); index++){
            change += getWaysHelper(n-coins[index],coins,index);
        }
        return change;
    }
}

/*
    Let memo[i][j] define the number of ways a value of 'j' can be obtained by using {C[0],C[1]...C[i]} only 
    Constructing the solution bottom up. Below reccursive relation can be formed

    memo[i][j] = {
                        1                                   if j = 0
                        0                                   if j < c[i]
                        memo[i][j-c[i]]                     if i ==0 and j >= c[i]
                        memo[i-1][j] + memo[i][j-c[i]]      if i > 0 and j >= c[i]
                 }
*/

//DP solution
// TC = O(m*n) where m = size of coins vector
// SC = O(m*n)
long getWays(long n, vector<long> c) {
    long memo[c.size()][n+1];
            for(int i=0;i < c.size(); i++){
                for(int j=0; j < n+1 ; j++){
                    if(j==0){//no. of ways of forming change for 0
                        memo[i][j] = 1;
                    } 
                    else{
                        long x,y;
                        //if include coin[j] 
                        x = j - c[i]>=0 ? memo[i][j-c[i]] : 0;
                        //if i exclude coin[j]
                        y = i > 0 ? memo[i-1][j]: 0 ;
                        memo[i][j] = x + y;
                    }
                } 
            }
           return memo[c.size()-1][n];
}



int main(){
    vector<long> c = {1,2,3};
    int n = 4;
    cout<<getWays(n,c);
//    cout<<getWaysRecc(n,c);
    return 0;
}
