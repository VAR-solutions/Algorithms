#include <iostream> 
using namespace std; 
  
int main() {
   cout << "Enter a number: ";
   cin >> n;
   while(cin.fail()) {
       cout << "Invalid input. Please re-enter: " << endl;
       cin.clear();
       cin.ignore(256,'\n');
       cin >> n;
   }
   cout << __builtin_popcount (n) << "\n";
   return 0; 
} 
