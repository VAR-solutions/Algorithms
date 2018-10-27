#include <iostream>

using namespace std;

int main()
{
int n,mid,element;
cout<<"enter size of array";
cin>>n;
int low=0,high=n-1;
int arr[n];
cout<<"Enter sorted Array elements"<<endl;
for(int i=0;i<n;i++)
{
    cin>>arr[i];
}
cout<<"Enter the element to search";
cin>>element;
while(low<=high)
   {

    mid=(low+high)/2;//finding of mid by adding starting and ending indexes and dividing by 2
if(element==arr[mid])
    {cout<<"found at:"<<mid+1;
    break;
    }
    if(element>=arr[mid])//if value to search is greater so operate on right of mid
    {
        low=mid+1;
    }
    else if(element<=arr[mid])//if value to search is smaller so operate on left of mid
    {
        high=mid-1;
    }
    else
    {
       cout<<"NOT FOUND";
        return -1;
    }
   }
}/*Implementation of binary search algorithm
in c++.A conventional search technique which is a divide and conquer algorithm based on 
deriving subarrays out of base data and operating on right and left of mid making subarrays w.r.t 
whether the key value to search is greater or smaller than mid*/ 





