#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 1e4+10;
struct edge {
    int to, cap, rev;
    edge(){}
    edge(int to, int cap, int rev):to(to), cap(cap), rev(rev){}
};
vector<edge> G[maxn];
int lev[maxn];
int n, m;

void init() {
    for(int i = 0; i <= n; i++)G[i].clear();
}

void add_edge(int u, int v, int w) {
    G[u].push_back(edge(v, w, (int)G[v].size()));
    G[v].push_back(edge(u, 0, (int)G[u].size()-1));
}

bool bfs(int s, int t) {
    memset(lev, -1, sizeof(lev));
    lev[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(auto &e : G[u]){
            if(e.cap > 0 && lev[e.to] < 0){
                lev[e.to] = lev[u]+1;
                if(e.to == t)return 1;
                q.push(e.to);
            }
        }
    }
    return 0;
}

int dfs(int v, int t, int f) {
    if(v == t)return f;
    int ret = 0;
    for(auto &e : G[v]){
        if(e.cap > 0 && lev[e.to] == lev[v]+1){
            int d = dfs(e.to, t, min(e.cap, f-ret));
            if(d > 0){
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                ret += d;
                if(ret == f)break;
            }
            
        }
    }
    if(!ret)lev[v] = 0;
    return ret;
}

int max_flow(int s, int t) {
    int flow = 0;
    while(bfs(s, t))flow += dfs(s, t, INF);
    return flow;
}
int main() {
    init();
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) {
        int u, v, cap;
        scanf("%d%d%d", &u, &v, &cap);
        add_edge(u, v, cap);
    }
    int src, dst;
    scanf("%d%d", &src, &dst);
    int flow = max_flow(src, dst);
    printf("%d\n", flow);
    return 0;
}
