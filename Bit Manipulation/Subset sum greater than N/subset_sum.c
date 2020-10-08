#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int subsetsum(int *set,int set_size,int value)
{
    int count=0,x,k;
    for(x=0;x<pow(2,set_size);x++)
    {
        int sum=0;
        for(k=0;k<set_size;k++)
        {
            if( (x&(1<<k))!=0)
              sum+=set[k];
        }
        if(sum>=value)
            count++;
    }
    return count;

}

int main()
{
    int arr[]={1,2,3};
    int n=5;
    int answer=subsetsum(&arr,3,n);
    printf("%d",answer);
    return 0;
}
