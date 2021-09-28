#include <cstdio>
#include <algorithm>
using namespace std;
constexpr int maxn = 5e2+10;
constexpr int INF = 0x3f3f3f3f;
int dis[maxn][maxn];
int n, m;

void floyd() {
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) {
                dis[i][j] = 0;
            }
            else {
                dis[i][j] = INF;
            }
        }
    }
    for(int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        dis[u][v] = dis[v][u] = min(dis[u][v], w);
    }
    floyd();
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            printf("%d%c", dis[i][j], " \n"[j==n]);
        }
    }
    return 0;
}
