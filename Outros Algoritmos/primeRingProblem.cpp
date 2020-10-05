#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int primos[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};

bool prime(int k){
  for(auto n : primos){
    if(n == k) return true;
  }
  return false;
}

bool isSolution(int n, vector<int> &v){
	for(int i = 0 ; i < n ; i++){
		if(!prime(v[i] + v[(i+1)%n])) return false; //%n por causa da ultima posição
	}
	return true;
}

void printa(vector < vector < int > > &solutions){
  int len = solutions.size(), len2 = solutions[0].size();
  for(int i=0; i<len; i++){
    for(int j=0; j<len2; j++){
      if(j == len2 - 1) cout << solutions[i][j];
      else cout << solutions[i][j] << " ";
    }
    cout << endl;
  }
}

void search(int i, vector < int > &v, vector < bool > &visitados, int n, vector < vector < int > > &solutions, vector < int > &sol, int atual){ //atual => se temos n números (de 1 até n) para botar no vector de soluções, fixamos o valor de um deles
  if(i == n){
    //printa as coisas
    if(isSolution(n, sol))  solutions.push_back(sol);
  } else{
    //muda os bagulhos
    for(int j=0; j<n; j++){
      if(visitados[j]) continue;
      if(prime(atual + v[j])){
        visitados[j] = true;
        int aux = atual;
        sol.push_back(j+1);
        atual = j + 1;
        search(i+1, v, visitados, n, solutions, sol, atual);
        visitados[j] = false;
        atual = aux;
        sol.pop_back(); //a ultima solução q botamos n necessariamente eh solução para essa q estamos vendo (n sei explicar isso direito)
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  for(int i=1, n; cin >> n; i++){
    if(i-1) cout << endl; // para n printar o endl a mais no primeiro caso
    vector < int > sol;
    vector < int > v(n);
    vector < bool > visitados(n, false); // para n botar mais do q n elementos em v
    visitados[0] = true; //para o 1 já ser marcado
    sol.push_back(1); //como o 1 já foi marcado como visitado, ele eh posto em nosso v(vector de solução)
    vector < vector < int > > solutions;
    for(int u=0; u<n; u++){
      v[u] = u+1; //no inicio
    }
    cout << "Case " << i << ":" << endl;
    search(1, v, visitados, n, solutions, sol, 1);
    printa(solutions);
  }
  return 0;
}
