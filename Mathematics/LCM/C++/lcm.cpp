#include <iostream>
using namespace std;
int main()
{
   int x, y, LCM;
   cout << "Enter two numbers: ";
   cin >> x >> y;
   LCM = (x > y) ? x:y;
   while(1)
   {
      if((LCM % x == 0) && (LCM % y == 0))
      {
         cout << "\nLCM: " << LCM;
         break;
      }
      ++LCM;
   }
   return 0;
}
