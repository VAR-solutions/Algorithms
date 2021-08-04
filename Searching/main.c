#include<stdio.h>
void main()
{
    int n,i;
    printf("Enter size of array\n");
    scanf("%d",&n);
    printf("Enter sorted array\n");
    int a[n],x;
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        printf("Enter element to be searched\n");
        scanf("%d",&x);
    int l,mid,h;
    l=0;
    h=n-1;
    mid=(l+h)/2;
    while(l<=h)
    {
        if(x>a[mid])
            l=mid;
        if(x<a[mid])
            h=mid;
        if(a[mid]==x)
        {
            printf("Element found at index position- %d",mid);
            break;
        }
        mid=(l+h)/2;
    }
    if(l>h)
        printf("Item not found");
}
