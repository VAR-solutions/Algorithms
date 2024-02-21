#include <iostream>
#include <map>
#define ull unsigned long long
using namespace std;

int fibo(map<ull,ull>&memo, int x){

    if(x <= 2){
      return 1;
    }
    if(memo.count(x)){
      return memo[x];
    }

    ull result = fibo(memo, x-1)% 1000000007 + fibo(memo, x-2)% 1000000007;
    memo[x] = result;
    return memo[x];
}

int main(){
    int x;
    while(cin>>x){
        map<ull,ull>memo;
        cout<<fibo(memo,x)<<endl;
    }
}
