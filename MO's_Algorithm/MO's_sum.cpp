#include <bits/stdc++.h>
using namespace std;
int BLOCK,answer=0;
int a[1000000],ans[100000];
struct node {
	int L, R, i;
}q[1000000];
bool cmp(node x, node y)
{
    if (x.L/BLOCK != y.L/BLOCK)
        return x.L/BLOCK < y.L/BLOCK;
    return x.R < y.R;
}
int main() {
	int n;
	scanf("%d", &n);
	BLOCK=sqrt(n);
	for(int i=0; i<n; i++)
		scanf("%d", &a[i]);
 
	int m;
	scanf("%d", &m);
	for(int i=0; i<m; i++) 
	{
		scanf("%d%d", &q[i].L, &q[i].R);
		q[i].L--; q[i].R--;
		q[i].i = i;
	}
 
	 sort(q, q + m, cmp);
     int start = 0, end = 0;
     
     for(int i=0; i<m; i++) 
	 {
	 int L = q[i].L, R = q[i].R;
	    while (start < L)
        {
            answer -= a[start];
            start++;
        }
        while (start > L)
        {
            answer += a[start-1];
            start--;
        }
        while (end <= R)
        {
            answer += a[end];
            end++;
        }
        while (end > R+1)
        {
            answer -= a[end-1];
            end--;
        }
        ans[q[i].i] = answer;
	  }
       	for(int i=0; i<m; i++)
		printf("%d\n", ans[i]);
	cin>>answer;
}
