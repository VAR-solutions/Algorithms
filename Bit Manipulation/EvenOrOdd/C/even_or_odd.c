#include <stdio.h>

void main(void){
	
	//quick test to see if number is even or odd
	//lsb toggles every time you increment a number
	//0 - 0000 - even
	//1 - 0001 - odd
	//2 - 0010 - even
	//3 - 0011 - odd
	//4 - 0100 - even 
	//5 - 0101 - odd
	//etc
	//pretty dope
	for(int evenodd = 0; evenodd <= 10; evenodd++){
		if(evenodd & 0x1){
			printf("%i is odd\n", evenodd);
		}else{
			printf("%i is even\n", evenodd);
		}
	}
	
}
