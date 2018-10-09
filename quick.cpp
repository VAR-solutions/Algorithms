#include <stdio.h>
#include <stdlib.h>
 
void swap(int *x,int *y);
int choose_pivot(int i,int j );
void quicksort(int list[],int m,int n);
void display(int list[],const int n);
 
void main()
{
    const int SIZE = 10;
    int list[SIZE];
 
    int i = 0;
 
    /* generates random numbers and fill the list */
    for(i = 0; i < SIZE; i++ )
        list[i] = rand();
 
    printf("The list before sorting is:\n");
    display(list,SIZE);
 
    /* sort the list using quicksort algorithm */
    quicksort(list,0,SIZE-1);
 
    printf("The list after sorting:\n");
    display(list,SIZE);
}
 
void swap(int *x,int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
 
int choose_pivot(int i,int j )
{
    return((i+j) /2);
}
 
void quicksort(int list[],int m,int n)
{
    int key,i,j,k;
    if( m < n)
    {
        k = choose_pivot(m,n);
        swap(&list[m],&list[k]);
        key = list[m];
        i = m+1;
        j = n;
        while(i <= j)
        {
            while((i <= n) && (list[i] <= key))
                i++;
            while((j >= m) && (list[j] > key))
                j--;
            if( i < j)
                swap(&list[i],&list[j]);
        }
        /* swap two elements */
        swap(&list[m],&list[j]);
 
        /* recursively sort the lesser list */
        quicksort(list,m,j-1);
        quicksort(list,j+1,n);
    }
}
void display(int list[],const int n)
{
    int i;
    for(i=0; i<n; i++)
        printf("%d\t",list[i]);
}

