#include<bits/stdc++.h>

using namespace std;
//function to calculate power of 2
unsigned int nextPowerOf2(unsigned int n){
    if (!n) return 1;
    else if (!(n & (n - 1))) return n;
    else return (1<<(32-__builtin_clz(n)));
}
//main function
int main(){
    int t;
    cin>>t;
    while(t--){
        unsigned int n;
        cin>>n;
        cout<<"Next Power of 2 greater than "<<n<<" is : "<<nextPowerOf2(n)<<endl;
    }
    return 0;
}
