#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
using namespace std;

void jobqueue(queue< pair<int,int> > &job_queue)
{
    job_queue.push(mp(5,5760));
    job_queue.push(mp(4,4190));
    job_queue.push(mp(8,3290));
    job_queue.push(mp(2,2030));
    job_queue.push(mp(2,2550));
    job_queue.push(mp(6,6990));
    job_queue.push(mp(8,8940));
    job_queue.push(mp(10,740));
    job_queue.push(mp(7,3930));
    job_queue.push(mp(6,6890));
    job_queue.push(mp(5,6580));
    job_queue.push(mp(8,3820));
    job_queue.push(mp(9,9140));
    job_queue.push(mp(10,420));
    job_queue.push(mp(10,220));
    job_queue.push(mp(7,7540));
    job_queue.push(mp(3,3210));
    job_queue.push(mp(1,1380));
    job_queue.push(mp(9,9850));
    job_queue.push(mp(3,3610));
    job_queue.push(mp(7,7540));
    job_queue.push(mp(2,2710));
    job_queue.push(mp(8,8390));
    job_queue.push(mp(5,5950));
    job_queue.push(mp(10,760));
}


void memoryalloc(vector<int>&memory)
{
    memory.push_back(9500);
    memory.push_back(7000);
    memory.push_back(4500);
    memory.push_back(8500);
    memory.push_back(3000);
    memory.push_back(9000);
    memory.push_back(1000);
    memory.push_back(5500);
    memory.push_back(1500);
    memory.push_back(500);
}

int scan(vector<int>&memory,int curr_job)
{
    for(int i=0;i<memory.size();i++)
    {
        if(memory[i]>=curr_job)
        {
            memory[i]-=curr_job;
            return i;
        }
    }
    return -1;
}

int main()
{
    queue< pair <int,int> > job_queue;
    queue< pair<int,int> >ready_queue;
    vector < int> memory;
    memoryalloc(memory);
    jobqueue(job_queue);
    int n=job_queue.size();
    int allocated[n];
    map< int,vector <int> >job_alloc;
    memset(allocated,-1,sizeof(allocated));
    int curr=0;
    while(n--)
    {
        pair<int,int> curr_job = job_queue.front();
        job_queue.pop();
        int res = scan(memory,curr_job.second);

        if(res==-1)
        job_queue.push(curr_job);
        else{
        ready_queue.push(curr_job);
        allocated[curr]=res+1;
        job_alloc[res].push_back(curr+1);
        }
        curr++;
    }


    cout<<"==================================="<<endl;
    cout<<"           Job Queue"<<endl;
    cout<<"==================================="<<endl;
    for(int i=0;i<25;i++)
    if(allocated[i]==-1)
    cout<<i+1<<" ";
    cout<<endl;
    cout<<endl;
    cout<<endl;


    cout<<"==================================="<<endl;
    cout<<"           Ready Queue"<<endl;
    cout<<"==================================="<<endl;
    for(int i=0;i<25;i++)
    if(allocated[i]!=-1)
    cout<<i+1<<" ";
    cout<<endl;
    cout<<endl;
    cout<<endl;


    int total_frag=0;
    cout<<"==================================="<<endl;
    cout<<"      Internal Fragmentation"<<endl;
    cout<<"==================================="<<endl;
    cout<<endl;
    for(int i=0;i<memory.size();i++)
    {
        cout<<"MEMORY BLOCK "<<i+1<<"-"<<endl;
        cout<<"Jobs allocated - ";
        for(int j=0;j<job_alloc[i].size();j++)
        {
            cout<<job_alloc[i][j]<<" ";
        }
        cout<<endl;
        cout<<"Internal Fragmentation -> "<<memory[i]<<endl;
        cout<<endl;
        total_frag+=memory[i];
    }
    cout<<endl;
    cout<<endl;

     cout<<"==================================="<<endl;
    cout<<"    Total Internal Fragmentation"<<endl;
    cout<<"==================================="<<endl;
    cout<<"Total internal Fragmentation = "<<total_frag<<endl;
    cout<<endl;

    cout<<"==================================="<<endl;
    cout<<"Memory block allocated to each job"<<endl;
    cout<<"==================================="<<endl;
    for(int i=0;i<25;i++)
    cout<<"JOB "<<i+1<<" -> "<<allocated[i]<<endl;

    return 0;
}
