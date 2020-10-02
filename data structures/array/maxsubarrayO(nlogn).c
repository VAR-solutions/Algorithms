#include<stdio.h>
#include<malloc.h>
typedef struct result
{
    int left_end,right_end,max_sum;
}result;
result maxsubarr_cross(int arr[],int l,int m,int r)
{
  result cross_res;
  int i,j,curr_sum=0,left_sum,right_sum,left_max,right_max;
  left_sum=-32767;
  right_sum=-32767;
  for(i=m;i>=l;i--)
  {
      curr_sum+=arr[i];
      if(curr_sum>left_sum)
        {
            left_max=i;
            left_sum=curr_sum;
        }
  }
  curr_sum=0;
  for(i=m+1;i<=r;i++)
  {
      curr_sum+=arr[i];
      if(curr_sum>right_sum)
        {
            right_max=i;
            right_sum=curr_sum;
        }
  }
  cross_res.left_end=left_max;
  cross_res.right_end=right_max;
  cross_res.max_sum=left_sum+right_sum;
  return cross_res;
}
result maxsubarr(int arr[],int l,int r)
{
    result res,r_left,r_right,r_mid;
    int i,j,mid;
    if(l==r)
    {
        res.left_end=l;
        res.right_end=l;
        res.max_sum=arr[l];
        return res;
    }
    else
    {
        mid=(l+r)/2;
        r_left=maxsubarr(arr,l,mid);
        r_right=maxsubarr(arr,mid+1,r);
        r_mid=maxsubarr_cross(arr,l,mid,r);
        if(r_left.max_sum>=r_right.max_sum && r_left.max_sum>=r_mid.max_sum)
            return r_left;
        else if(r_right.max_sum>=r_left.max_sum &&  r_right.max_sum>=r_mid.max_sum)
            return r_right;
        else return r_mid;

    }
}
int main()
{
    int n,*arr,i;
    result r;
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    arr=(int *)malloc(sizeof(int)*n);
    printf("Start entering the elements of array\n");
    for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
    printf("Elements of the array are:\n");
    for(i=0;i<n;i++)
    printf("%d\t",arr[i]);
    printf("\n\n");
    r=maxsubarr(arr,0,n-1);
    printf("Sub array with maximum is from %d to %d\n",r.left_end,r.right_end);
    printf("Maximum sum is %d\n",r.max_sum);
    return 0;
}
