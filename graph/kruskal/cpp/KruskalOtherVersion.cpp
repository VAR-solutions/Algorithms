#include <bits/stdc++.h>
#define SIZE 124770
using namespace std;
 
typedef long long ll;
 
ll parents[SIZE];
pair <ll, pair<ll, ll>> ladj[SIZE]; // adjacency matrix
 
int search(ll x){
    if (parents[x] == x){
        return x;
    }
 
    return parents[x] = search(parents[x]);
}
 
void join(ll x, ll y){
    x = search(x);
    y = search(y);
 
    if (x == y){
        return;
    }
    parents[x] = y;
    return;
}
 
ll kruskal(ll m, pair<ll, pair<ll, ll>> ladj[]){
    ll x, y;
    ll cost;
    ll min_cost = 0;
 
    for (ll i = 1; i <= m; i++){
        x = ladj[i].second.first;
        y = ladj[i].second.second;
        cost = ladj[i].first;
        if (search(x) != search(y)){
            printf("%lld -> %lld : COST = %lld\n", x, y, cost);
            min_cost += cost;
            join(x, y);
        }
    }
    return min_cost;
}
 
int main(){
    ll n, m, u, v, c;
    // n = number of vertices   m = number of edges  u, v = vertices  c = edge weight
    scanf("%lld %lld", &n, &m);
 
    for (ll i = 0; i <= n; i++){
        parents[i] = i;
    }
 
    for (ll i = 1; i <= m; i++){
        scanf("%lld %lld %lld", &u, &v, &c);
        ladj[i] = make_pair(c, make_pair(u, v));
    }
 
    sort(ladj + 1, ladj + m + 1);
    printf("The result is: %lld\n", kruskal(m, ladj));
    return 0;
}