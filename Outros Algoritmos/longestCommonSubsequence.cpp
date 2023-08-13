#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

/*
A matriz eh o seguinte -> linha = string a + empty string e coluna = string b + empty string
quando faço lcs[i][j] estou vendo o lcs da string a até o caractere na posição i - 1 e semelhante com a string b
seria parecido fazendo de forma recursiva (porém deu problemas)
*/
int search(string a, string b){
  vector < vector < int > > lcs(a.size() + 1, vector < int > (b.size() + 1));
  for(int i = 0; i <= a.size(); i++){
    for(int j = 0; j <= b.size(); j++){
      if(!i || !j) lcs[i][j] = 0; //lcs com strings vazias
      else if(a[i-1] == b[j-1]) lcs[i][j] = 1 + lcs[i-1][j-1];
      else lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
    }
  }
  return lcs[a.size()][b.size()];
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  string a, b;
  while(getline(cin, a) && getline(cin, b)){
    cout << search(a, b) << endl;
  }
  return 0;
}
