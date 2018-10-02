#include<bits/stdc++.h>
using namespace std;
string binarySearch(vector <int> a,int l,int r,int num)
{
    int mid = l + (r-l)/2;
    if(r>=l)
    {
        if(a[mid] == num)
        return("Found");
        else if(a[mid] > num)
        return(binarySearch(a,l,mid-1,num));
        else
        return(binarySearch(a,mid+1,r,num));

    }
    else
    return("Not Found");
}
int main()
{
    int n;
    cout<<"Enter total number of elements: ";
    cin>>n;
    cout<<"Enter Elements";
    int i = n;
    vector <int> a;
    while(i--)
    {
        int t;
        cin>>t;
        a.push_back(t);
    }
    int num;
    cout<<"enter number to search";
    cin>>num;
    cout<<binarySearch(a,0,n,num);
}