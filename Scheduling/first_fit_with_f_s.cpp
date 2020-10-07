#include<bits/stdc++.h>
using namespace std;

struct job{
    int jno,jsize,mno,ctime,comp;
    pair <int,int> alloc;
    };

struct memory{
    int mno,msize;
    vector <pair <int,int> > frag;
    };

memory mem[1000];
job jobs[1000];
int n,m;
vector <int> ready_queue,job_queue;
queue <int> done_job;

void fcfs()
{
    if(ready_queue.size()>0)
    {
        int now=ready_queue[0];
        ready_queue.erase(ready_queue.begin());
        cout<<"Job No "<<now<<" is completed. \n\n";

        mem[jobs[now].mno].frag.push_back(jobs[now].alloc);
        sort(mem[jobs[now].mno].frag.begin(),mem[jobs[now].mno].frag.end());
        for(int l=0;l<mem[jobs[now].mno].frag.size()-1;l++)
        {
            pair <int,int> p1,p2;
            p1=mem[jobs[now].mno].frag[l];
            p2=mem[jobs[now].mno].frag[l+1];
            if(p1.second==p2.first-1)
            {
                mem[jobs[now].mno].frag.erase(mem[jobs[now].mno].frag.begin());
                mem[jobs[now].mno].frag.erase(mem[jobs[now].mno].frag.begin());
                mem[jobs[now].mno].frag.push_back(make_pair(p1.first,p2.second));
                l=0;
            }
            sort(mem[jobs[now].mno].frag.begin(),mem[jobs[now].mno].frag.end());
        }
        if(mem[jobs[now].mno].frag.size()==2)
        {
            pair <int,int> p1,p2;

            p1=mem[jobs[now].mno].frag[0];
            p2=mem[jobs[now].mno].frag[1];
            if(p1.second==p2.first-1)
            {
                mem[jobs[now].mno].frag.erase(mem[jobs[now].mno].frag.begin());
                mem[jobs[now].mno].frag.erase(mem[jobs[now].mno].frag.begin());
                mem[jobs[now].mno].frag.push_back(make_pair(p1.first,p2.second));
            }

        }
        done_job.push(now);
    }
    else
    cout<<"Ready queue is empty\n";

}
void sjf()
{
    if(ready_queue.size()>0)
    {
        int time=INT_MAX,now;
        for(int i=0;i<ready_queue.size();i++)
        {
            if(jobs[ready_queue[i]].ctime<time)
            {
                time=jobs[ready_queue[i]].ctime;
                now=ready_queue[i];
            }
        }
        cout<<"Job No "<<now<<" is completed\n";
        ready_queue.erase(std::find(ready_queue.begin(),ready_queue.end(),now));
        mem[jobs[now].mno].frag.push_back(jobs[now].alloc);

        sort(mem[jobs[now].mno].frag.begin(),mem[jobs[now].mno].frag.end());
        for(int l=0;l<mem[jobs[now].mno].frag.size()-1;l++)
        {
            pair <int,int> p1,p2;
            p1=mem[jobs[now].mno].frag[l];
            p2=mem[jobs[now].mno].frag[l+1];
            if(p1.second==p2.first-1)
            {
                mem[jobs[now].mno].frag.erase(mem[jobs[now].mno].frag.begin());
                mem[jobs[now].mno].frag.erase(mem[jobs[now].mno].frag.begin());
                mem[jobs[now].mno].frag.push_back(make_pair(p1.first,p2.second));
                l=0;
            }
            sort(mem[jobs[now].mno].frag.begin(),mem[jobs[now].mno].frag.end());
        }
        if(mem[jobs[now].mno].frag.size()==2)
        {
            pair <int,int> p1,p2;

            p1=mem[jobs[now].mno].frag[0];
            p2=mem[jobs[now].mno].frag[1];
            if(p1.second==p2.first-1)
            {
                mem[jobs[now].mno].frag.erase(mem[jobs[now].mno].frag.begin());
                mem[jobs[now].mno].frag.erase(mem[jobs[now].mno].frag.begin());
                mem[jobs[now].mno].frag.push_back(make_pair(p1.first,p2.second));
            }

        }
        done_job.push(now);
    }
    else
        cout<<"Ready queue is empty\n";

}

int main()
{
    cout<<"Enter no of jobs\n";
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>jobs[i].jno>>jobs[i].ctime>>jobs[i].jsize;
        jobs[i].mno=0;
        jobs[i].comp=0;
    }


    cout<<"Enter no of blocks of memory\n";
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>mem[i].mno>>mem[i].msize;
        mem[i].frag.push_back(make_pair(1,mem[i].msize));
    }

    int choice;
    cout<<"Enter 1 for fcfs and 2 for sjf\n";
    cin>>choice;

    cout<<"JOB List\n";
    cout<<"Job No   CPU Time   Size\n";
    for(int i=1;i<=n;i++)
        cout<<jobs[i].jno<<" \t"<<jobs[i].ctime<<" \t"<<jobs[i].jsize<<"\n";


    cout<<"Memory Block\n";
    cout<<"Memory No   Memory Size\n";
    for(int i=1;i<=m;i++)
        cout<<mem[i].mno<<"\t"<<mem[i].msize<<"\n";

    cout<<"\nScheduler is ";
    if(choice==1)
        cout<<"fcfs\n\n";
    else
        cout<<"sjf\n\n";


    int t=0,cnt=0,ptr=0;
    pair <int,int> p;
    while(cnt<n){
    job_queue.clear();
    for(int i=1;i<=n;i++)
    {
        int j,k;
        if(jobs[i].mno==0)
        {
            for(j=1;j<=m;j++)
            {
                ptr=0;
                for( k=0;k!=mem[j].frag.size();k++)
                {
                    p=mem[j].frag[k];
                    if(p.second-p.first+1>=jobs[i].jsize)
                    {
                        mem[j].frag.push_back(make_pair(p.first+jobs[i].jsize,p.second));
                        mem[j].frag.erase(std::find(mem[j].frag.begin(),mem[j].frag.end(),p));
                        jobs[i].alloc = make_pair(p.first , p.first-1+jobs[i].jsize);
                        jobs[i].mno=mem[j].mno;
                        ready_queue.push_back(jobs[i].jno);
                        cout<<"Job No "<<jobs[i].jno<<" allocated memory no "<<jobs[i].mno<<" at "<<p.first<<" "<<p.first+jobs[i].jsize-1<<"\n";
                        ptr=1;
                        break;
                    }
                }
                if(ptr==1)
                break;
            }
            if(j==m+1)
            job_queue.push_back(i);
        }
    }
    cnt++;
    if(choice==1)
    fcfs();
    else
    sjf();
    }

    cout<<"Execution Order\n";
    while(!done_job.empty())
    {
        cout<<done_job.front()<<" ";
        done_job.pop();
    }
    cout<<"\n\nJob Queue\n";
    for(int i=0;i<job_queue.size();i++)
        cout<<job_queue[i]<<" ";
    cout<<"\n\nJob No     Memory Block No     Job Size       CPU Time \n";
    for(int i=1;i<=n;i++)
    {
        cout<<jobs[i].jno<<"\t\t";
        if(jobs[i].mno!=0)
        cout<<jobs[i].mno<<"\t\t"<<jobs[i].jsize<<"\t\t"<<jobs[i].ctime<<"\n";
        else
        cout<<"NOT ALLOCATED\n";
    }
}
