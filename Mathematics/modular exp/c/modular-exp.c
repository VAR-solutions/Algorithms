#include <stdio.h>

int power(int x, unsigned int y, int p) { 
    int res = 1;
    x = x % p;  
  
    while (y > 0) {  
        if (y & 1) 
            res = (res*x) % p; 
        y = y>>1; // y = y/2 
        x = (x*x) % p;   
    } 
    return res; 
}
int main() {  
   printf("%u", power(2, 32, 1024)); 
   return 0; 
} 
