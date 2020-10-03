#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
 
 
void bucketSort(float a[], int n)
{
    vector<float> t[n];
    
    for (int i=0; i<n; i++)
    {
       int x = n*a[i];                //mutyplying the array element with the size of array ( here we had used n because let's say if one of the element was 1 so it would max go upto size of array (if we multiply some larger no that the size of array then we end up getting segmentation fault))
       t[x].push_back(a[i]);          //pushing back the element to the  position x vector                     
    }
 
    for (int i=0; i<n; i++)
       sort(t[i].begin(), t[i].end());                //you could think of why we need to sort the vector ( reson for that is like when we multiply the float no with the int we can end up getting  2 or more same value of x for different values in  a (int array) (in this particluar soln our a array contains 0.324 and 0.245 so multiplying with the 6(size of array) would end up resulting 1(x value) for both as 0.324 is before the 0.245 so we end up storing the 0.324 before 0.245 )
 
    int k= 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < t[i].size(); j++)           // copying all the elemtn from the vector array to our previous array of elements
          a[k++] = t[i][j];
}
 
int main()
{
    float a[] = {0.765, 0.324, 0.111, 0.951, 0.245, 0.48};
    int n = sizeof(a)/sizeof(a[0]);
    cout << "Elements before Sorting\n";
    for (int i=0; i<n; i++)
    cout << a[i] << " ";
    
    bucketSort(a, n);
    
    cout << "\nElements After Sorting \n";
    for (int i=0; i<n; i++)
       cout << a[i] << " ";
    return 0;
}
