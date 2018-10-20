package main

import(
	"fmt"
)

func countSetBits(n int) int {
	var p int = 0

	for (n > 0) {

		if (n % 2 == 1){
			p++
		}

		n >>= 1

	}

	return p
}

func main(){
	var input int

	fmt.Println("The Point of this program is to compute\nNumber of set",
		"bits in the number entered.\nPlease enter a number")

	_,err := fmt.Scanf("%d",&input)
	if err != nil {
		fmt.Println("Invalid input")
	}
	fmt.Printf("Number of Set bits in %d is %d\n",input,countSetBits(input))
}
