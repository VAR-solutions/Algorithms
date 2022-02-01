// Optimizing DSU To Find Cycle In Undirected Graph
#include <bits/stdc++.h>
using namespace std;

void init() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}


// Cycle detection using disjoint set union
class Graph {
	int V;
	list<pair<int, int>> l;
public:
	Graph(int V) {
		this->V = V;
	}
	void addEdge(int x, int y) {
		l.push_back(make_pair(x, y));
	}
	// find
	int find_set(int x, int *parent) {
		if (parent[x] == -1) {
			return x;
		}
		// Path Compression Optimisation
		return parent[x] = find_set(parent[x], parent);
	}
	// Union
	void union_set(int x, int y, int *parent, int *rank) {
		int s1 = find_set(x, parent);
		int s2 = find_set(y, parent);

		if (s1 != s2) {
			if (rank[s1] < rank[s2]) {
				parent[s1] = s2;
				rank[s2] += rank[s1];
			} else {
				parent[s2] = s1;
				rank[s1] += rank[s2];
			}
		}
	}

	// cycle detection
	bool cycleDetection() {
		int *parent = new int[V];
		int *rank = new int[V];

		// DSU logic to check if graph contains a cycle or not
		for (int i = 0; i < V; i++) {
			parent[i] = -1;
			rank[i] = 1;
		}

		for (auto edge : l) {
			int u = edge.first;
			int v = edge.second;

			int s1 = find_set(u, parent);
			int s2 = find_set(v, parent);
			if (s1 != s2) {
				union_set(s1, s2, parent, rank);
			} else {
				cout << "Same Parent " << s1 << " and " << s2 << endl;
				return true;
			}
		}
		// Uncomment this to print the parent and rank array
		// cout << endl;
		// for (int i = 0; i < V; i++) {
		// 	cout << parent[i] << ",";
		// }
		// cout << endl;
		// for (int i = 0; i < V; i++) {
		// 	cout << rank[i] << ",";
		// }
		return false;
	}
};
int main() {
	init();
	int V, E;
	cin >> V >> E;
	Graph g(V);
	for (int i = 0; i < E; i++) {
		int x, y;
		cin >> x >> y;
		g.addEdge(x, y);
	}
	if (g.cycleDetection()) {
		cout << "contains a cycle" << endl;
	} else {
		cout << "does not contains a cycle" << endl;
	}
	return 0;
}
