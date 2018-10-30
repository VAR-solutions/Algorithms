#include <iostream>
#include <vector>
using namespace std;

vector< int > phi;
void computer_euler_totient_sieve(int n)
{
    phi.resize(n+1);
    for(int i=1; i<=n; i++)
    {
        phi[i] = i;
    }

    for(int i=2; i<=n; i++)
    {
        if(phi[i] == i)
        {
            for(int j=i; j<=n; j+=i)
            {
                phi[j] = (phi[j] - phi[j]/i);
            }
        }
    }
}

int main()
{
    int n;
    cin>>n;
    computer_euler_totient_sieve(n);
    cout<<phi[n];
}