#include <cstdlib>
#include <ctime>
#include <iostream>
 
int main (int argc, char const* argv[])
{
      srand((unsigned)time(0)); 
      int maior = 100;
      int menor = 30;
      int aleatorio = rand()%(maior-menor+1) + menor;
      std::cout << "Numero Aleatorio = " << aleatorio << std::endl;
      return 0;
}
