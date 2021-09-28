#include<stdio.h>
//mergesort function
void mergesort(int arr[],int left,int right)
{
    int mid;
    if(left<right)
    {
        mid=(left+right)/2;
        mergesort(arr,left,mid);
        mergesort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}
//merge function
void merge(int arr[],int left,int mid,int right)
{
    int i=left,j=mid+1,k=0,temp_arr[right-left+1];
    while(i<=mid && j<=right)
    {
        if(arr[i]<=arr[j])
           {
               temp_arr[k]=arr[i];
               k++;
               i++;
           }
           else if(arr[j]<arr[i])
           {
               temp_arr[k]=arr[j];
               k++;j++;
           }
    }
    while(i<=mid)
    {
        temp_arr[k]=arr[i];
        i++;k++;
    }
    while(j<=right)
    {
        temp_arr[k]=arr[j];
        j++;k++;
    }
    for(i=0;i<=(right-left);i++)
        arr[left+i]=temp_arr[i];
}
int main()
{
    int arr[100],i,n;
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    printf("Start entering the elements\n");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    mergesort(arr,0,n-1);
    printf("Sorted array is :\n");
    for(i=0;i<n;i++)
        printf("%d\n",arr[i]);
    return 0;
}
