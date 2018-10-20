/*Program for merge sort implementation in C++. */

#include <iostream>
#include <vector>

void mergeHalves(std::vector<int> &A, int leftStart, int mid, int rightEnd)
{
        int n1=mid-leftStart+1, n2=rightEnd-mid;
        std::vector<int> left, right;
        for (int i = 0; i < n1; i++)
	{
            left.push_back(A[leftStart+i]);
        }
        for (int i = 0; i < n2; i++)
	{
            right.push_back(A[mid+1+i]);
        }

        int i=0, k=leftStart, j=0;

        while (i < n1 && j <n2)
        {
                if(left[i] <= right[j])
                	A[k++] = left[i++];

                else
                	A[k++] = right[j++];
        }

        while(i <n1)
        {
                A[k++] = left[i++];
        }
        while(j <n2)
        {
                A[k++]  = right[j++];
        }

}

void merge_sort(std::vector<int> &A, int leftStart, int rightEnd)

{/*
        std::cout<<"Current list : \n";
        for(int i=0;i<A.size();i++)
        {
                std::cout<<A[i]<<" ";
        }
*/
        if(leftStart>=rightEnd)
                return;

        int mid = (leftStart+rightEnd)/2;
        merge_sort(A,leftStart,mid);
        merge_sort(A,mid+1,rightEnd);

        mergeHalves(A, leftStart, mid, rightEnd);
/*
        std::cout<<"\nSorted list : \n";
        for(int i=0;i<A.size();i++)
        {
                std::cout<<A[i]<<" ";
        }
        return; */
}

int main()
{
        std::cout<<"\nTest\n";
        std::vector<int> arr={10,2,23,-4,235,56,2,6,5,81,5,23,-4,346,-56,-54};

        merge_sort(arr,0,arr.size()-1);
        std::cout<<"\n\n\n";

        for(int i=0;i<arr.size();i++)
        {
                std::cout<<arr[i]<<" ";
        }
        return 0;
}
