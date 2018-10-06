// Count number of bits to be flipped 
// to convert A into B 
#include <iostream> 
using namespace std; 
  
int countSetBits(int n) 
{ 
    int count = 0; 
    while (n) 
    { 
        count += n & 1; 
        n >>= 1; 
    } 
    return count; 
} 
   
int FlippedCount(int a, int b) 
{ 
    return countSetBits(a^b); 
} 
//driver code
int main() 
{ 
    int a = 10; 
    int b = 20; 
    cout << FlippedCount(a, b)<<endl; 
    return 0; 
} 
