#include <iostream> 
using namespace std; 
  
int main() {
    cout << "Enter an integer: ";
    cin >> input;
    while(cin.fail()) {
        cout << "Invalid input. Please re-enter: " << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> input;
    } 
   cout << __builtin_popcount (input) << "\n"; 
   return 0; 
} 
