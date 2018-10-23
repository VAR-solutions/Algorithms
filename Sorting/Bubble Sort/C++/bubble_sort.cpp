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
   for(int j=0; j<n-1-i; j++)
   if(a[j] > a[j+1])
   {
     swap(a[j+1], a[j]);
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
     std::cout << a[i] << '\n';
   }
   return 0;
 }
