#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

void evenOdd(int num)
{
    if(num%2==0)
        printf("The number is even!");
    else
        printf("The number is odd!");
}


int checkInd(int ind)
{
    if(++ind==SIZE)
        return 0;
    else
        return ind;
}

int lsearch(float data[],int size, float key)
{
    int found = 0;
    int position = -1;
    int index = 0;
    while(index<size)
    {
        if(data[index]==key)
        {
            found = 1;
            position = index;
            break;
        }
        index++;
    }
    return position;
}

int main()
{
    /*int in;
    printf("Enter a number: ");
    scanf("%d", &in);
    evenOdd(in);

    int i;
    for(i=0; i<10; i++)
        printf("%d\n", checkInd(i));*/

    float arr[] = {10,50,14,85,24,58,63,45,82,12};
    float key = 99;
    int ind = lsearch(arr, 10, key);
    if(ind==-1)
        printf("The key was not found!");
    else
        printf("The key was found in index %d", ind);
    return 0;
}