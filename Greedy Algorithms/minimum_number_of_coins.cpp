#include <bits/stdc++.h>
 using namespace std;
 int deno[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000}; //user defined denominations
int n = sizeof(deno)/sizeof(deno[0]);
 void minChange(int m)
{
     vector<int> v;
     for (int i=n-1; i>=0; i--)
    {
         while (m>=deno[i])
        {
           m-=deno[i];
           v.push_back(deno[i]);
        }
    }
     for (int i = 0; i < v.size(); i++)
           cout << v[i] << "  ";
}
 int main()
{
   int n;
   cout<<"Enter a value n for which you want minimal number of change: "<<'\n';
   cin>>n;
   cout << "Minimal number of change for " << n << " is ";
   minChange(n);
   return 0;
}
