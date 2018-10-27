class UnionFind{
  vector<int> p, rank;
public:
  UnionFind(int n): rank(n,0){
    p.resize(n);
    for(int i = 0; i < n; i++) p[i] = i;
  }

  int findSet(int i){
    if(p[i] == i) return p[i];
    else return p[i] = findSet(p[i]);
  }

  bool isSameSet(int i, int j){
    return findSet(i) == findSet(j);
  }

  void mergeSet(int i, int j){
    int x = findSet(i), y = findSet(j);
    if(x == y) return;
    if(rank[x] > rank[y]){
      p[y] = x;
    }
    else{
      p[x] = y;
      if(rank[x] == rank[y]) ++rank[y];
    }
  }
};
