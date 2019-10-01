
#include <iostream>
using namespace std;

int digitalRoot(int n)
{
    //Your code here
    if(n < 10)
     return n;
    
    int sum= digitalRoot(n/10) + n % 10;
    
    return digitalRoot(sum);

}


int main() {
	int T;
	cin>>T;
	while(T--)
	{
	    int n;
	    cin>>n;
	    
	    cout<<digitalRoot(n)<<endl;
	    
	    
	}
	return 0;
}
