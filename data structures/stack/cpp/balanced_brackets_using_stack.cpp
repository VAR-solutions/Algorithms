//Kumar Ankit
//Balancing the brackets
//Example Test Cases:
/*
3
{[()]}
{[(])}
{{[[(())]]}}
output:
YES
NO
YES
*/
#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        stack<char> st;
        char x;
        bool ch = true;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
                continue;
            }
            if(st.empty()){
                ch = false;
                break;
            }
            x = st.top();
            st.pop();
            if(s[i]==')'){
                if(x=='{' || x=='['){
                    ch = false;
                    break;
                }
            }else if(s[i]=='}'){
                if(x=='(' || x=='['){
                    ch = false;
                    break;
                }
            }else{
                if(x=='(' || x=='{'){
                    ch = false;
                    break;
                }
            }
        }
        if(ch==true){
            if(st.empty()){
                cout<<"YES\n";
            }else{
                cout<<"NO\n";
            }
        }else{
            cout<<"NO\n";
        }
    }
    return 0;
}
