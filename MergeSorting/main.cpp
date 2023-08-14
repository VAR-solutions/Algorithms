#include <iostream>
#include <stdio.h>
#include <stdlib.h>


using namespace std;


void merge(int arr[], int p, int q, int r)
{
	int i, j, k;
	int n1 = q - p + 1;
	int n2 = r - q;

	int L[n1], R[n2];

	for (i = 0; i < n1; i++)
		L[i] = arr[p + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[q + 1 + j];


	i = 0;
	j = 0;
	k = p;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}


void mergeSort(int arr[], int p, int r)
{
	if (p < r) {
		int q =  (r + p) / 2;


		mergeSort(arr, p, q);
		mergeSort(arr, q + 1, r);

		merge(arr, p, q, r);
	}
}

int main()
{
    int n = 0;
    cout<<"Number of elements: ";
    cin>>n;
	int arr[n];
	cout<<"Enter elements: ";
	for(int i=0; i<n ; i++)
        cin>>arr[i];



	cout<<"Given array is \n";
	for (int i = 0; i < n; i++)
            cout<<arr[i]<<" ";


	mergeSort(arr, 0, n - 1);

	cout<<"\nSorted array is \n";
	for (int i = 0; i < n; i++)
            cout<<arr[i]<<" ";
	return 0;
}
