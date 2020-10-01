#include <bits/stdc++.h>
using namespace std;

//table size = 13 (Usually Odd prime number)
int hashtable[13];
int hashValue(int N)
{
	return N%13;
}

//inserts the number in the table.
void insert(int N)
{
	int h=hashValue(N);
	int iterations=0;
	while(hashtable[h]!=0 && hashtable[h]!=-1)
	{
		iterations++;
		h=(h+1)%13;
		if(iterations==14)
		{
			cout<<"No empty space"<<endl;
			return;
		}
	}
	cout<<N<<" inserted at "<<h<<endl;
	hashtable[h]=N;
}

//search for the number N in the table. Return -1 if the number is not found.
int search(int N)
{
	int h=hashValue(N);
	while(hashtable[h]!=0 && hashtable[h]!=N)
		h=(h+1)%N;
	if(hashtable[h]==0)
		return -1;
	else
		return h;
}

//deletes a number from the table.
void delete_key(int N)
{
	int h=hashValue(N);
	while(hashtable[h]!=0 && hashtable[h]!=N)
		h=(h+1)%N;
	if(hashtable[h]!=0)
	{
		cout<<"Position deleted: "<<h<<endl;
		hashtable[h]=-1;
	}
	else
		cout<<"Key Not Found"<<endl;
}

int main()
{
	//inserting some numbers in the table
	for(int i=27;i<120;)
	{
		if(i<30)
			i+=2;
		else if(i<40)
			i+=3;
		else if(i<60)
			i+=7;
		else
			i+=10;

		insert(i);
	}

	//searching for numbers
	for(int i=27;i<120;)
	{
		if(i<30)
			i+=2;
		else if(i<40)
			i+=3;
		else if(i<60)
			i+=7;
		else
			i+=10;
		cout<<search(i)<<endl;
	}

	delete_key(27);
	delete_key(30);
	delete_key(40);
	delete_key(43);
	delete_key(47);

	delete_key(53);
	delete_key(65);
	delete_key(74);

	//searching for numbers post deletion.
	for(int i=27;i<120;)
	{
		if(i<30)
			i+=2;
		else if(i<40)
			i+=3;
		else if(i<60)
			i+=7;
		else
			i+=10;
		cout<<search(i)<<endl;
	}
}
