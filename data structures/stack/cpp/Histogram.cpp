#include <iostream>
using namespace std;
#include<stack>
#define ll long long  

ll max_Area(ll a[], ll n){

    stack<ll> s;
    ll max_value = 0;

    for(int i=0; i<n; i++){

        if(s.empty()){
            s.push(i);
        }
        else {

            while(!s.empty() && a[i] < a[s.top()]){
                ll area = 0;
                ll p = s.top();
                s.pop();
                if(s.empty())
                    area = a[p] * i;
                else 
                    area = a[p] * (i- s.top() -1);
                max_value = max(area, max_value);
            }
            s.push(i);
        }
    }

    while(!s.empty()){
        ll area = 0;
        ll p = s.top();
        s.pop();
        if(s.empty())
            area = a[p] * n;
        else
            area = a[p] * (n-p);

        max_value = max(area,max_value);
    }
    return max_value;
}
int main() {

    ll n;
    cin>>n;
    
    ll h[n];
    for(ll i=0;i<n;i++){
        cin>>h[i];
    }
    cout<<max_Area(h, n)<<endl;

return 0;
}
