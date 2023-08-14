package main
	
import "fmt"

func factorial(number int) int {
	if(number < 2){
		return 1
	}
	return number*factorial(number-1)
}

	
func main() {
    fmt.Println(factorial(5))
}