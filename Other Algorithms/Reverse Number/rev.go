package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println("Hello, playground")
	num := -123

	fmt.Println(num)
	fmt.Println(reverseNumber(num))

	num2 := 123

	fmt.Println(num2)
	fmt.Println(reverseNumber(num2))
}

func reverseNumber(n int) int {
	if n == 0 {
		return 0
	}

	negNum := false

	if n < 0 {
		n = n * -1
		negNum = true
	}

	lengthOfN := (int)(math.Log10(float64(n)) + 1)
	newN := 0
	for i := lengthOfN; i > 0; i-- {
		digit := n % 10
		n = n / 10
		for j := 1; j < i; j++ {
			digit *= 10
		}
		newN += digit
	}

	if negNum == true {
		newN *= -1
	}
	return newN
}
