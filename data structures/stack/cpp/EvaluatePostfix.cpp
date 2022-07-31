#include<iostream>
using namespace std;
#include <string>
char stack[100];
int top = -1;
void push(char x)
{
 top++;
 stack[top]=x;
}

int pop()
{
return stack[top--];
}

int evaluate(string ex)
{
    int i = 0,value,opnd2,opnd1;
    char symb;
    while(ex[i]!='\0')
    {
        symb = ex[i];
        if(symb >= '0' && symb <= '9')
            push(symb);
        else
        {
            opnd2 = (int)pop()-48;
            opnd1 = (int)pop()-48;
            switch(symb)
            {
                case '+':
                    value = opnd1 +opnd2;
                    break;
                case '-':
                    value = opnd1 -opnd2;
                    break;
                case '*':
                    value =opnd1 * opnd2;
                    break;
                case '/':
                    value =opnd1 / opnd2;
                    break;
            }
            char pushval = (value+48);
            push(pushval);
        }
        i++;
    }
    return(pop());
}

int main()
{
    string exp;
    int value;
    cout<<"Enter the Postfix expression : ";
    cin>>exp;
    value = (int)evaluate(exp)-48;
    cout<<"value= "<<value<<endl;
    return 0;
}
