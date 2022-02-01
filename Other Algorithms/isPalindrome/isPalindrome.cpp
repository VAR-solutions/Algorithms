#include<bits/stdc++.h>

using namespace std;

bool isPalindrome(string g) {
    string  h = g;

    reverse(h.begin(),h.end());

    return h==g;

}


int main () {

    cout<<"Please give the string to be checked: ";
    string s;
    cin>>s;

    cout<<isPalindrome(s);


return 0;
}