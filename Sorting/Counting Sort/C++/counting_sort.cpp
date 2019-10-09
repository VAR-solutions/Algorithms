#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    cout<<"Enter size of array:\n";
    cin>>n;
    vector<ll> a(n,0);
    cout<<"enter the array:\n";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    //frequency array:
    ll m = *max_element(a.begin(),a.end());
    vector<ll> fre(m+1,0);
    for(int i=0;i<n;i++){
        fre[a[i]]++;
    }
    cout<<"The sorted array is:\n";
    for(int i=0;i<m+1;i++){
        for(int j=0;j<fre[i];j++){
            cout<<i<<" ";
        }
    }
    cout<<"\n";
}