#include <bits/stdc++.h>
using namespace std;
 
/*Prototype for utility functions */
void printArray(int arr[], int size); 
void swap(int arr[], int fi, int si, int d); 
 
void leftRotate(int arr[], int d, int n) 
{ 
    /* Return If number of elements to be rotated  
    is zero or equal to array size */
    if(d == 0 || d == n) 
        return; 
         
    /*If number of elements to be rotated 
    is exactly half of array size */
    if(n - d == d) 
    { 
        swap(arr, 0, n - d, d); 
        return; 
    } 
         
    /* If A is shorter*/       
    if(d < n - d) 
    { 
        swap(arr, 0, n - d, d); 
        leftRotate(arr, d, n - d);     
    } 
    else /* If B is shorter*/       
    { 
        swap(arr, 0, d, n - d); 
        leftRotate(arr + n - d, 2 * d - n, d); /*This is tricky*/
    } 
} 
 
/*UTILITY FUNCTIONS*/
/* function to print an array */
void printArray(int arr[], int size) 
{ 
    int i; 
    for(i = 0; i < size; i++) 
        cout << arr[i] << " "; 
    cout << endl; 
} 
 
/*This function swaps d elements starting at index fi 
with d elements starting at index si */
void swap(int arr[], int fi, int si, int d) 
{ 
    int i, temp; 
    for(i = 0; i < d; i++) 
    { 
        temp = arr[fi + i]; 
        arr[fi + i] = arr[si + i]; 
        arr[si + i] = temp; 
    } 
} 
 
// Driver Code
int main() 
{ 
    int arr[] = {1, 2, 3, 4, 5, 6, 7}; 
    leftRotate(arr, 2, 7); 
    printArray(arr, 7); 
    return 0; 
} 
 
