#include <stdio.h>
/*
    Kadane's algorithm finds the maximum subarray(contigious subsequence) sum.

    let f(i) be the maximum sum of any non-empty subarray ending at i.

    f(i) = {
                max(arr[i], f[i-1] + arr[i])    otherwise
                arr[0]                            when i = 0
            }
    
*/
int max(int a,int b){
//returns the maximum of two
    return a>b?a:b;
}

//kadane's algorithm
//Time Complexity  = O(n)
//Space Complexity = O(n)
int max_subarray_sum(int arr[], int size){
    int f[size];
    int maximum_sum;

    f[0] = arr[0];
    maximum_sum = arr[0];
    for(int i=1; i< size; i++){
        f[i] = max(arr[i], f[i-1]+ arr[i]);
        //keep track of maximum sum ending at ith position found so far.
        maximum_sum = max(f[i],maximum_sum);
    }
    return maximum_sum;
}

//Time Complexity  = O(n)
//Space Complexity = O(1)
//Space Complexity can be reduced by thinking that we really don't need to store all the values of f[i]
//we need to track arr[i] and f[i-1] only  
int max_subarray_sum2(int arr[], int size){
    int sum;
    int maximum_sum;

    sum = arr[0];
    maximum_sum = arr[0];

    for(int i=1; i< size; i++){
        sum = max(arr[i],sum + arr[i]);
        maximum_sum = max(sum, maximum_sum);
    }
    return maximum_sum;
}
int main(){
    int arr[10000];
    int size;
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&size);
        for(int i=0;i < size; i++)
            scanf("%d",&arr[i]);
        printf("%d\n",max_subarray_sum2(arr,size));    
//      printf("%d\n",max_subarray_sum(arr,size));    

    }
}