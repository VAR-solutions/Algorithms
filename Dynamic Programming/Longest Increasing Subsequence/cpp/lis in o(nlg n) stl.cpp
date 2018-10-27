#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define o 100005
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define mem(a,b) memset(a,(b),sizeof(a))
#define lpo(a) for(int i=0;i<a;i++)
#define loop(a,x) for(int i=a;i<x;i++)
#define srt(x) sort(x.begin(),x.end())
#define all(x) x.begin(),x.end()
const ll MAX=1000000000000000001;
typedef pair<int,int> pii;
vector<int> d;
int ans, n;
 
int main() {
    cin>>n;
    for (int i = 0; i < n; i++) 
    {
        int x;
        cin>>x;
        vector<int>::iterator it = lower_bound(d.begin(), d.end(), x);//upper_bound for Non decreasing sequence
        if (it == d.end()) 
            d.push_back(x);
        else 
            *it = x;
    }
    cout<<d.size();
    return 0;
}