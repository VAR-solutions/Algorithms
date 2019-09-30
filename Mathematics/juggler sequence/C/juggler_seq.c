// C implementation of Juggler Sequence 
#include<stdio.h> 
#include<math.h> 

// This function prints the juggler Sequence 
void printJuggler(int n) 
{ 
	int a = n; 

	// print the first term 
	printf("%d ", a); 

	// calculate terms until last term is not 1 
	while (a != 1) 
	{ 
		int b = 0; 

		// Check if previous term is even or odd 
		if (a%2 == 0) 

			// calculate next term 
			b = floor(sqrt(a)); 

		else

			// for odd previous term calculate 
			// next term 
			b = floor(sqrt(a)*sqrt(a)*sqrt(a)); 

		printf("%d ", b); 
		a = b; 
	} 
} 

//driver program to test above function 
int main() 
{  
    int n;
    printf("Enter any Integer\n");
    scanf("%d",&n);
	printJuggler(n); 
	return 0; 
} 
