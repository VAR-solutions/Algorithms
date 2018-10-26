
#include<stdio.h> 
  
/* Count set bits */
unsigned int countSetBits(int num) 
{ 
    unsigned int count = 0; 
    while (num) 
    { 
      num &= (num-1) ; 
      count++; 
    } 
    return count; 
} 
  
/* Program to test function countSetBits */
int main() 
{ 
    /* count set bits in 9 */
    int numnum = 9; 
    printf("%d", countSetBits(numnum)); 
    getchar(); 
    return 0; 
} 
