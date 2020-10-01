#include<bits/stdc++.h>
using namespace std;

int main(){
	int product[100][100];
	int n, m;               //n is no of rows and m is no of column
	cin >> n >> m;
	int a[n][m];

	for(int i=0; i<n; i++){
	for(int j=0; j<m; j++)
	 cin >> a[i][j];
	}

    int minr = 0;       // min row
    int maxr = n-1;     // max row
    int minc = 0;       // min column
    int maxc = m-1;     // max column
    int count = 0;
    int tno = n*m;

    while(count < tno){
    	//left wall
       for (int i = minr, j=minc; i <=maxr && count<tno; ++i)            
       {
       	 cout << a[i][j] << endl;
       	 count++;
       }
       minc++;
        
        //bottom wall
       for (int i = maxr, j=minc; j <=maxc && count<tno; ++j)
       {
       	 cout << a[i][j] << endl;
       	 count++;
       }
       maxr--;

        //right wall
       for (int i = maxr, j=maxc; i>=minr && count<tno; i--)
       {
       	 cout << a[i][j] << endl;
       	 count++;
       }
       maxc--;
      
       //top wall
       for (int i = minr, j=maxc; j>=minc && count<tno; j--)
       {
       	 cout << a[i][j] << endl;
       	 count++;
       }
       minr++;
    }

	return 0;
}
