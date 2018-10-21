package main

import (
	"fmt"
)

func main() {
	for i := 0; i < 10; i++ {
		if i&1 == 1 {
			fmt.Println(i, "is odd")
		} else {
			fmt.Println(i, "is even")
		}
	}
}
