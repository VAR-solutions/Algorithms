#include<iostream.h>
#include<conio.h>
void main()
{
	clrscr();
	int size, arr[50], i, j, temp,pos;
	cout<<"Enter Array Size : ";
	cin>>size;
	cout<<"Enter Array Elements : ";
	for(i = 0; i < size; i++)
	{
		cin>>arr[i];
	}
	cout<<"Sorting array using selection sort...\n";
    	for(i = 0; i < size; i++)
    	{
        	pos = i;
        	for(j = i + 1 ; j < size  ; j++)
        	{
            	if(arr[j] < arr[pos])
                	pos = j;
        	}
        	temp = arr[i];
        	arr[i] = arr[pos];
        	arr[pos] = temp;
    	}
	cout<<"Now the Array after sorting is :\n";
	for(i = 0; i < size; i++)
	{
		cout<<arr[i]<<" ";
	}
	getch();
}
