package main
import "fmt"

// Binary Search
func binarySearch(item int, items []int) bool {
    
    low := 0
    high := len(items) - 1
 
    for low <= {
        median := (low + high) / 2
 
        if items[median] < item {
            low = median + 1
        } else{
            high = median - 1
        }
    }
 
    if low == len(items) || items[low] != item {
        return false
    }
 
    return true
}
 
// Main
func main(){
    items := []int{1,2, 9, 20, 31, 45, 63, 70, 100}
    flag := binarySearch(63, items)
    if flag {
      fmt.Println("\nFound!\n")
    } else {
      fmt.Println("\nNot Found!\n")
    }
}
