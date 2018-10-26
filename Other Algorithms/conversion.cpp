#include<iostream>
#include<string>
using namespace std;
int main()
{int n;
string c;
long octal(int);
long binary(int);
string hexa(int);
cout<<"Enter the no. to convert :";
cin>>n;


cout<<"Binary Equivalent :"<<binary(n);
cout<<"\nOctal equvalent :"<<octal(n);
cout<<"\nHexa decimal Equivanent :"<< hexa(n);
}
long binary(int n)
      {int r,i=1,num=0;
        while(n)
        {
		r=n%2;
		n=n/2;
		num=num+r*i;
		i=i*10;
		
		}
		return num;
		}
long octal(int n)
      {int r,i=1,num=0;
        while(n)
        {
		r=n%8;
		n=n/8;
		num=num+r*i;
		i=i*10;
		
		}
		return num;
		}
string hexa(int n)
      {int r,i=0;
         char str[100];
        string str2;
		while(n)
        {
		r=n%16;
		n=n/16;
		if(r<10)
		str[i++]=r+48;
		else
		str[i++]= 55+r;
		}
		int j;
        for(j=i-1;j>=0;j--)
        { str2=str2+str[j];
        }
	     return str2;
		}
