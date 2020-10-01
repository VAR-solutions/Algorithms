#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vi;
vector<vector<vi>> g;
vector<vector<int>> grid;

void seta(vi &att){
	
		for(int i=0;i<att.size();i++){
			grid[att[i].first][att[i].second] = 1;
		}
}

void reseta(vi &att){
	
		for(int i=0;i<att.size();i++){
			grid[att[i].first][att[i].second] = 0;
		}
}

bool valid(int u,int v){
	
	if(u<0 || v <0) return true;
	else if(grid[u][v] == 1) return false;
	else return true;
}

void attr(vi &a, vi &b){

	int xmini = a[0].first;
	int ymini = a[0].second;
	
	for(int i=0;i<b.size();i++){
			a.push_back(b[i]);
			xmini = min(xmini,b[i].first);
			ymini = min(ymini,b[i].second);
	}

	for(int i=0;i<a.size();i++){
			a[i].first -= xmini;
			a[i].second -= ymini;
	}

	sort(a.begin(),a.end());
}

void preProcess(int n){

		vi aux;
		g.resize(n);
		grid.resize(11);
		for(int i=0;i<11;i++){
			grid[i].resize(11);
		}		

		int dl[] = {-1,1,0,0};
		int dc[] = {0,0,-1,1};

		aux.push_back({0,0});
		g[0].push_back(aux);

		for(int i=1;i<n;i++){
			set<vi> all;
			for(int j=0;j<g[i-1].size();j++){
				seta(g[i-1][j]);

				for(int k=0;k<g[i-1][j].size();k++){
						int u = g[i-1][j][k].first;
						int v = g[i-1][j][k].second;

						for(int l=0;l<4;l++){
								
								if(valid(u+dl[l],v+dc[l])){
										aux.clear();
										aux.push_back({u+dl[l],v+dc[l]});
										attr(aux,g[i-1][j]);
										all.insert(aux);
								}
						}
				}				

				reseta(g[i-1][j]);
			}

			for(auto atual: all){
				g[i].push_back(atual);
			}

			//cout << "tam " << i+1 << ": " << g[i].size() << endl;
		}
}

int main(){

	//preProcess(10);
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,m;
	cin >> n >> m;
	vector<vector<int>> mapa;
	preProcess(m);
	mapa.resize(n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int a;
			cin >> a;
			mapa[i].push_back(a);
		}
	}

	int maxi = 0;
	m--;
	for(int i=0;i<g[m].size();i++){
		int sum = 0;
		int xmax = 0;
		int ymax = 0;
		for(int j=0;j<=m;j++){
			xmax = max(xmax,g[m][i][j].first);
			ymax = max(ymax,g[m][i][j].second);
		}
		
		for(int j=0;j<n-xmax;j++){
			for(int k=0;k<n-ymax;k++){
				sum = 0;
				for(int z=0;z<=m;z++){
					sum += mapa[j+g[m][i][z].first][k+g[m][i][z].second];
				}	
				maxi = max(maxi,sum);
			}
		}
	}
	
	cout << maxi << endl;
}
