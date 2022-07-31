#include<iostream>
using namespace std;
int pos(int arr[] , int size , int tofind)
{
	
	for(int i=0;i<size;i++)
		if (arr[i] == tofind) return i;
	return -1;
}
void main()
{
	const int size = 5;
	int arr[] = {1,2,3,4,5};
	int p = pos(arr, size, 2);
	if (p == -1)
		cout <<"Not found\n";
	else cout << " Position of element is: "<<p+1<<endl;

}
