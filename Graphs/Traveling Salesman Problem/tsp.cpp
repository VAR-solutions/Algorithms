#include <bits/stdc++.h>
using namespace std;

double V[16][16];
vector<pair<int,int> > P;
int n;

double dp[20][1 << 16];

inline double calc(int i,int j){
	return sqrt((P[i].first-P[j].first)*(P[i].first-P[j].first) + (P[i].second - P[j].second)*(P[i].second - P[j].second));
}

double solve(int current, int mask){
	if(mask == ((1<<(n+1))-1)){
		return V[current][0];
	}
	
	if(dp[current][mask]!=-1) return dp[current][mask];
	
	double ans = 1e9 + 10;
	
	for(int i=1;i<=n;i++){
		if(!(mask & (1<<i)))
			ans = min(solve(i,mask | (1<<i))+V[current][i],ans);
	}
	return dp[current][mask] = ans;
}


main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int x,y,a,b;
	while(cin >> n and n){
		P.clear();
		for(int i=0;i<=n;i++){
			for(int j=0;j<=(1<<(n+1));j++){
				dp[i][j] = -1;
			}
		}
		cin >> x >> y;
		P.push_back(make_pair(x,y));
		for(int i=1;i<=n;i++){
			cin >> a >> b;
			P.push_back(make_pair(a,b));
		}
		for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++){
				V[i][j] = calc(i,j);
			}
		}
		cout << fixed << setprecision(2) << solve(0,1) << endl;
	}
}

