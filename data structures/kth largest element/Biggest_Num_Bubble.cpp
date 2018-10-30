// getting kth largest number in an array of numbers.
// the complexity is O(N^2)

#include <iostream>
using namespace std;
void BubbleSort(int a[], int n){
        int z,j,temp,flag; //temp will be used for swapping two consecutive numbers
        for (z = 1; z <n; z++){
            flag = 0;
            for (j = 0 ; j < n-z ;j++){
                if (a[j] > a[j+1]){
                    temp = a[j];
                    a[j]=a[j+1];
                    a[j+1]= temp;
                    flag = 1;
                }
            }
            if (flag==0) //checks if sorted
            break;
        }
    }

int main(){
    int k;
    cout << "please enter the largest element order: ";
    cin >> k;
    int n;
    cout << "Please enter the number of array elements: ";
    cin >> n;
    cout <<"Please enter the array elements one number in a line: \n";
    int* a = new int[n]; // this is the line that allocates dynamically a place in memory with size n when the user enters n
    for(int i=0;i<n;i++){
        cin >> a[i]; //u can enter numbers separated by spaces or one number in each line
    }
    cout << "The sorted list is: \n";
    BubbleSort(a, n);
    for (int i=0;i<n; i++){
            cout <<  a[i] << endl;
    }
    cout << "The largest required number is " << a[n-k]<<"."<< endl;
    return 0;
}
