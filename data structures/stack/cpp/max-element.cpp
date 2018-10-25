#include<bits/stdc++>
using namespace std;
int main()
{
    stack<long int>s1,s2;
    s2.push(-1);
    int n,i,q,x;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>q;
        if(q==1)
        {
            cin>>x;
            	s1.push(x);
            if(x>=s2.top())
                s2.push(x);
        }
        else if(q==2)
        {
        	if(s1.top()==s2.top())
        		s2.pop();
            s1.pop();

        }
        else if(q==3){
            //int m=max(s1);

            cout<<s2.top()<<endl;
        }
    }
    return 0;
}
