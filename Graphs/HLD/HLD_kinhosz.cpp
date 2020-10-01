typedef long long ll;
typedef pair<int,int> ii;

class HLD{

	vector<int> pos;
	vector<int> parent;
	vector<int> sz;
	vector<int> level;
	vector<int> head;
	vector<vector<ii>> g;

	// segment tree
	vector<int> tree;
	vector<int> lazy;

	int N;

	void propagate(int pos,int i,int j){

	}

	int query(int pos,int i,int j,int l,int r){

	}

	void update(int pos,int i,int j,int l,int r,int w){

	}
	
	void dfs(int u,int lv){

		level[u] = lv;
		sz[u] = 1;
		int bigChild = 0;

		for(int i=0;i<g[u].size();i++){
			ii topo = g[u][i];
			int v = topo.first;
			if(v == parent[u]) continue;
			parent[v] = u;
			dfs(v,lv+1);
			sz[u] += sz[v];
			if(sz[v] > bigChild) swap(g[u][i],g[u][0]);
			bigChild = max(bigChild,sz[v]);
		}
	}

	void decompose(int u,int &x,bool keep){

		if(keep){
			head[u] = head[parent[u]];
		}
		else head[u] = u;
		
		pos[u] = x++;

		if(sz[u] > 1) decompose(g[u][0].first,x,true);

		for(int i=1;i<g[u].size();i++){
			ii topo = g[u][i];
			int v = topo.first;
			if(v == parent[u]) continue;
			decompose(v,x,0);
		} 
	}

public:

	HLD(int n){
		N = n;
		pos.resize(n,-1);
		parent.resize(n,-1);
		sz.resize(n,-1);
		level.resize(n,-1);
		head.resize(n,-1);
		g.resize(n);
		// segment tree
		tree.resize(4*n+3,-1);
		lazy.resize(4*n+3,-1);
	}	
	
	void addEdge(int u,int v,int w){
		g[u].push_back({v,w}); // vertex, weight
	}
	
	void init(){
		parent[0] = -1;
		dfs(0,0);
		int x=0;
		decompose(0,x,0);
	}
	
	int LCA(int u,int v){
		while(head[u] != head[v]){
			if(level[head[u]] > level[head[v]]) u = parent[head[u]];
			else v = parent[head[v]];
		}
		return (level[u] < level[v]?u:v);
	}
	
	int get(int u,int v){
		int l = LCA(u,v);
		int ret = 0;
		int add;
		while(head[u] != head[l]){
			add = query(1,0,N-1,pos[head[u]],pos[u]);
			u = parent[head[u]];
		}
		add = query(1,0,N-1,pos[l]+1,pos[u]);
		while(head[v] != head[l]){
			add = query(1,0,N-1,pos[head[v]],pos[v]);
			v = parent[head[v]];
		}
		add = query(1,0,N-1,pos[l],pos[v]);
		return ret;
	}
	
	void flip(int u,int v,int w){
		int l = LCA(u,v);
		while(head[u] != head[l]){
			update(1,0,N-1,pos[head[u]],pos[u],w);
			u = parent[head[u]];
		}
		update(1,0,N-1,pos[l]+1,pos[u],w);
		while(head[v] != head[l]){
			update(1,0,N-1,pos[head[v]],pos[v],w);
			v = parent[head[v]];
		}
		update(1,0,N-1,pos[l],pos[v],w);
	}

	int lenPath(int u,int v){
		int l = LCA(u,v);
		int ret = level[u] - level[l];
		ret += level[v] - level[l];
		ret++;
		return ret;
	}
};
