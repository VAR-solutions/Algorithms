#include <iostream>
#define ll long long int
using namespace std;
int main(){

	int n;
	cin>>n;
	int a[n+1]={1,1};
	for(int i=2;i<=n;i++)
		a[i]=aa[i-1]*i;

	cout<<a[n]<<endl;
	
}
