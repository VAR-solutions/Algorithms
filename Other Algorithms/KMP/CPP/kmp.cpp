/*Problem Statement:-
	Given a text(t) and a string(s) you need to find the number of occurrences
	of the string in the text
Solution(KMP(Knuth–Morris–Pratt) algorithm):-
	The main idea is to use the prefix function array denoted by pi
	in the kmp algorithm on the string s+'#'+t
Time Complexity:-
	O(n+m) where n is the lenght of the text and m is the length of the string
*/

#include<iostream>
#include<vector>

using namespace std;

int main()
{
	cout<<"\nEnter a text to be seached for the string : ";
	string t;
	getline(cin,t);
	cout<<"\nEnter a string : ";
	string s;
	getline(cin,s);
	string buff=s+'#'+t;
	int n=buff.size();

	vector<int> pi(n);
	for(int i=1;i<n;i++)				//calculating the prefix function array
	{
		int j=pi[i-1];
		while(j>0&&buff[j]!=buff[i])
			j=pi[j-1];
		if(buff[j]==buff[i])			//else the j will be zero
			j++;
		pi[i]=j;
	}

	vector<int> ans;
	for(int i=s.size();i<n;i++)
		if(pi[i]==s.size())
			ans.push_back(i);
	
	cout<<"\nNumber of occurrences of the string in the text are : "<<ans.size()<<endl;
	
	if(ans.size())
	{
		cout<<"\nString found at the positions : ";
		for(auto x:ans)
			cout<<x-2*s.size()<<" ";
	}
	cout<<endl;

return 0;
}
