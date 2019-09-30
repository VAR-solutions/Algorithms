/*
	terniary search finds position of an element in a UNIMODAL function or array filled
	* unimodally
	*  https://en.wikipedia.org/wiki/Unimodality
 */
 #include<iostream>
using namespace std;
const int SIZE = 10000005;
int arr[SIZE];
int ternary_search(int l,int r, int x)
{
    if(r>=l)
    {
        int mid1 = l + (r-l)/3;
        int mid2 = r -  (r-l)/3;
        if(arr[mid1] == x)
            return mid1;
        if(arr[mid2] == x)
            return mid2;
        if(x<arr[mid1])
            return ternary_search(l,mid1-1,x);
        else if(x>arr[mid2])
            return ternary_search(mid2+1,r,x);
        else
            return ternary_search(mid1+1,mid2-1,x);

    }
    return -1;
}
int main()
{
	int sz = 100;
	for(int i=0;i<sz;i++)
		arr[i] = i*2;
	int pos = ternary_search(0,sz,10);
	if (pos == -1)
		cout <<"NOT FOUND\n";
	else cout <<"FOUND AT "<<pos+1<<endl;
return 0;
}
