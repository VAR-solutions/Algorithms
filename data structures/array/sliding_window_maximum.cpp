#include<bits/stdc++.h>
using namespace std;

//finds the maximum element in the array for every window of size k
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size(),i=0;
    vector<int> res;
    if(n == 0)
        return res;
    deque<int> dq;
    for(;i<k;i++){
        while(!dq.empty() && nums[i] >= nums[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }
    for(;i<n;i++){
        res.push_back(nums[dq.front()]);
        while(!dq.empty() && dq.front() + k <= i)
            dq.pop_front();
        while(!dq.empty() && nums[i] >= nums[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }
    res.push_back(nums[dq.front()]);
    return res;
}

int main(){
	int n;
	cin>>n;
	vector<int> nums(n);
	for(int i = 0;i<n;i++)
		cin>>nums[i];

	//window size
	int k;
	cin>>k;

	vector<int> res = maxSlidingWindow(nums,k);
	for(auto n : res)
		cout<<n<<" ";
}
