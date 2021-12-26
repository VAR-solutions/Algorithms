#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

struct Phone
{
	long long number;
	string name;
	Phone(long long num, string n) //constructor
	{
		number = num;
		name = n;
	}
};
Phone Phonebook[10000000];

void add(long long num , string name)
{
Phonebook[num] = Phone(num,name);
}

void del(long long num)
{
Phonebook[num]=Phone(0,"");
}

void find(long long num)
{
if(Phonebook[num].number != 0 )
{
cout<<Phonebook[num].name;
}
else
{
cout<<"not found";
}
}


int main()
{
int n;
cin>>n;
while(n--)
{
 string inp;
 cin>>inp;
 if(inp == "add")
 	 {
	   int num; string name;
	   add(num,name);
 	 }
 else if(inp == "del")
 	 {
	   int num;
	   del(num);
 	 }
 else if(inp == "find")
 	 {
	   int num;
	   find(num);
 	 }
}
return 0;
}
