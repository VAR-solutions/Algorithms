#include<iostream>
using namespace std;
int main(){
	int i, j, n, search;
	cin >> n;
	int arr[n]; //Declaration
	for(i=0;i<n;i++){
		cin >> arr[i]; //Input Elements Into Array 
	}
	cin >> search; //Inputting the search element
	for(i=0;i<n;i++){
		if(arr[i] == search){
			cout << "Element Found at the position " << i+1 << endl; //Linear Search Algorithm
			break;
		}
	}
	if(i == n){
		cout << "Element Not Found"; //In case if element is not there
	}
	return 0;
}
