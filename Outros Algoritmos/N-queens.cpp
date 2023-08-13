#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int TAMANHO_DO_TABULEIRO;

//dentro do tabuleiro
bool isInside(int i, int j){
  if(i >= 0 && j >= 0 && i < TAMANHO_DO_TABULEIRO && j < TAMANHO_DO_TABULEIRO) return true;
  return false;
}

bool isNotAttacked(int i, int j, vector<vector<bool>> table){
  //n precisa checar as colunas (ao contrário do normal)
  //checa linha
  for(int x = 0; x < TAMANHO_DO_TABULEIRO; x++){
    if(table[i][x]) return false; //ve se tem alguem na msm linha
  }
  //diagonal principal
  for(int linha = i, col = j; isInside(linha,col) ; linha--,col--){
    if(table[linha][col]) return false;
  }
  for(int linha = i, col = j; isInside(linha,col) ; linha++,col++){
    if(table[linha][col]) return false;
  }
  //a outra diagonal
  for(int linha = i, col = j; isInside(linha,col) ; linha--,col++){
    if(table[linha][col]) return false;
  }
  for(int linha = i, col = j; isInside(linha,col) ; linha++,col--){
    if(table[linha][col]) return false;
  }
  
  return true;
}

bool isTwoDigit(int x){
	if(!(x/10)) return false;
	return true;
}

void printa(vector < vector < int > > &solutions){
  cout << "SOLN       COLUMN" << endl;
  cout << " #      ";
  for(int i=1; i<=TAMANHO_DO_TABULEIRO; i++){
    cout << i << " ";
  }
  cout << endl << endl;
  for(int i = 0 ; i < solutions.size() ; i++){
			if(!isTwoDigit(i + 1))cout << " " << i+1 << "      ";
			else cout << i + 1 << "      ";
			for(int j = 0; j < solutions[i].size(); j++){
				if(j == solutions[i].size() - 1) cout << solutions[i][j] + 1;
				else cout << solutions[i][j] + 1 << " ";
			}
			cout << endl;
		}
}

//fazendo coluna por coluna pra deixar em ordem alfabética
void recursion(int i, vector < int > &queens, vector < vector < int > > &solutions, vector < vector < bool > > &table){ //i = numero da rainha, top = ja tentei todas as posições para essa rainha
  if(i == TAMANHO_DO_TABULEIRO) solutions.push_back(queens); //fora do tabuleiro
  else if(queens[i] != -1) recursion(i+1,queens,solutions,table);
  else{
  	for(int row = 0 ; row < TAMANHO_DO_TABULEIRO ; row++){
      if(isNotAttacked(row, i, table)){
        table[row][i] = true;
        queens[i] = row; //a rainha eh o row
        recursion(i+1,queens,solutions,table);
        table[row][i] = false;
        queens[i] = -1;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << "Digite o tamanho do tabuleiro: " << endl;
  cin >> TAMANHO_DO_TABULEIRO;
  vector<vector<bool>> table(TAMANHO_DO_TABULEIRO, vector < bool > (TAMANHO_DO_TABULEIRO, false));
  vector < vector < int > > solutions;
  vector < int > queens(TAMANHO_DO_TABULEIRO, -1);
  recursion(0, queens, solutions, table);
  printa(solutions);
  return 0;
}
