#include<iostream>
using namespace std;
#include<stack>


bool validexp(string s){

	stack<char> stk;

	for(int i=0; i<s.size(); i++){
		
		char ch = s[i];
		if(ch == '(' || ch=='{' || ch=='['){
			stk.push(ch);
		}
		else if(ch == ')'){
			if(stk.empty() || stk.top()!= '('){
				return false;
			}
			stk.pop();
		}
		else if(ch == '}'){
			if(stk.empty() || stk.top()!= '{'){
				return false;
			}
			stk.pop();
		}
		else if(ch == ']'){
			if(stk.empty() || stk.top()!= '['){
				return false;
			}
			stk.pop();
		}
	}
	return stk.empty();
}

int main(){

	string ch;
	cin>>ch;

	if(validexp(ch))
		cout<<"Yes";
	else 
		cout<<"No";

return 0;
}

