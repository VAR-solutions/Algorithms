#include<iostream>
using namespace std;
int main()  //Bubble Sort
{
    int a[7]={22,1,4,77,33,11,8},N=7,l=0;
    void swap(int*,int*);
    cout<<"Your array:\n";
    for(int i=0;i<N;i++)
        cout<<a[i]<<"\t";
    cout<<endl;
    cout<<"After Bubble sort\n";
    for(int i=0;i<N;i++)
    {
        l=0;
        for(int j=l;j<N-1;j++)
        {
            if(a[j]>a[j+1]){
                swap(&a[j],&a[j+1]);
            }
            l++;
        }
    }

    cout<<"\nUpdated array is:\n";
    for(int i=0;i<N;i++)
        cout<<a[i]<<"\t";

    return 0;
}
void swap(int *a,int *b )
{
    int c;
    c=*a;
    *a=*b;
    *b=c;
}
