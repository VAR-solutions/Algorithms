
// C++ program to find GCD of two numbers
#include <iostream>

// Recursive function to return gcd of a and b
int gcd(int a, int b){
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// iterative approach
int gcd2(int a, int b) {
    while (b != 0) {
        let c = a % b;
        a = b;
        b = c;
    }
    return a;
}
	
int main(){
    int a, b;
	cin>>a>>b;
    cout<<"GCD of "<<a<<"and "<<b<<"is : "<<gcd(a, b)<<endl;
    return 0;
}
