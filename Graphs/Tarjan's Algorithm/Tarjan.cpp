vector<int> g[100100];
vector<vector<int>> res;
int time = 0;

void dfs(int u, int prev, vector<int> &low, vector<int> &disc) {
    disc[u] = low[u] = ++time;
    
    for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        
        if (v == prev) {
            continue;
        }
        
        if (disc[v] == -1) {
            dfs(v, u, low, disc);
        }
        
        low[u] = min(low[u], low[v]);
        
        if (low[v] > disc[u]) {
            res.push_back({u, v});
        }
    }
}
