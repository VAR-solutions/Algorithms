#include <iostream> 
using namespace std; 
  
// Function to reverse a string 
void reverseStr(string& str) { 
    // Line length
    int n = str.length(); 
    // Swap character
    for (int i = 0; i < n / 2; i++) 
        swap(str[i], str[n - i - 1]); 
} 
  
int main() { 
    string str = "MyStingToReverse"; 
    reverseStr(str); 
    cout << str; 
    return 0; 
} 
