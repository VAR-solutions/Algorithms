/* A  Recursive implementation to find sum of digits of a number*/
#include<bits/stdc++.h> 
using namespace std;

int sumOfDigits(int n){
    if(n == 0) return 0;

    return n%10+sumOfDigits(n/10);
}
   
int main() 
{ 
    int n=1729;
    cout << "Sum of Digits of " << n << " is " << sumOfDigits(n) << endl; 
    return 0; 
} 
