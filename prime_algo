#include<iostream>
using namespace std;
void primeSieve(int *p,int n){
    int i;
    for(i=2;i<=5000000; i++)
    {
        p[i]=1;
    }
    
    for(i=2;i<=5000000;i++)
    {
        if(p[i]==1)
        {
            
            for(int j=i*i;j<=5000000;j+=i)
            {
                p[j]=0;
            }
        }
    }
    p[1]=0;
    p[0]=0;   
    return ;
}
int main() {
    int arr[5000001] = {0};
    int n;
    cin>>n;
    int counter = 0;
    primeSieve(arr,n);
    for(int i=0;i<=5000000;i++)
    {
        if(arr[i]==1)
        {
            counter++;
        }
        if(counter==n){
            cout << i;
            break;
        }
    }
    
    return 0;
}
