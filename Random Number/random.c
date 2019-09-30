// C program to generate random numbers 
#include <stdio.h> 
#include <stdlib.h> 
  
// Driver program and testing
int main(void) 
{ 
    // This program will create same sequence of  
    // random numbers on every program run  
  
    for(int i = 0; i<5; i++) 
        printf(" %d ", rand()); 
    return 0; 
} 
