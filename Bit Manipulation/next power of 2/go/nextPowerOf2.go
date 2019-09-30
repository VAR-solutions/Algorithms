package main

import(
	"fmt"
)

func next2pow(n int) int {
	var p int = 1

	if( n > 0 && (n & (n-1)) == 0){
		return n
	}

	for (p < n) {
		p <<= 1
	}

	return p
}

func main(){
	var input int

	fmt.Println("The Point of this program is to compute\nSmallest power of two ",
		"greater than or eqaul to the number entered.\nPlease enter a number")

	_,err := fmt.Scanf("%d",&input)
	if err != nil {
		fmt.Println("Invalid input")
	}
	fmt.Printf("Smallest Power of 2 greater than or equal to %d is %d\n",input,next2pow(input))
}
