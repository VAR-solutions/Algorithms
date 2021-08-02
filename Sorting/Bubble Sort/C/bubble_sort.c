/* Bubble Sort implementation in C;
 * Author : Felipe Gabriel;
 * Input : Array lenght and elements;
 * Output : Sorted array elements;
*/
// optimization of bubble_sort in lower bound complexity (best case scenario)
// demonstration of c features like pointers , passing by reference 
// design code more better by using functions for micro-programs 
// Author : Boussebha Wassim

#include "bubble_sort.h"

int main()
{
	int j;
	do
	{
		scanf("%d",&n);
	} while (n > 31); // never trust the user max = 30
	
	int *v = (int*)malloc(n * sizeof(int));

	for(j = 0; j < n; j++)
	{
		scanf("%d",v+j);
	}		
	array_print(v); // before
	bubble_sort(v);
	array_print(v); // after
	free(v);
	
	return 0;
}
void array_print(int *v)
{
	for(int j = 0; j < n; j++)
	{
		if(j != n-1)
			printf("%d ",v[j]);
		else
			printf("%d\n",v[j]);
	}
}

void bubble_sort(int *v)
{
	int i,k;
	for(i = 0; i < n; i++)
	{
		for(k = 0; k < n - i -1; k++)
		{
			if(v[k] > v[k+1])
				swap(v+k,v+k+1);
				if(swapped == 0)
					return;
		}
	}

}
void swap(int *a, int *b)
{
	int aux = *b;
	*b = *a;
	*a = aux;
	swapped++; // it is a global variable declared in bubble_sort.h , intitliazed with 0
}