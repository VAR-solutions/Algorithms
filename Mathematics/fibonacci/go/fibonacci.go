package main

import(
	"fmt"
)

func fib(x int) int {
	//Thus function finds the xth number of the fibonacci sequence
	if x < 3 {
		return 1
	}
	return fib(x-1)+fib(x-2)
}

func main(){
	var input int
	fmt.Println("The Point of this program is to compute fibonacci. Please enter a number")
	_,err := fmt.Scanf("%d",&input)
	if err != nil {
		fmt.Println("Invalid input")
	}
	fmt.Printf("The fibbonacci at %d is %d\n",input,fib(input))
}
