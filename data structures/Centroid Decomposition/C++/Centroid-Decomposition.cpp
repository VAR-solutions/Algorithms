#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;


struct CentroidDecomposition
{
    vector <set <int>> g;
    vector <int> parent, sz;

    CentroidDecomposition(vector <set <int>> &_g): g(_g)
    {
        int n = g.size();
        parent.resize(n);
        sz.resize(n);
        Build(0, -1);
    }

    void Build(int x, int p)
    {
        int n = findSz(x, p);
        int centroid = findCentroid(x, p, n);
        if (p == -1) p = centroid;
        parent[centroid] = p;
        set <int>::iterator it = g[centroid].begin();

        for (; !g[centroid].empty();)
        {
            int y = *it;
            g[centroid].erase(it);
            g[y].erase(centroid);
            Build(y, centroid);
            it = g[centroid].begin();
        }
    }

    int findSz(int x, int p)
    {
        // find subtree sizes
        sz[x] = 1;

        for (auto y: g[x])
            if (y != p) sz[x] += findSz(y, x);

        return sz[x];
    }

    int findCentroid(int x, int p, int n)
    {
        for (auto y: g[x])
            if (y != p && sz[y] > n/2) return findCentroid(y, x, n);

        return x;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);


    int n; // number of nodes
    cin >> n;
    vector <set <int>> g(n); // graph

    for (int i = 0; i < n-1; ++i)
    {
        int a, b; // edge between nodes 'a' and 'b'
        cin >> a >> b;
        g[a].insert(b);
        g[b].insert(a);
    }

    CentroidDecomposition cd(g); // finished


    return 0;
}