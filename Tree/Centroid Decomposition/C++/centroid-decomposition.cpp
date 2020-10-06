// Centroid of a tree of size N is a vertex V, such that if we
// remove V from the tree, all resulting trees will have
// at most N/2 vertices.

// Usually used for solving problems that ask something
// about paths for all pairs of vertices.

// We find the centroid of the current tree, process 
// all paths that go through the centroid. Remove
// centroid from tree and call the function recursively
// for all resulting trees.

//Sample problem: https://codeforces.com/contest/161/problem/D

#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int MAXN = 50010;

vector < int > AdjList[MAXN];
int dist[MAXN];
int subtreeSize[MAXN];
bool used[MAXN];
int n, k;

void calcSubtreeSize(int x, int p = -1){
    subtreeSize[x] = 1;
    for(int y : AdjList[x]){
        if(y == p || used[y]) continue;
        calcSubtreeSize(y, x);
        subtreeSize[x] += subtreeSize[y];
    }
}

int findCentroid(int x, int treeSize){
    for(int y : AdjList[x]){
        //Ignore parent and used vertices.
        if(subtreeSize[y] > subtreeSize[x] || used[y]) continue;

        //If the current node has a child, such that the child's subtree size
        //is bigger than treeSize/2, the centroid will be on that subtree.
        if(2*subtreeSize[y] > treeSize) return findCentroid(y, treeSize);
    }

    //If no such child exist, the current vertex is the centroid. 
    return x;
}

//Problem specific, not part of decomposition.
void calcDist(vector < ll > &freq, int x, int maxDist, int p = -1){
    freq[dist[x]]++;

    if(dist[x] == maxDist) return;
    
    for(int y : AdjList[x]){
        if(y == p || used[y]) continue;
        dist[y] = dist[x]+1;
        calcDist(freq, y, maxDist, x);
    }
}

ll centroidDecomp(int x){
    calcSubtreeSize(x);
    
    int centroid = findCentroid(x, subtreeSize[x]);

//Process paths that go through centroid.
//In this case, find number of pairs (u, v)
//such that the path from u to v has lenght k.
    ll ans = 0;

    vector < ll > total(k+1, 0);
    for(int y : AdjList[centroid]){
        if(used[y]) continue;

        vector < ll > freq(k+1, 0);
        dist[y] = 1;
        calcDist(freq, y, k, centroid);
        
        for(int l=1; l<k; l++){
            ans += freq[l]*total[k-l];
        }
        for(int i=0; i<=k; i++) total[i] += freq[i];
    }

    ans += total[k];

//Remove centroid from tree.
    used[centroid] = true;

//Call function recursively for resulting trees.
    for(int y : AdjList[centroid]){
        if(used[y]) continue;
        ans += centroidDecomp(y);
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;

    for(int i=0; i<n-1; i++){
        int a, b;
        cin >> a >> b;

        AdjList[a].push_back(b);
        AdjList[b].push_back(a);
    }

    cout << centroidDecomp(1) << "\n";

    return 0;
}