/*
	Author: Utkarsh
	Institute: IIIT-Guwahati, India
	e-mail: utk.akt@gmail.com
*/

#include <bits/stdc++.h>

using namespace std;

int max(int a, int b)
{
	return (a > b) ? a : b;
}

int max(int a, int b, int c)
{
	return max(max(a, b), c);
}

int maxCrossingSum(int arr[], int l, int m, int h)
{
	//LEFT of Mid
	int sum = 0;
	int left_sum = INT_MIN, max_left;
	for (int i = m; i >= l; i--)
	{
		sum = sum + arr[i];
		if (sum > left_sum)
		{
			left_sum = sum;
			max_left = i;
		}
	}

	//RIGHT of mid
	sum = 0;
	int right_sum = INT_MIN, max_right;
	for (int i = m + 1; i <= h; i++)
	{
		sum = sum + arr[i];
		if (sum > right_sum)
		{
			right_sum = sum;
			max_right = i;
		}
	}

	return max(left_sum + right_sum, left_sum, right_sum);
}

int maxSubArraySum(int *arr, int lo, int hi)
{
	if (lo == hi)
	{
		return arr[lo];
	}
	else
	{
		int mid = lo + (hi - lo) / 2;
		return max(maxSubArraySum(arr, lo, mid), maxSubArraySum(arr, mid + 1, hi), maxCrossingSum(arr, lo, mid, hi));
	}
}

int main()
{
	unsigned n;
	cout << "Enter length of Array: " << endl;
	cin >> n;

	int *arr = (int *)calloc(n, sizeof(int));
	cout << "Enter the elements of the Array" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	cout << "The Maximum Contiguous Sum is: " << maxSubArraySum(arr, 0, n - 1) << endl;

	return 0;
}