#include<bits/stdc++.h>
#include <iostream>
using namespace std;
int main(){
	string s;
	int t, l;

	while(t--){
		cin>>s;
		l = s.length();
		int c[1000], a=0;

		for(int i=0; i<l; i++){
			if(s[i]=='A') s[i]='4';
			if(s[i]=='E') s[i]='3';
			if(s[i]=='I') s[i]='!';
			if(s[i]=='L') s[i]='1';
			if(s[i]=='O'){ s[i]='(';
			c[a] = i;
			a++;}

			if(s[i]=='S') s[i]='5';
			
		}
		for(int z=0; z<=a; z++){
			int b = c[a];


		s = s.substr(0, b+1) + ')' + s.substr(b+1, l-b-1);

		}
			for(int y=0; y<=l; y++){
				cout<<s[y];
			}

		cout<<endl;

	}
	return 0;
}