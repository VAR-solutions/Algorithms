// C++ program for implementation of Heap Sort
#include <iostream>
#define MIN_HEAP 0;
#define MAX_HEAP 1;

using namespace std;

// Choice to choose between Max/Min Heap.
int CHOICE = MAX_HEAP;
//Use MIN_HEAP to use this algorithm as a Min Heap. 

// We defined a comparator function to automatically make comparisions based on our Choice instead of making it generic
bool const comparator(const int l, const int r) {
    if (CHOICE)
        return l > r;
    return l < r;
}

// We use these function calls lchild() and rchild() to get the left child/right child for any node
int lchild(const int i) {
    return 2 * i;
}

int rchild(const int i) {
    return 2 * i + 1;
}

// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = lchild(i); // left = 2*i + 1
    int r = rchild(i); // right = 2*i + 2

    // compare left child & root
    if (l < n && comparator(arr[l], arr[largest]))
        largest = l;

    // compare right child & root
    if (r < n && comparator(arr[r], arr[largest]))
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// main function to do heap sort
void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

/* A utility function to print array of size n */
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

// Driver program
int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);

    cout << "Sorted array is \n";
    printArray(arr, n);
}