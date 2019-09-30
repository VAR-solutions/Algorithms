// this is an algorithm for colouring nodes in regular square grid
#include <iostream>

int colour(int position[], int dimension){
    int result = 0;
    for(int i = 1; i <= dimension; i++)
        result += i * position[i];
    return result % (2 * dimension + 1);
}

int main(){
    
    int x[] = {1,1};
    int y[] = {1,2};
    int z[] = {2,1};
    
    
    std::cout << colour(x,2) << std::endl;
    std::cout << colour(y,2) << std::endl;
    std::cout << colour(z,2) << std::endl;
}
