//no of occurrences of pattern(substring) in a string
//Using Z-algo 
//Preprocess: O(n), Search-Time O(n+m)
//For tutorial refer to the link: https://www.geeksforgeeks.org/z-algorithm-linear-time-pattern-searching-algorithm/

#include<bits/stdc++.h>
#define endl "\n"
#define ll long long int
#define N (ll)(1e9+7)
#define T int
#define P pair<T,T>
#define umap unordered_map<T,T>
#define uset unordered_set<T>
#define rep(i,n) for(i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define print(v) for(auto x:v) cout<<x<< " "
#define pb push_back
using namespace std;

//generates the z-array for any given string
//Runtime: O(n), n=length of the string
//z-array: This is an array of length n (i.e. same length as the string)
//z[i]=longest common prefix of {s and suffix of s starting at index i}.

vector<int> z_function(string &s)
{
	int n=s.length();
	vector<int> z(n,0);
	int i,l,r;
	for(i=1,l=0,r=0;i<n;i++)
	{
		if(i<=r)
		{
			z[i]=min(z[i-l],r-i+1);
		}
		while(i+z[i]<n && s[i+z[i]]==s[z[i]])
			++z[i];
        if(i+z[i]-1>r)
        {
            l=i;
            r=i+z[i]-1;
        }
	}
	return z;
}

//counts the number of occurrences of pattern p as a substring in string s  
//Runtime: O(m+n), m=pattern length, n=string length

int countOccurrences(const string &p,const string &s)
{
    string conc=p+"$"+s;

    vector<int> z=z_function(conc);
    int i;
    int m=p.length();
    int n=s.length();
    int ans=0;
    for(i=0;i<n;i++)
    {
        if(z[i+m+1]==m)
            ++ans;
    }
    return ans;
}

//driver program

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string p,s;
    cin>>p>>s;

    int ans=countOccurrences(p,s);
    cout<<ans<<endl;


    return 0;
}

