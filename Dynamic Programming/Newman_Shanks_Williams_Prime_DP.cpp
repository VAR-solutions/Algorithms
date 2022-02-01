/*
The following is the code to implement an find the nth NWS prime_nummber.
S(2*m+1)	=	[(1+sqrt(2))^(2*m+1)+(1-sqrt(2))^(2*m+1)]//2;
S(n) = 2*S(n-1)+S(n-2);
*/


#include<bits/stdc++.h>

using namespace std;


int nswp(int n) {		//calling out the NSWP function

int dp[n+1];		//declaring the array used for solving the problem using DP


dp[0] = dp[1] = 1;		//initialsing the first two elements as 1

for(int i=2;i<=n;i++) {
	dp[i]=2*dp[i-1]+dp[i-2];		// the next element of the DP array is the twice of the previous element added to the prev. to the prev. element
}

return dp[n];		//returning the nth dp(element) as the NSWP no.

}


int main() {

int n;		

cin>>n;		//input the nth no. to be found!

cout<<nswp(n)<<endl;	// callling the NSWP function!

	return 0;
}