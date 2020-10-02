//Used for almost sorted arrays

#include <stdio.h>

void cook_kim_sort(int*, int);

void main()
{
    int i, n;
    printf("COOK-KIM SORT");
    printf("\nEnter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the almost sorted elements one by one: ");
    for(i = 0; i < n; i++)
        scanf("%d", (arr+i));

    cook_kim_sort(arr, n);

    printf("\nArray after sort: ");
    display(arr, n);
    printf("\n");
}

void cook_kim_sort(int arr[], int n)
{
    int temp[n];
    int k = 0;
    for(int i = 0; i < n-1-k; i++)
    {
        if(arr[i] > arr[i+1])
        {
            temp[k] = arr[i+1];
            temp[k+1] = arr[i];
            delete(arr, n-k, i);
            k+=2;
            i-=2;
        }
    }

    if(k < 15)
        insertion_sort(temp, k);
    else
        quick_sort(temp, 0, k-1);

    merge(arr, temp, arr, n-k, k);
}

void merge(int a[], int b[], int c[], int m, int n)
{
    int temp[m+n];
    int i = 0, j = 0, k = 0;

    while((i < m) && (j < n))
    {
        if(a[i] <= b[j])
            temp[k++] = a[i++];
        else
            temp[k++] = b[j++];
    }

    while(i < m)
       temp[k++] = a[i++];

    while(j < n)
       temp[k++] = b[j++];

    //copying temp to array
    for(int i = 0; i < m+n; i++)
        c[i] = temp[i];
}

void display(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

void delete(int arr[], int n, int i)
{
    int j = i+2;
    for(int k = j; k < n; k++)
        arr[k-2] = arr[k];
}

void quick_sort(int a[], int low, int up)
{
    if(low >= up)
        return;

    int index = partition(a, low, up);
    quick_sort(a, low, index-1);
    quick_sort(a, index+1, up);
}

int partition(int a[], int low, int up)
{
    int temp;
    int i = low+1, j = up;
    int pivot = a[low];

    while(i <= j)
    {
        while((a[i] < pivot) && (i < up))
            i++;
        while(a[j] > pivot)
            j--;
        if(i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
        else
            i++;
    }
    a[low] = a[j];
    a[j] = pivot;
    return j;
}

void insertion_sort(int a[], int n)
{
    int i, j, temp;
    for(i = 1; i < n; i++)
    {
        temp = a[i];
        for(j = i-1; j>=0 && temp < a[j]; j--)
            a[j+1] = a[j];
        a[j+1] = temp;
    }
}