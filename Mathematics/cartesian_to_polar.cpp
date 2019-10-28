#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

#define PI 3.14159265

const ld to_degrees = 180.0/PI;

struct pcord{
    ld r, theta;

    void to_pcord(ld x, ld y){
        r = sqrt(x*x+y*y);
        if(x==0){
            if(y>0) theta = PI/2;
            else theta = -PI/2;
        }
        theta = atan(abs(y/x));
        if(x>0){
            if(y>0) ;
            else    theta = -theta;
        }
        else{
            if(y>0) theta = PI - theta;
            else theta = -(PI - theta);
        }   
    }
};

int main(){
	ll q;
	cin>>q;
	while(q--){
		ll x,y;
		cin>>x>>y;
		pcord A;
		A.to_pcord(x,y);
		cout<<A.r<<" "<<A.theta<<endl;
	}    
    return 0;
}
