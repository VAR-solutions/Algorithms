#include<iostream>
#define max_in 1048575
using namespace std;

void constructTree(int inp[],int segTree[],int low, int high, int pos)
{
    if(high == low)
    {
        segTree[pos] = inp[low];
        return;
    }
    int mid = (low + high)/2;
    constructTree(inp,segTree,low,mid,2*pos+1);
    constructTree(inp,segTree,mid+1,high,2*pos+2);
    segTree[pos] = segTree[2*pos+1] & segTree[2*pos+2];
}

int minQuery(int segTree[],int qlow, int qhigh, int low, int high, int pos)
{
    if(qlow <= low && qhigh >= high ) //total overlap
    return segTree[pos];
    if(qlow > low || qhigh < high)
    return max_in;
    int mid = (low + high)/2;
    return(minQuery(segTree,qlow,qhigh,low,mid,2*pos+1) & minQuery(segTree,qlow,qhigh,mid+1,high,2*pos+2));
}

int main()
{
    int n = 3;
    int a[] = {1,2,3};
    int seg[7];
    for(int i=0;i<7;i++)
    seg[i] = max_in;

    constructTree(a,seg,0,n-1,0);
    cout<<minQuery(seg,1,3,0,n-1,0);
    for(int i=0;i<7;i++)
    cout<<seg[i]<<endl;
}
