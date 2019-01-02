#include<iostream>
using namespace std;
void swap(int *x, int *y) 
{ 
    int temp = *x; 
    *x = *y; 
    *y = temp; 
}

int main()
{
        int N, k, max;
        cout << "Enter the Size Of the Arrray: ";
        cin >> N;
        int Arr[N];
        cout << "\nEnter The Elements One by One: \n";
        for(int i = 0; i < N; i++)
        {
                cin >> Arr[i];
        }
        cout << "\nEnter the value of k for which kth largest element is to be found: ";
        cin >> k;
        max = Arr[0];
        if (k <= N)
        {       
        for (int j = 0; j < k; j++)
        {
                for (int l = 1; l < N; l++)
                {
                        if (max < Arr[l])
                        {
                                max = Arr[l];
                        }
                }
                swap(max, Arr[j]);
        }
        }
        else 
        {
                cout << "\n\nInvalid Value of K";
        }
        cout << "\n\nThe kth largest element is: " << Arr[k-1];
        return 0;
}
