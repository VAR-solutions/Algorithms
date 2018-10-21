package main

import (
	"fmt"
)

func gcd(a int, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func lcm(a int, b int) int {
	return (a * b) / gcd(a, b)
}

func main()  {
	a := 0
	b := 0
	fmt.Println("Find LCM")
	fmt.Println("Enter a")
	fmt.Scanln(&a)
	fmt.Println("Enter b")
	fmt.Scanln(&b)

	result := lcm(a, b)
	fmt.Printf("LCM of %v and %v is %v", a, b, result)
}