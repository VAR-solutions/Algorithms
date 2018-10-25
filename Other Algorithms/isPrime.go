package main

import (
	"fmt"
)

func main() {
	status := isPrime(42)
	fmt.Println(status)
}

func isPrime(value int) bool {
	for i := 2; i <= value; i++ {
		if value%i == 0 && i != value {
			return false
		}
	}
	return true
}
