#include <iostream>
#include <cmath>

double euclidean_distance(double x_pos[], double y_pos[], int space_dimension){
    double result = 0;
    for(int i = 0; i < space_dimension; i++){
        result += pow(x_pos[i] - y_pos[i],2);
    }
    return sqrt(result);
}


int main(int argc, const char * argv[]) {
    double x[] = {0,0,0};
    double y[] = {1,1,1};
    std::cout << euclidean_distance(x, y, 3);
    
    return 0;
}
