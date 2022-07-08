#include<bits/stdc++.h>
using namespace std;

struct job{
    int jno,ctime,jsize,alloc,mno,start,remain,msize;};

struct memory{
    int mno,msize,ptr,alloc;};

memory mem[1000];
job jobs[1000];
int n,m;
queue <job> ready_queue,job_queue;

void scan(int t)
{
    while(!job_queue.empty())
    {
        for(int i=0;i<n;i++)       // allocating jobs to first available memory
        {
            for(int j=0;j<m;j++)
            {
                if(mem[j].alloc==0&&mem[j].msize>=jobs[i].jsize)
                {
                    mem[j].alloc=jobs[i].alloc=1;
                    jobs[i].remain=mem[j].msize-jobs[i].jsize;
                    jobs[i].mno=mem[j].mno;
                    jobs[i].start=t;
                    ready_queue.push(jobs[i]);
                    break;
                }
            }
        }
        t++;
        for(int i=0;i<n;i++)     //if its time is over removing from memory
        {
            for(int j=0;j<m;j++)
            {
                if(mem[j].alloc==1)
                {
                    if(t-jobs[i].start==jobs[i].ctime)   //checking if job is completed
                    {                                     // if completed then clearing it from memory
                        int memory_no=jobs[i].mno;
                        mem[memory_no].alloc=0;
                    }
                }
            }
        }
    }

}

int main()
{
    cout<<"Enter no of jobs\n";
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>jobs[i].jno>>jobs[i].ctime>>jobs[i].jsize;
        jobs[i].alloc=0;
        job_queue.push(jobs[i]);
    }
    cout<<"Enter no of blocks of memory\n";
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>mem[i].mno>>mem[i].msize;
        mem[i].alloc=0;
    }
    int t=0;

    //if CPU time is not considered
    queue <int> rq;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(mem[j].alloc==0&&mem[j].msize>=jobs[i].jsize)   //if memory is empty and size greater than job
            {
                mem[j].alloc=jobs[i].alloc=1;                   //job allocated
                jobs[i].remain=mem[j].msize-jobs[i].jsize;      //internal fragmentation
                jobs[i].mno=mem[j].mno;                             //assigning memory block no
                rq.push(i);                                      // push in ready queue
                jobs[i].msize=mem[i].msize;
                break;
            }
        }
    }
    cout<<"Ready Queue\n";
    while(!rq.empty())
    {
        cout<<rq.front()<<" ";
        rq.pop();
    }
    cout<<"\nJob No     Block No     Block Size    Job Size    Int Fragment \n";
    for(int i=0;i<n;i++)
    {
        cout<<jobs[i].jno<<"\t\t";
        if(jobs[i].alloc==1)
        cout<<jobs[i].mno<<"\t\t"<<jobs[i].msize<<"\t\t"<<jobs[i].jsize<<"\t\t"<<jobs[i].remain<<"\n";
        else
        cout<<"NOT ALLOCATED\n";
    }

}
/*
1
9500
2
7000
3
4500
4
8500
5
3000
6
9000
7
1000
8
5500
9
1500
10
500
*/
