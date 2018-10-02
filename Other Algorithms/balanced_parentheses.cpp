#include <bits/stdc++.h>

using namespace std;
bool ArePair(char opening,char closing)
{
  if(opening == '(' && closing == ')') return true;
  else if(opening == '{' && closing == '}') return true;
  else if(opening == '[' && closing == ']') return true;
  return false;
}
bool AreParenthesesBalanced(string exp)
{
  stack<char>  S;
  for(int i =0;i<exp.length();i++)
  {
    if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
      S.push(exp[i]);
    else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
    {
      if(S.empty() || !ArePair(S.top(),exp[i]))
        return false;
      else
        S.pop();
    }
  }
  return S.empty() ? true:false;                                           // if this returns true then it means that all the parantheses are matched properly and in order //
}

 int main()
{
  /*Code to test the function AreParenthesesBalanced*/
  int t;
  cin>>t;
  for(int t_itr=0;t_itr<t;t_itr++)
  {
  string expression;
  cout<<"Enter an expression:  "; 
  cin>>expression;
  if(AreParenthesesBalanced(expression))
    cout<<"YES\n";
  else
    cout<<"NO\n";
  }
  
  return 0;
}

// To test the program comment out the above main function and uncomment the following main function//

	/*int main()
	{
		if(AreParenthesesBalanced("[{()}]"))
		{
			cout<<"YES";
		}
		else
		{
			cout<<"NO";
		}
		
		return 0;
	}*/

