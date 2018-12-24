#include <bits/stdc++.h>
 
int main (int argc, char const* argv[])
{
      srand((unsigned)time(0)); 
      int u = 100;
      int d = 30;
      int r = rand()%(u-d+1) + d;
      std::cout << "Random Number = " << r << std::endl;
      return 0;
}
