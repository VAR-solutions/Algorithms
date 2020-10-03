#include <iostream>
#include <algorithm>
using namespace std;

void triplesum(int a[],int n,int k){

// This Algorithm finds the Triple Sum pairs in array whose sum is equal to our target value
	
	int s=0,e=n-1;
	for(int i=0;i<n;i++){
		int s=i+1,e=n-1;
		while(s<e){
			int target=k-a[i];
			int sum=a[s]+a[e];
			if(sum>target){
				e--;
			}
			else if(sum<target){
				s++;
			}
			else if(sum==target){
				cout<<a[i]<<", "<<a[s]<<" and "<<a[e]<<endl;
				s++;
				e--;
			}


		}

	}
}

int main(){
	int n;
	cout<<"Enter the maximum number of elements you want to enter in array :"<<endl;
	cin>>n;
	cout<<"Enter the "<<n<<" elements of array :"<<endl;
	int arr[1000];
	for (int i=0;i<n;i++){
		cin>>arr[i];
	}

	cout<<"Enter the target value whose sum triple pairs you want to find in array :"<<endl;
	int target;
	cin>>target;
	sort(arr,arr+n);
	cout<<"The triple pairs which have the sum Equal to our target are :"<<endl;
	triplesum(arr,n,target);

	return 0;
}
