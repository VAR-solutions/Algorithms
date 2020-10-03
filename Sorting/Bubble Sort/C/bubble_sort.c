#include<stdio.h>
int main(){
	int i, j, n,  temp;
	int arr[n]; //Declaration
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%d", &arr[i]); //Input Elements Into Array 
	}
	for(i=0;i<n;i++){ 
		for(j=i+1;j<n;j++){
			if(arr[i] > arr[j]){
				temp = arr[i];
				arr[i] = arr[j]; //Sorting The Elements Of The Array
				arr[j] = temp;	
			}
		}
	}
	for(i=0;i<n;i++){
		printf("%d", arr[i]); //Outputting The Sorted Array
	}
	return 0;
}
