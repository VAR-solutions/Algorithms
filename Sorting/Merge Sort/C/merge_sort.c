#include<stdio.h>
void merge(int arr1[],int ll1,int ul1,int ll2,int ul2)
{
    int i=0,k,ll=ll1;
    int arr3[100];
    while(ll1<=ul1&&ll2<=ul2)
    {
        if(arr1[ll1]<arr1[ll2])
            arr3[i++]=arr1[ll1++];
        else
            arr3[i++]=arr1[ll2++];
    }
    while(ll1<=ul1)
        arr3[i++]=arr1[ll1++];
    while(ll2<=ul2)
        arr3[i++]=arr1[ll2++];
    for(k=0;k<i;k++)
        arr1[ll++]=arr3[k];
}
void merge_sort(int arr1[],int ll,int ul)
{
    int mid;
      if(ll<ul)
   {
          mid=(ul+ll)/2;
        merge_sort(arr1,ll,mid);
        merge_sort(arr1,mid+1,ul);
        merge(arr1,ll,mid,mid+1,ul);
   }
}
void main()
{
    int arr1[100];
    int n,i;
    printf("\nEnter the no. of elements present in the array :");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\narr[%d]=",i);
        scanf("%d",&arr1[i]);
    }
    merge_sort(arr1,0,n-1);
    printf("\nThe sorted array is...");
    for(i=0;i<n;i++)
    {
        printf("\narr[%d]=%d",i,arr1[i]);
    }
}