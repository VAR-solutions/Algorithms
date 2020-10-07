#include<bits/stdc++.h>
using namespace std;

struct disk{
    int track,sector;
    int done;
    int dist;
    float seek_time;
    int r_latency;
    float delay;
    float total_delay;
};

int n;
disk request[100];

void fcfs(int track,int sector)
{
    for(int i=0;i<n;i++)
    {
        request[i].seek_time=10+0.1*abs(track-request[i].track);
        request[i].r_latency=(request[i].sector-sector+8)%8;
        request[i].delay=1+request[i].seek_time+request[i].r_latency;
        track=request[i].track;
        sector=request[i].sector;
    }

    request[0].total_delay=request[0].delay;

    for(int i=1;i<n;i++)
        request[i].total_delay=request[i-1].total_delay+request[i].delay;

    cout<<"Seek Sequence is \n";
    for(int i=0;i<n;i++)
        cout<<request[i].track<<" ";
    cout<<"\n\n";
}

void sstf(int track,int sector)
{
    vector <int> execution;  //total 8 sectors from 0 to 7 and full rotation takes 8ms
    float sum=0;             //seek=10+0.1*T
    for(int j=0;j<n;j++)
    {
        int index=0,mindist=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(request[i].done==0)
            {
                request[i].dist=abs(track-request[i].track);
                if(request[i].dist<mindist)
                {
                    mindist=request[i].dist;
                    index=i;
                }
            }
        }
        request[index].seek_time=10+0.1*abs(track-request[index].track);
        request[index].r_latency=(request[index].sector-sector+8)%8;
        request[index].delay=1+request[index].seek_time+request[index].r_latency;
        request[index].total_delay=sum+request[index].delay;
        sum+=request[index].delay;
        track=request[index].track;
        sector=request[index].sector;
        request[index].done=1;
        execution.push_back(request[index].track);
    }

    cout<<"Sequence is \n";
    for(int i=0;i<execution.size();i++)
        cout<<execution[i]<<" ";
    cout<<"\n\n";
}


int main()
{
    cout<<"Enter no of requests \n";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>request[i].track>>request[i].sector;
        request[i].done=0;
    }

    int start_track=50,start_sector=0;

    int choice;
    cout<<"Enter 1 for fcfs and 2 for sstf\n";
    cin>>choice;

    if(choice==1)
        {
            cout<<"FCFS Disk Scheduling\n\n";
            fcfs(start_track,start_sector);
        }
    else
        {
            cout<<"SSTF Disk Scheduling\n\n";
            sstf(start_track,start_sector);
        }


    cout<<"Track \t    Sector \t  Seek Time(ms)   Rotational L.(ms)    Transfer T(ms) \t    Delay(ms)  \t   Net Delay(ms)\n";
    for(int i=0;i<n;i++)
    {
        cout<<request[i].track<<"\t\t"<<request[i].sector<<"\t\t"<<request[i].seek_time<<"\t\t"<<request[i].r_latency;
        cout<<"\t\t    1   \t\t"<<request[i].delay<<"\t\t"<<request[i].total_delay<<"\n";
        cout<<"\n";
    }
}
/*
10
45 0
132 6
20 2
23 1
198 7
170 5
180 3
78 4
73 5
150 7
*/
