/*Program for quick sort implementation in C++. */

#include <iostream>
#include <vector>

int partition(std::vector<int> &A, int start, int end)
{
	int temp;
	int pivot = A[end];
	int partitionIndex = start; // set partition index as start initially
	for(int i=start; i<end; i++)
	{
		if(A[i] <= pivot)
		{
			swap(&A[i], &A[partitionIndex]);
			partitionIndex++;
		}
	}
	swap(&A[partitionIndex], &A[end]);		//	partition index

	return partitionIndex;
}

void swapElements(int* elementOne, int* elementTwo)
{
	int temp = *elementOne;
	*elementOne = *elementTwo;
	*elementTwo = temp;
}
std::vector<int> quick_sort(std::vector<int> &A, int start, int end)
{
/*        std::cout<<"Current list : \n";
        for(int i=0;i<A.size();i++)
        {
                std::cout<<A[i]<<" ";
        }
        std::cout<<"\nSorted list : \n";
*/
	
	if(start<end)
	{
		int partitionIndex = partition(A,start,end);
		quick_sort(A,start,partitionIndex-1);
		quick_sort(A,partitionIndex+1, end);
	}

/*        for(int i=0;i<A.size();i++)
        {
                std::cout<<A[i]<<" ";
        }
*/        return A;
}

int main()
{
        std::cout<<"\nTest\n";
        std::vector<int> arr={10,2,23,-4,235,56,2,6,5,5,5,23,-4,346,-56,81,43,654,435,-54};
        quick_sort(arr, 0, arr.size()-1);
        std::cout<<"\n\n\n";
        for(int i=0;i<arr.size();i++)
        {
                std::cout<<arr[i]<<" ";
        }
        return 0;
}

