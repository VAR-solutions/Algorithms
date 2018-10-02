/* Insertion Sort implementation in C++
 * Author : Manvi Gupta
 * Input : array length and elements
 * Output : Sorted array elements
 */  

#include <iostream>
using namespace std;

int n;
void insertionSort(int A[])
{
	int key;
  for(int i=0;i<n;i++)
  {
    key = A[i];
    int j = i-1;
    while(j>=0 and key<A[j])
    {
      A[j+1] = A[j];
      j--;
    }
    A[j+1]=key;
    }
}

int main()
{
  std::cout << "Enter the array length: ";
  std::cin >> n;
  int A[n];
  std::cout << "Enter the array elements :" << '\n';
  for(int i=0; i<n; i++)
  cin >> A[i];
  insertionSort(A);
  std::cout << "Sorted Array :" << '\n';
  for(int i=0;i<n;i++)
  cout << A[i] << endl;
  return 0;
}
