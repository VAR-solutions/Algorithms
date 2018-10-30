package main

import (
	"fmt"
)

func gcd(a int, b int) int{
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func main()  {
	a := 0
	b := 0
	fmt.Println("Find GCD")
	fmt.Println("Enter a")
	fmt.Scanln(&a)
	fmt.Println("Enter b")
	fmt.Scanln(&b)

	result := gcd(a, b)
	fmt.Printf("GCD of %v and %v is %v", a, b, result)
}