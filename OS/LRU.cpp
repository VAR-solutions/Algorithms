#include<bits/stdc++.h>
using namespace std;

int page_replacement=0;

int pageFaults(int pages[], int n, int frames)
{
    set <int> s;
    map <int, int> indexes;

    int page_faults = 0;
    for (int i=0;i<n;i++)
    {
        if (s.size()<frames)
        {
            if (s.find(pages[i])==s.end())
            {
                s.insert(pages[i]);
                page_faults++;
                cout<<"Page fault for page no "<<pages[i]<<"\n\n";
            }
            indexes[pages[i]] = i;
        }
        else
        {
            if (s.find(pages[i]) == s.end())
            {
                int lru = INT_MAX, val;
                set <int> :: iterator it;
                for (it=s.begin(); it!=s.end(); it++)
                {
                    if (indexes[*it]<lru)
                    {
                        lru = indexes[*it];
                        val = *it;
                    }
                }
                s.erase(val);
                s.insert(pages[i]);
                page_faults++;
                page_replacement++;
                cout<<"Page fault for page no "<<pages[i]<<"\n";
                cout<<"Page replacement for page no "<<pages[i]<<"\n\n";
            }
            indexes[pages[i]] = i;
        }
    }
    return page_faults;
}

int main()
{
	int req,psize,msize,val;
	cout<<"Enter memory size and page size\n";
	cin>>msize>>psize;
	cout<<"Enter no of requests\n";
	cin>>req;
    int pages[req];
    for(int i=0;i<req;i++)
    {
        cin>>val;
        pages[i]=val/psize;
    }

    cout<<"\nPage requests are \n";
    for(int i=0;i<req;i++)
        cout<<pages[i]<<" ";
    cout<<endl<<endl;

	int frames = msize/psize;
	int pf=pageFaults(pages, req, frames);
	int hits=req-pf;
	float rat=1.0*hits/req;

	cout <<"\n\nTotal page faults are "<<pf;
	cout<<"\nTotal page replacement are "<<page_replacement;
	cout<<"\nTotal hits are "<<hits;
	cout<<"\nHit Ratio "<<rat;
	return 0;
}
