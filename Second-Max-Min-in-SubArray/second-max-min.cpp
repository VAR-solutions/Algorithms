#include<iostream>
#include<limits.h>
using namespace std;

int calculate(int a[],int start,int endd){
    cout<<"start-"<<start<<" "<<"end-"<<endd<<endl;
    int min1=INT_MAX,min2=INT_MAX,max1=INT_MIN,max2=INT_MIN,i,k=0;
    for(i=start;i<=endd;i++){
            if(a[i]>max1){
                max2=max1;
                max1=a[i];
            }
            else if(a[i]>max2 && a[i]!=max1){
                max2=a[i];
            }
    }
    for(i=start;i<=endd;i++){
          if(a[i]<min1){
                min2=min1;
                min1=a[i];
            }
            else if(a[i]<min2 && a[i]!=min1){
                min2=a[i];
            }
    }
    cout<<"min-"<<min2<<" "<<"max-"<<max2<<endl;
    return min2+max2;
}

int main(){
    int n,i,j,start,endd,k;
    cin>>n>>k;
    int a[n];
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    for(i=0,j=k-1;j<n;i++,j++){
        int ans=calculate(a,i,j);
        cout<<ans<<endl;
    }
    return 0;
}
