#include <iostream>
#include <cstring>
using namespace std;

long long to_number(string s)
{
    long long num = 0;
    for(int i=s.length()-1,j=0; i<s.length(); i--, j++)
    {
        if(s[i]=='1')
        {
            num += (1<<j);
        }
    }
    return num;
}

string to_bitset(int num)
{
    string bit_string;
    while(num)
    {
        if(num&1) bit_string+="1";
        else bit_string+="0";
        num>>=1;
    }
    bit_string+="0";
    for(int i=0; i<bit_string.length()/2; i++)
    {
        swap(bit_string[i], bit_string[bit_string.length()-i-1]);
    }
    return bit_string;
}

int main()
{
    int n;
    cin>>n;
    string temp = to_bitset(n);
    cout<<temp<<"\n";
    cout<< to_number(temp);
}