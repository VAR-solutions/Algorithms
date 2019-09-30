/* Bubble Sort implementation in C++
 * Author : Manvi Gupta
 * Input : array length and elements
 * Output : Sorted array elements
 */
#include <iostream>
using namespace std;

int n;

void bubble_Sort(int a[])
{

 	for(int i=0; i<n-1; i++)
 	{
 		int flag = 0;  // Declaring a variable to check if elements have been sorted in this iteration.
 		for(int j=0; j<n-1-i; j++)
 		{
 			if(a[j] > a[j+1])
 			{
   			swap(a[j+1], a[j]);
   			flag = 1;		// Set flag = 1 to signify that the element is sorted.c
 			}
 		}	
 		if (flag == 0)
 		{
 			// No elements have been swapped, which means that the array is sorted. End the algorithm.
 			break;
 		}
 	}
}

int main()
{
	cout<<"Enter the size of the array"<<endl;
	cin >> n;
	int a[n];
	cout<<"Enter the elements of the array"<<endl;
	for(int i=0; i<n; i++)
	cin >> a[i];
	bubble_Sort(a);
	cout<<"The sorted array is : "<<endl;
	for (int i = 0; i < n; i++) {
		cout << a[i] << '\n';
  }
  return 0;
}
