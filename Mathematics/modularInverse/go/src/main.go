package main

import (
	"errors"
	"fmt"
)

func egcd(a int, b int) (int, int, int) {
	if a == 0 {
		return b, 0, 1
	} else {
		g, y, x := egcd(b%a, a)
		r := x - (b/a)*y
		return g, r, y
	}
}

func modInv(a int, m int) (int, error) {
	g, x, _ := egcd(a, m)
	if g != 1 {
		return 0, errors.New("modular inverse does not exist")
	} else {
		return x % m, nil
	}
}

func main() {
	a := 0
	m := 0
	fmt.Println("Find Modular Inverse")
	fmt.Println("Enter a")
	fmt.Scanln(&a)
	fmt.Println("Enter m")
	fmt.Scanln(&m)

	result, err := modInv(a, m)
	if err != nil {
		fmt.Printf("Modular of %v with modular %v does not exist", a, m)
	}
	fmt.Printf("Modular of %v with modular %v is %v", a, m, result)
}
