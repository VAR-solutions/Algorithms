/* Given an integer N, find and return the count of unique Binary search trees (BSTs)
   possible with nodes valued from 1 to N.
   Output count can be very large, so return the count modulo 10^9+7.
   Contraints : 1<= N <=1000
   Time Complexity: O(n^2)
*/


/* Recurssion solution: 
   BSTcount(for value n) = summationOf ( BSTcount( for node [k-1]) 
   			  	  				 	   			   + BSTcount( for node [n-k]) );
          (k)
          / \
        /    \
      /       \
(1 to k-1)  (k+1 to n)

*/

/* Input: 3
   Output: 5
   
   Input: 8
   Output: 1430
*/			  	  				 	   			   
   			  	  				 	   			   
#include <bits/stdc++.h>
#define mm 1000000007
using namespace std;

int countBST(int n, int *dp) {
    //base condition
    if(n==0 || n==1)
        return 1;
    if(n==2)
        return 2;
    //if dp[n] has some value, then answer is already calculated for that n.
    if(dp[n]!=0) {
        return dp[n];
    }
    //calculating sum for every value of n.
    long long sum=0;
    for(int k=1; k<=n; k++) {
        sum = (sum%mm + (countBST(k-1, dp)%mm * countBST(n-k, dp))%mm)%mm;
    }
    //save the answer for n in the dp array.
    dp[n] = sum;
    return sum;
}


int main() {
	int n ;
	cin>>n;
	//dp array to fill in the values which are calculated.
	int *dp = new int[n+1] {0}; 
    //for n=0 and n=1, the number of BSTs possible is 1.
	dp[0] = 1; 
    dp[1] = 1;
	cout<<countBST(n, dp);
	return 0;
}

