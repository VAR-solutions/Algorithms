#include<bits/stdc++.h>
using namespace std;

struct process
{
    string name;
    int atime,btime,ctime,tatime,wtime;
};

int main()
{
    int n,t,cnt=0;
    cin>>n;
    process arr[n],now;
    queue <process> rq;
    for(int i=0;i<n;i++)
        cin>>arr[i].name>>arr[i].atime>>arr[i].btime;

    int context,quant,ptr=0;
    cin>>context>>quant;

    for(t=0;t>=0;t++)
    {
        for(int i=ptr;i<n;i++)
        {
            if(arr[i].atime<=t)
            {
                rq.push(arr[i]);
                ptr++;
            }
        }
        if(ptr>0)
            break;
    }

    for(t=t;t>=0;)
    {
        now=rq.front();
        cout<<now.name;
        rq.pop();

        if(now.btime>quant)
        {
            now.btime-=quant;
            t+=quant;
            for(int i=ptr;i<n;i++)
            {
                if(arr[i].atime<=t)
                {
                    rq.push(arr[i]);
                    ptr++;
                }
            }
            rq.push(now);
        }
        else if(now.btime==quant)
        {
            now.btime=0;
            t+=quant;
            for(int i=ptr;i<n;i++)
            {
                if(arr[i].atime<=t)
                {
                    rq.push(arr[i]);
                    ptr++;
                }
            }
            for(int i=0;i<n;i++)
            {
                if(now.name==arr[i].name)
                {
                    arr[i].ctime=t;
                    arr[i].tatime=arr[i].ctime-arr[i].atime;
                    arr[i].wtime=arr[i].tatime-arr[i].btime;
                }
            }
        }
        else if(now.btime<quant)
        {
            t+=now.btime;
            now.btime=0;
            for(int i=ptr;i<n;i++)
            {
                if(arr[i].atime<=t)
                {
                    rq.push(arr[i]);
                    ptr++;
                }
            }
            for(int i=0;i<n;i++)
            {
                if(now.name==arr[i].name)
                {
                    arr[i].ctime=t;
                    arr[i].tatime=arr[i].ctime-arr[i].atime;
                    arr[i].wtime=arr[i].tatime-arr[i].btime;
                }
            }

        }
        if(rq.size()==0)
            break;
    }
    cout<<endl;
    for(int i=0;i<n;i++)
        cout<<arr[i].name<<"\t"<<arr[i].atime<<"\t"<<arr[i].btime<<"\t"<<arr[i].ctime<<"\t"<<arr[i].tatime<<"\t"<<arr[i].wtime<<endl;
}
