// program to calculate factorial using C++
// can calculated Factorial upto 500 digits 

#include <iostream>
using namespace std;
#define ll long long
#define max_range 500
int mul(int x, int r[], int r_size) {
  int carry = 0;
  
  // multiply n one by one with indiviual digits of r[]
  for (int i=0; i<r_size; i++) 
    { 
        int prod = r[i] * x + carry; 
  
        // Store last digit of 'prod' in r[]   
        r[i] = prod % 10;   
  
        // Put rest in carry 
        carry  = prod/10;     
    } 
    
    // Put carry in res and increase result size 
    while (carry) 
    { 
        r[r_size] = carry%10; 
        carry = carry/10; 
        r_size++; 
    } 
    return r_size; 
} 

// FACTORIAL FUNCTION 
void factorial(int value) {
    int r[max_range];
    
    r[0] = 1; 
    int r_size = 1; 
    
    for (int x=2; x<=value; x++) 
        r_size = multiply(x, r, r_size);
    
    // factorial calculated 
    cout << "Factorial of given number is \n"; 
    for (int i=r_size-1; i>=0; i--) 
        cout << r[i];   
}

int main() {
  int value;
  cout<<"Enter Value To Calculate Factorial For > ";
  cin>>value;
  factorial(value);
  return 0;
}

// EDITS ARE WELCOME .    
