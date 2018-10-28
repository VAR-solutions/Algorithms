#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    int c = N-1;

    vector<int> G[10005];
    bool vis[10005];
    int nLevel[10005]; //node level
    
	//input Example
	//4
	//1 2
	//2 5
	//5 1
	//1 3

    while((c)--)
    {
        int a, b;
        cin >> a >> b;
        
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    int x;
    cin >> x;
    
    queue<int> v;
    v.push(1); //Add node 1 as root
    nLevel[1] = 1;
    vis[1] = true;
    
    while(!v.empty())
    {
        int p = v.front();
        v.pop();

        for(auto i = 0; i < G[p].size(); i++)
        {
            if(vis[G[p][i]] == false)
            {
                vis[G[p][i]] = true;
                nLevel[G[p][i]] = nLevel[p] + 1;
                v.push(G[p][i]);
            }
        }
    }
    
    int nodesInX = 0;
    
    for(int i=1; i <= N; i++)
    {
	    if(nLevel[i] == x)
	        nodesInX++;
    }
    
    cout << nodesInX;
    
    return 0;
}
