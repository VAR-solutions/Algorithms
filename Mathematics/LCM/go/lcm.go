package main

import(
	"fmt"
)

func gcd (a int, b int) int {
	if (b > a){
		return gcd(b,a)
	}
	if (b == 0){
		return a
	}
	return gcd(b,a%b)
}
func lcm(a int, b int) int {
	var p int = a*b

	return p / gcd(a,b)
}

func main(){
	var x,y int

	fmt.Println("The Point of this program is to compute",
		"LCM.\nPlease enter two numbers space seperated.")

	_,err := fmt.Scanf("%d %d",&x, &y)
	if ( (err != nil) || (x|y == 0)){
		fmt.Println("Invalid input")
	}
	fmt.Printf("LCM of %d,%d is %d\n",x,y,lcm(x,y))
}
