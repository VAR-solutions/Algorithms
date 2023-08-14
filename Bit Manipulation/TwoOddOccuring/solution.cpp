#include<iostream>
using namespace std;

void findOddOnes(int a[], int n)
{
    int xor_val = 0, res1 = 0, res2 = 0;
    for (int i=0;i<n;i++){xor_val ^= a[i];}
    int sb = xor_val & ~(xor_val-1);
    for (int i=0;i<n;i++)
    {
        if ((a[i] & sb)!=0)
        {
            res1 ^= a[i];
        }
        else{
            res2 ^= a[i];
        }
    }
    cout<<res1<<" "<<res2<<endl;
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    findOddOnes(a, n);
    return 0;
}
