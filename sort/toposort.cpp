#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define n 7
void toposort(vector<vector<int>> grafo, int *visitados, stack<int> &pilha, int no){
    visitados[no] = 1;
    for(auto w: grafo[no]){
        if(visitados[w]==0){
            toposort(grafo, visitados, pilha, w);
        }
        pilha.push(no);
    }
}
int main()
{
    vector<vector<int>> grafo(n);
    stack<int> pilha;
    int visitados[n]={};
    return 0;
}
