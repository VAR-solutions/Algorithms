#include<bits/stdc++.h>
using namespace std;

vector<bool> isprime;
vector<int> allprimes;
vector<int> p_factors;

void sieve(int n)
{
    isprime.resize(n+1,true);
    isprime[1]=isprime[0]=false;
    for(int p=2;p*p<=n;p++)
    {
        if(isprime[p]==true)
          for(int i=p*2;i<=n;i+=p)
               isprime[i]=false;
    }
    for(int i=2;i<n+1;i++)
       if(isprime[i])
          allprimes.push_back(i);
}

void primefactors(int n)
{
  p_factors.clear();
  int idx=0;
  int pf=allprimes[idx];
  while(pf*pf<=n)
  {
     while(n%pf==0)
     {
       n/=pf;
       p_factors.push_back(pf);
     }
     pf=allprimes[++idx];
  }
  if(n!=1) p_factors.push_back(n);
}

int main()
{
  int n;
  cout<<"Enter the number\n";
  cin>>n;
  if(n==1)
  {
    cout<<"No prime factors\n";
    return 0;
  }
  sieve(n);
  primefactors(n);
  cout<<"The Prime factors are:\n";
  for(int i=0;i<p_factors.size();i++) cout<<p_factors[i]<<" ";
  cout<<endl;
}
