#include <bits/stdc++.h>

using namespace std;
class NQueen{
	set<int> column,main_diagonal,opposite_diagonal;
	bool safePos(int row,int col){
		if(column.find(col)!= column.end() || main_diagonal.find(row+col)!=main_diagonal.end() || opposite_diagonal.find(row-col)!=opposite_diagonal.end())
			return false;
		column.insert(col);
		main_diagonal.insert(row+col);
		opposite_diagonal.insert(row-col);
		return true;
	}
	void delPos(int row,int col){
		column.erase(col);
		main_diagonal.erase(row + col);
		opposite_diagonal.erase(row-col);
	}
	bool solve(int row,int n,vector<vector<bool>>& board){
		if(n==row)
			return true;
		for(int i=0;i<n;i++){
			if(safePos(row,i)){
				board[row][i] = true;
				if(solve(row+1,n,board))
					return true;
				board[row][i] = false;
				delPos(row,i);
			}
		}
		return false;
	}
public:
	bool solve(vector<vector<bool>>& board,int n){
		if(board.size() != n)
			throw "Error!";
		for(int i=0;i<board.size();i++)
			if(board[i].size() != board.size())
				throw "Error!";
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				board[i][j] = false;
		return solve(0,n,board);
	}
};

int main(){
	vector<vector<bool>> b(4,vector<bool>(4,false));
	NQueen nq;
	nq.solve(b,4);
	for(auto i:b){
		for(auto j:i)
			cout<<j<<" ";
		cout<<endl;
	}
}