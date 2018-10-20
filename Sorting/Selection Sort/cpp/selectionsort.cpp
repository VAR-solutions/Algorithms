#include<iostream>
using namespace std;

int main()
{
	int size, arr[50];
	cout << "Enter Array Size: ";
	cin >> size;
	cout << "Enter Array Elements: ";
	for(int i = 0; i < size; i++) {
		cin >> arr[i];
	}

	cout << "Sorting array using Selection Sort...\n";
	for(int i = 0; i < size; i++) {
		for(int j = i+1; j < size; j++) {
			if(arr[i] > arr[j]) {
				swap(arr[i], arr[j]);
			}
		}
	}
	cout << "Now the Array after sorting is :\n";
	for(int i=0; i<size; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}
