#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
 
int main()
{
    std::string in = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum";
    std::string needle = "aliquip";
    auto it = std::search(in.begin(), in.end(),
                   std::boyer_moore_searcher(
                       needle.begin(), needle.end()));
    if(it != in.end())
        std::cout << "The string " << needle << " found at offset "
                  << it - in.begin() << '\n';
    else
        std::cout << "The string " << needle << " not found\n";
}
