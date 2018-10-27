#include <bits/stdc++.h>
#define MAX 1000007

using namespace std;

struct node{
	int link, len;
	map<char, int> next;
} st[MAX];

int sz, last;

void init(){
	sz = 1;
	last = 0;
	st[0].len = 0;
	st[0].link = -1;
	st[0].next.clear();
}

void add(char c){
	int cur = sz++;
	st[cur].len = st[last].len + 1;

	for(; last != -1 && !st[last].next[c]; last = st[last].link) st[last].next[c] = cur;

	if(last == -1) st[cur].link = 0;
	else{
		int q = st[last].next[c];
		if(st[q].len == st[last].len + 1) st[cur].link = q;
		else{
			int clone = sz++;
			st[clone].len = st[last].len + 1;
			st[clone].link = st[q].link;
			st[clone].next = st[q].next;

			for(; last != -1 && st[last].next[c] == q; last = st[last].link) st[last].next[c] = clone;
			st[q].link = st[cur].link = clone;
		}
	}
	last = cur;
}
int main(){
	string palavra; cin >> palavra;
	init();
	for(int i = 0; i < palavra.size(); i++) add(palavra[i]);
	return 0;
}