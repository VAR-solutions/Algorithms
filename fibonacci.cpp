#include <iostream>
using namespace std;

int main()
{
    int n1 = 0, n2 = 1, nextNum = 0, n;

    cout << "Enter a positive number: ";
    cin >> n;

    cout << "Fibonacci Series: " << n1 << ", " << n2 << ", ";

    nextNum = n1 + n2;

    while(nextNum <= n)
    {
        cout << nextNum << ", ";
        n1 = n2;
        n2 = nextNum;
        nextNum = n1 + n2;
    }
    
    cout<<"\n";
    return 0;
}
