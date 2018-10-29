#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void countingSort(int* arr, int highest, int num){
  int* Count = (int*)malloc(highest*sizeof(int));
  int* Sorted = (int*)malloc(num*sizeof(int));
  for(int i=0;i<highest+1;i++)
    Count[i]=0;
  for(int i=0;i<num;i++){
    Count[arr[i]]++;
  }
  int j=0;
  for(int i=0;i<=highest;i++){
    int temp = Count[i];
    while(temp--){
      Sorted[j]=i;
      j++;
    }
  }
  printf("The sorted array is : \n");
  for(int i=0;i<num;i++)
  printf("%d ",Sorted[i]);
}
int main(void) {
  int* arr;
  printf("Enter the number of elements : ");
  int n,k=0;
  scanf("%d",&n);
  arr = (int*)malloc(n*sizeof(int));
  printf("Enter the elements : ");
  for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
    if(arr[i]>k)
      k = arr[i];
  }
  countingSort(arr,k,n);
  return 0;
}
