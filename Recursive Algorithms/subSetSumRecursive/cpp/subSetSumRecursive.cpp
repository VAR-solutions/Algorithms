#include <iostream>
using namespace std;

bool isSubSet(int set[], int sum, int n)
{

    if (sum == 0)
        return true;

    if (n == 0 && sum != 0)
        return false;
    if (sum < set[n - 1])
        return isSubSet(set, sum, n - 1);

    return isSubSet(set, sum, n - 1) || isSubSet(set, sum - set[n - 1], n - 1);
}

int main(int argc, char const *argv[])
{
    //int set[] = {3, 34, 4, 12, 5, 2};
    int size;
    //size of set
    cin >> size;
    int set[size];

    for (size_t i = 0; i < size; i++)
        cin >> set[i];

    int sum;
    cin >> sum;

    if (isSubSet(set, sum, size) == true)
        printf("Found a subset with given sum");
    else
        printf("No subset with given sum");
    return 0;
}
