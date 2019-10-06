<<<<<<< HEAD
//First Comes First Serve(FCFS)

#include<bits/stdc++.h>

using namespace std; 

void Sort_by_arrival_time(int arrival_time[], int burst_time[], int n){
	vector< pair <int, int> > v;

	for (int i = 0; i < n; ++i){
		v.push_back({arrival_time[i], burst_time[i]});
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; ++i)
	{
		arrival_time[i] = v[i].first;
		burst_time[i] = v[i].second;
	}
}

void findWaitingTime(int processes[], int n, int bt[], int wt[]) { 
	 
	wt[0] = 0;  
	for (int i = 1; i < n ; i++ ) 
		wt[i] = bt[i-1] + wt[i-1] ; 
} 

void findTurnAroundTime( int processes[], int n, int bt[], int wt[], int tat[]) { 
	for (int i = 0; i < n ; i++) 
		tat[i] = bt[i] + wt[i]; 
} 

void findavgTime( int processes[], int n, int bt[]) { 
	int wt[n], tat[n], total_wt = 0, total_tat = 0; 

	findWaitingTime(processes, n, bt, wt); 

	findTurnAroundTime(processes, n, bt, wt, tat); 

	cout << "Processes "<< " Burst time "
		<< " Waiting time " << " Turn around time\n";  
	for (int i=0; i<n; i++) 
	{ 
		total_wt = total_wt + wt[i]; 
		total_tat = total_tat + tat[i]; 
		cout << " " << i+1 << "\t\t" << bt[i] <<"\t "
			<< wt[i] <<"\t\t " << tat[i] <<endl; 
	} 

	cout << "Average waiting time = "
		<< (float)total_wt / (float)n; 
	cout << "\nAverage turn around time = "
		<< (float)total_tat / (float)n; 
} 

int main() 
{ 
	//process id's 
	int n;//Enter number of processes
	cin>>n;
	int processes[n],burst_time[n], arrival_time[n];

	for (int i = 0; i < n; ++i){

		cin>>processes[i]>>arrival_time[i]>>burst_time[i];
	}

	cout<<"Processes\t"<<"Arrival Time\t"<<"Burst Time\n";

	for (int i = 0; i < n; ++i){	
		cout<<Processes[i]<<"\t\t"<<arrival_time[i]<<"\t\t"<<burst_time[i]<<endl;
	}

	Sort_by_arrival_time(arrival_time, burst_time, n);

	findavgTime(processes, n, burst_time); 
	return 0; 
} 
=======
//First Comes First Serve(FCFS)

#include<bits/stdc++.h>

using namespace std; 

void Sort_by_arrival_time(int arrival_time[], int burst_time[], int n){
	vector< pair <int, int> > v;

	for (int i = 0; i < n; ++i){
		v.push_back({arrival_time[i], burst_time[i]});
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; ++i)
	{
		arrival_time[i] = v[i].first;
		burst_time[i] = v[i].second;
	}
}

void findWaitingTime(int processes[], int n, int bt[], int wt[]) { 
	 
	wt[0] = 0;  
	for (int i = 1; i < n ; i++ ) 
		wt[i] = bt[i-1] + wt[i-1] ; 
} 

void findTurnAroundTime( int processes[], int n, int bt[], int wt[], int tat[]) { 
	for (int i = 0; i < n ; i++) 
		tat[i] = bt[i] + wt[i]; 
} 

void findavgTime( int processes[], int n, int bt[]) { 
	int wt[n], tat[n], total_wt = 0, total_tat = 0; 

	findWaitingTime(processes, n, bt, wt); 

	findTurnAroundTime(processes, n, bt, wt, tat); 

	cout << "Processes "<< " Burst time "
		<< " Waiting time " << " Turn around time\n";  
	for (int i=0; i<n; i++) 
	{ 
		total_wt = total_wt + wt[i]; 
		total_tat = total_tat + tat[i]; 
		cout << " " << i+1 << "\t\t" << bt[i] <<"\t "
			<< wt[i] <<"\t\t " << tat[i] <<endl; 
	} 

	cout << "Average waiting time = "
		<< (float)total_wt / (float)n; 
	cout << "\nAverage turn around time = "
		<< (float)total_tat / (float)n; 
} 

int main() 
{ 
	//process id's 
	int n;//Enter number of processes
	cin>>n;
	int processes[n],burst_time[n], arrival_time[n];

	for (int i = 0; i < n; ++i){

		cin>>processes[i]>>arrival_time[i]>>burst_time[i];
	}

	cout<<"Processes\t"<<"Arrival Time\t"<<"Burst Time\n";

	for (int i = 0; i < n; ++i){	
		cout<<Processes[i]<<"\t\t"<<arrival_time[i]<<"\t\t"<<burst_time[i]<<endl;
	}

	Sort_by_arrival_time(arrival_time, burst_time, n);

	findavgTime(processes, n, burst_time); 
	return 0; 
} 
>>>>>>> 2db113523ebbfb33ba57baa4f18f9baa62be7c49
