#include <bits/stdc++.h>

int fill(){
 return rand() % 10000;
}
 
int main (int argc, char const* argv[])
{
 srand(1);
 std::vector<int> a(10000);
 std::generate(a.begin(), a.end(), fill); 
 for(int& i:a){
    std::cout << i << " ";
 }
}
