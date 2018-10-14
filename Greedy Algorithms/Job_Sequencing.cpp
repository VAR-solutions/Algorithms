#include<bits/stdc++.h>
using namespace std;

struct JOB{

    char job;
    int dline;
    int profit;
};

bool comparision(JOB a,JOB b){
    return (a.profit>b.profit); //Sorting according to MAXIMIZE Profit
}

void job_Sequencing(struct JOB a[],int n){

    sort(a,a+n,comparision); //max to min Profit

    //Finding max deadline => MAX Size of output Array

    int max_deadline=0;
    for(int i=0;i<n;i++){
        if(a[i].dline>max_deadline){
            max_deadline=a[i].dline;
        }
    }
    //cout<<max_deadline;

    char output[max_deadline+1];
    for(int i=1;i<=max_deadline;i++){
        output[i]='?';
    }

    for(int i=0;i<n;i++){
        if(output[a[i].dline]=='?'){
            output[a[i].dline]=a[i].job;
        }
        else{
            int x=a[i].dline-1;  //finding vacant space
            while(output[x]!='?'){
                --x;
            }
            if(x>=1){
                output[x]=a[i].job;
            }
        }
    }

    for(int i=1;i<=max_deadline;i++){
        if(output[i]!='?'){
            cout<<output[i]<<' ';
        }
    }
}

int main(){
    int n;
    cout<<"Enter Number of Jobs: ";
    cin>>n;
    struct JOB a[n];
    cout<<"Enter Job names: ";
    for(int i=0;i<n;i++){
        cin>>a[i].job;
    }
    cout<<"Enter Deadline For Each Job: ";
    for(int i=0;i<n;i++){
        cin>>a[i].dline;
    }
    cout<<"Enter Profit For Each Job: ";
    for(int i=0;i<n;i++){
        cin>>a[i].profit;
    }

    job_Sequencing(a,n);

return 0;
}
