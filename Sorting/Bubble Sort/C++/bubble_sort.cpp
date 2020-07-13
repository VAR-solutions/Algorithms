/* Bubble Sort implementation in C++
 * Author : Manvi Gupta
 * Input : array length and elements
 * Output : Sorted array elements
 */
#include <iostream>
using namespace std;

void bubble_Sort(int a[],int n)
{
	for(int i=0; i<n-1; ++i)
 	{
 		for(int j=0; j<n-i-1; ++j)
 		{
 			if(a[j] > a[j+1])
 			{
   			swap(a[j+1], a[j]);
 			}
 		}	
 	}
}

int main()
{
	int n,i;
	cout<<"Enter the size of the array"<<endl;
	cin >> n;
	int a[n];
	cout<<"Enter the elements of the array"<<endl;
	for(i=0; i<n; ++i){
		cin >> a[i];
	}
	bubble_Sort(a,n);
	cout<<"The sorted array is : "<<endl;
	for (int i = 0; i < n; ++i) {
		cout << a[i] << '\n';
  		}
  	return 0;
}
