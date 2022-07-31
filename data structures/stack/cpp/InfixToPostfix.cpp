#include<iostream>
using namespace std;
//#include<stdlib>
#include <cstring>

int opstk[100],top=-1; char symb,tsymb;
void push(char);
int pop(void);
int pred(char);

int pop()
{
    return (opstk[top--]);
}

   void push(char x)
   {
  	top++;
   	opstk[top]=x;
   }
   int pred(char c)
   {
       if(c == '*' || c == '/')
       return 2;
       else if(c == '+' || c == '-')
       return 1;
       else
       return 0;
   }

   int main()
   {
     string ex, ps;
     int c=0,q=0;
     cout<<"Enter an expression";
     cin>>ex;
     while(ex[c] != '\0')
     {
       symb=ex[c];
       if((symb>='0'&&symb<='9')||(symb>='a'&&symb<='z')||(symb>='A'&&symb<='Z'))
       ps+=symb;
       else
       {
         while (opstk!=NULL&& (pred(opstk[top])>pred(symb)))
         {
           tsymb=pop();
           ps+=tsymb;
         }
         push(symb);
       }
       c++;
     }
     while(top!=-1)
     {
       tsymb=pop();
       ps+=tsymb;
     }
     cout<<"\nPostfix="<<ps;
     return 0;
   }
