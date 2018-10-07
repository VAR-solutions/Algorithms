#include<stdio.h>

void mergeSort(int a[10], int beg, int mid, int end)
{
  int i = beg, j = mid + 1, index = beg, temp[10], k;
  while((i <= mid)&&(j <= end))
  {
    if(a[i]<a[j])
    {
      temp[index] = a[i];
      i++;
    }
    else
    {
      temp[index] = a[j];
      j++;
    }
    index++;
  }
  if(i > mid)
  {
    while(j<=end)
    {
      temp[index] = a[j];
      index++;
      j++;
    }
  }
  else if(j > end)
  {
    while(i <= mid)
    {
      temp[index] = a[i];
      index++;
      i++;
    }
  }
  for(k=beg;k<=end;k++)
  {
    a[k]=temp[k];
  }
}

void sort(int a[10], int beg, int end)
{
  int mid;
  if(beg < end)
  {
    mid = (beg + end) / 2;
    sort(a, 0, mid);
    sort(a, mid + 1, end);
    mergeSort(a, 0, mid, end);
  }
}

void main()
{
  int tape_length, lengths[10], n, sum = 0, i, j;
  float mrt;
  printf("Enter the Max Storage on the tape: ");
  scanf("%d", &tape_length);
  printf("Enter the no. of programs: ");
  scanf("%d", %n);
  printf("Enter the lengths of programs: ");
  for(i=0;i<n;i++)
  {
    scanf("%d", &lengths[i]);
    sum += lengths[i];
  }
  if(sum>tape_length)
    printf("Tape Length too small. Cannot Store all programs.\n");
  else
  {
    merge(lengths, 0, n-1);
    for(i=0;i<n;i++)
    {
      for(j=0;j<i;j++)
      {
        mrt+=lengths[j];
      }
    }
    /*for(i=n;i>0;i--)
    {
      mrt += sum[j] - lengths[j];
      sum[j] -= lengths[j];
    }*/
    mrt = mrt / n;
    printf("The Minimum Mean Retrieval Time is %f", mrt);
  }
}
