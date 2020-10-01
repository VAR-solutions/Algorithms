#include <bits/stdc++.h>
using namespace std;

void TowerOfHanoi(int n,int a,int b,int c){
    if(n){
        TowerOfHanoi(n-1,a,c,b);
        cout << a << "->" << b << "\n";
        TowerOfHanoi(n-1,c,b,a);
    }
}

int main(){
    int number_of_discs;
    cout << "Enter the value of n: ";
    cin >> number_of_discs;
    TowerOfHanoi(number_of_discs,1,2,3);
    //each rod is numbered as 1,2,3
    return 0;
}
