#include <bits/stdc++.h>
#define ll long long
using namespace std;

//Linear time partition algo
ll partition_(ll arr[], ll i, ll j, ll p){
	//arr[i..k..j]
	ll l, r;
	l=r=0;
	std::swap(arr[l], arr[p]);
	p=0;
	while(r <= j){
		if(arr[r]< arr[p]){
			std::swap(arr[++l], arr[r]);
		}
		r++;
	}
	std::swap(arr[l], arr[p]);
	return l;
}

//In-place algorithm
//requires O(1) memory if compiler is tail call optimized
//selection of pivot is randomized to avoid worst case pivot selection
//leading ot amortized T.C = O(n)
ll quick_select(ll arr[], ll size_arr, ll N){
	N-=1;//Nth smallest will be at index N-1
	ll i = 0;
	ll j = size_arr - 1;

	while(i <= j){
		srand(time(NULL));
		ll p = rand()%(j-i+1)+i;
		p = partition_(arr, i, j, p);
		if(p == N){
			break;
		}
		else if(p < N){
			i = p+1;
		}
		else{
			j = p-1;
		}
	}
	return arr[N];
}
//run a comparison b/w randomized version of quickselect and 
//inbuilt nth_element which utilizes 
//intro select algorithm
int main(int argc, char const *argv[]){
	ll size_arr;
	ll ans;
	clock_t t;
	cin>>size_arr;
	ll arr[size_arr];
	std::vector<ll> v;
	for(ll i=0; i<size_arr; i++){
		cin>>arr[i];
		v.push_back(arr[i]);
	}
	ll N;
	cin>>N;	
	t = clock();
	ans = quick_select(arr, size_arr, N);
	t = clock() - t;
	cout<<"quickselect returned in "<<((float)t/CLOCKS_PER_SEC)<<" seconds: ";
	cout<<ans<<"\n";

	t = clock();
	std::nth_element(v.begin(), v.begin() + N -1, v.end());
	t = clock() - t;
	cout<<"intro select returned in "<<((float)t/CLOCKS_PER_SEC)<<" seconds: ";
	cout<<v[N-1]<<"\n";


	return 0;
}