
// C++ program to find GCD of two numbers
#include <iostream>

// Recursive function to return gcd of a and b
int gcd(int a, int b){
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
 
int main(){
    int a, b;
	cin>>a>>b;
    cout<<"GCD of "<<a<<"and "<<b<<"is : "<<gcd(a, b)<<endl;
    return 0;
}
