/* Bubble Sort implementation in C;
 * Author : Felipe Gabriel;
 * Input : Array lenght and elements;
 * Output : Sorted array elements;
*/

#include <stdio.h>

int n;

void bubble_sort(int v[]){
	int i,k,aux = 0;
	for(i = 0; i < n; i++){
		for(k = 0; k < n-1; k++){
			if(v[k] > v[k+1]){
				aux = v[k+1];
				v[k+1] = v[k];
				v[k] = aux;
			}
		}
	}

}


int main(){
	int j;
	scanf("%d",&n);
	int v[n];

	for(j = 0; j < n; j++){
		scanf("%d",&v[j]);
	}
	bubble_sort(v);
	for(j = 0; j < n; j++){
		if(j != n-1){
			printf("%d ",v[j]);
		}
		
		else{
			printf("%d\n",v[j]);
		}
	}
	
	return 0;
}
