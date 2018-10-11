package main
 
import(
	"fmt"
)

var memo [] int64 //memoization array
 
func fib(n int) int64 {
	var f int64
	if memo[n-1] != 0 {
		return memo[n-1]
	} else if n <= 2 {
		f = 1
	} else {
		f = fib(n-1) + fib(n-2)
		memo[n-1] = f
	}
	return f
} 

func main() {
	n := 10
	memo = make([] int64, n)
	fmt.Println(fib(n))
}

