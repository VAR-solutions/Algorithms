#include<bits/stdc++.h>  //includes all libraries mainly used in CP
using namespace std;

/*
CODE INTRO:--
this code has 3 functions:
1st- for adding edge
2nd- for printing graph as adjacency list
3rd- bfs implementation
*/

/*

addedge function:
Arguments : 1.adjacency list(adj), 2.first vertex(u), 3.second vertex(v), 4.bool value(twoWay) to check whether itis directed or undirected
then fills list as u-->v
if undirected twoWay will be true and,
v-->u will also gets implemented

*/

void addedge(vector<vector<int>>  &adj, int u, int v, bool twoWay)
{
     adj[u].push_back(v);//u-->v
     if(twoWay)
     adj[v].push_back(u);//v-->u
} 

/*

printgraph function:
Arguments : 1.adjacency list, 2.no. of vertex(n)
loops through whole vertex and goes inside the list of particular vertex to print all vertices
e.g:
[1]-->3-->4-->5
 |
[2]-->1-->3-->6
 |
[3]-->4-->3

o/p will be : 1->3->4->5->2->6

*/

void printgraph( vector<vector<int>> &adj, int n)
{
    for(int v=0;v<n;++v)//for looping no. of vertex basically nodes of array list
    {
        cout<<"all vertex of list - "<<v<<" are: "<<endl;
        cout<<"head->";
        for(auto x:adj[v])//loops through particular vertex
        cout<<"->"<<x;
        cout<<endl;
    }
}

/*

bfs function:
Arguments : 1.adjacency list(adj), 2.no. of vertices(n), 3.source vertex(s) from where u want ur bfs to start
it uses,
queue q: for taking all vertex one-by-one
bool vector used: for marking visited nodes
int vector d: for storing the distance of particular vertex from start
int vector p: for storing the parnet of particular vector 
int vector path: to get the shortest path

*/
void bfs(const vector<vector<int>> &adj,int n, int s)
{
    //vector<vector<int>> adj  adjacency list representation
    //int n  no. of nodes
    //int s  source vetex
    queue<int> q;
    vector<bool> used(n); //for marking visited nodes
    vector<int> d(n), p(n); //for distance and parent
    vector<int>path;
    q.push(s);//first pushes this source vertex to the queue to find all the connected vertices of s
    used[s]=true;//marked visited
    p[s]=-1;
    d[s]=0;
    while(!q.empty())//loop until queue becomes empty
    {
        int v=q.front();//take first vertex of queue
        path.push_back(v);//push it into path vector
        q.pop();
        for(int u : adj[v])//find all vertices connected with that vertex
        {
            //for traversing
            if(!used[u])//if that vertex is not visited make it visit
            {
                used[u]=true;
                q.push(u);
                d[u]=d[v]+1;//find distance
                p[u]=v;//find parent
            }
        }
    }
    cout<<"path :";//prints shortest path
    for(auto x:path)
    cout<<x<<" ";
}

int main()
{
   

    int n1,n2;
    cout<<"enter no. of nodes : ";
    cin>>n1;
    cout<<"enter no. of edges :";
    cin>>n2;
    cout<<"enter vertex";
    int u,v;
    vector<vector<int>> adj(n1+1);//adjacency list 
    char ch;
    for(int i=0;i<n2;i++)
    {
        cout<<"enter two vertex :\n";
        cin>>u;
        cin>>v;
        cout<<"y: undirected -";// asks for directed or undirected
        cin>>ch;
        if(ch=='y')
        addedge(adj,u,v,true);
        else
        addedge(adj,u,v,false);
    }
     printgraph(adj,n1);
     cout<<"enter the sorce vertex : ";
     int s;
     cin>>s;
     bfs(adj,n1,s);//finds bfs
}
