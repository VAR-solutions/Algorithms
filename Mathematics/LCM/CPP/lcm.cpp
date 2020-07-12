#include <iostream>

int gcd(int a, int b){
  if(b == 0)
  return a;
  return gcd(b, a % b);
}

int lcm(int a, int b){
  return a * b / gcd(a, b);
}

int main()
{
  int a{};
  int b{};
  std::cin >> a >> b;
  std::cout << lcm(a, b);
}
