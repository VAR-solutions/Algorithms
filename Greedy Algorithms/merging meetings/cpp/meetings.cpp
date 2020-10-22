//problem
//Your company built an in-house calendar tool called HiCal. You want to add a feature to see the times in a day when everyone is available.
//To do this, you’ll need to know when any team is having a meeting. In HiCal, a meeting is stored as an instance of a Meeting class with integer member variables startTime and endTime. These integers represent the number of 30-minute blocks past 9:00am.

//solution
//as we need to get common free time of all employes, we need to merge given meeting timesand find-
//free slots between them
//step1: get sorted your list w.r.t. starting time.
//step2: compare their ending times.
//step3: merge meetings in place and get final list. 
#include<iostream>
#include<bits/stdc++.h>
#define pb push_back
#define INF 1e9
#define ll long long
using namespace std;

class Meeting         					//meeting obects will be elements of list
{
private:
    // number of 30 min blocks past 9:00 am
    unsigned int startTime_;
    unsigned int endTime_;

public:
    Meeting() :
        startTime_(0),
        endTime_(0)
    {
    }

    Meeting(unsigned int startTime, unsigned int endTime) :
        startTime_(startTime),
        endTime_(endTime)
    {
    }

    unsigned int getStartTime() const
    {
        return startTime_;
    }

    void setStartTime(unsigned int startTime)
    {
        startTime_ = startTime;
    }

    unsigned int getEndTime() const
    {
        return endTime_;
    }

    void setEndTime(unsigned int endTime)
    {
        endTime_ = endTime;
    }

    bool operator==(const Meeting& other) const
    {
        return
            startTime_ == other.startTime_
            && endTime_ == other.endTime_;
    }
};

bool comp_by_start(Meeting &meeting1, Meeting &meeting2)  		// used for sorting with starting time
{
	return meeting1.getStartTime()<meeting2.getStartTime();
}
void merge_meetings(vector<Meeting> &v)
{
	sort(v.begin(), v.end(), comp_by_start); // sorted meetings w.r.t. starting time
	for(int i=0; i<v.size()-1; i++)
	{
		if(v[i].getEndTime()<v[i+1].getStartTime())
		{
			continue;
		}
		else if(v[i].getEndTime()>=v[i+1].getEndTime())
		{
			v.erase(v.begin()+1+i);
			i--;
		}
		else{
			v[i].setEndTime(v[i+1].getEndTime());
			v.erase(v.begin()+1+i);
			i--;
		}
	}
}

int main()
{
	int t;  //test cases
	cin>>t;
	while(t--)
	{
		unsigned int n, temp1, temp2;
		cout<<"enter no. of meetings";
		cin>>n;
		vector<Meeting> v(n);
		for(int i=0; i<n; i++)
		{
			cout<<"enter meeting start and end times\n";
			cin>>temp1;
			cin>>temp2;
			Meeting meet(temp1,temp2);
			v.pb(meet);
		}
		merge_meetings(v);
		cout<<"starttime	emdtime\n";
		for(int i=0; i<v.size(); i++){
			cout<<v[i].getStartTime()<<"		"<<v[i].getEndTime()<<endl;
		}
	}
	return 0;
}
