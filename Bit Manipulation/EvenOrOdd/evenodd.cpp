#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

/* 
	Function checks whether the number is even or not.
	Returns "yes" is N is even, else returns "no".
*/
string isEven(int N) {
	/*
		Bitwise & with any number N returns 1 if the least significant bit is set. Otherwise, it returns 0.
		If the most significant bit is set, then the number is odd
	*/
	if(N & 1) 
		return "no";
	else
		return "yes";
}
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    cout<<isEven(N)<<endl;
}
